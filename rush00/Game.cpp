/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 16:16:34 by arherrer          #+#    #+#             */
/*   Updated: 2019/05/05 23:23:26 by arherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

#include <string>

#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <unistd.h>

/*** Static Members ***/
const int Game::_size_x = 80;
const int Game::_size_y = 25;
const int Game::_entity_cooldown = 42;

/*** Helper Functions ***/
static void ncursesInit(void)
{
	initscr();
	cbreak();
	noecho();
	intrflush(stdscr, true);
	nodelay(stdscr, true);
	curs_set(false);
}

enum {
	color0,
	colorRed,
	colorCyan,
	colorBlack,
	colorGreen,
	colorYellow,
	colorBlue,
	colorMagenta,
	colorWhite,
	color1
};

static void colorsInit(void)
{
	start_color();
	init_pair(colorBlack, COLOR_BLACK, COLOR_BLACK);
	init_pair(colorRed, COLOR_RED, COLOR_BLACK);
	init_pair(colorGreen, COLOR_GREEN, COLOR_BLACK);
	init_pair(colorYellow, COLOR_YELLOW, COLOR_BLACK);
	init_pair(colorBlue, COLOR_BLUE, COLOR_BLACK);
	init_pair(colorMagenta, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(colorCyan, COLOR_CYAN, COLOR_BLACK);
	init_pair(colorWhite, COLOR_WHITE, COLOR_BLACK);
}

static void playersInit(Entity& player0, Entity& player1, int y, int x)
{
	player0.x = x / 4;
	player0.y = y / 2;
	player0.alive = true;
	player0.counter = 21;

	player1.x = x / 4;
	player1.y = (y / 2) + 1;
	player1.alive = true;
	player1.counter = 21;
}

/*** Coplien ***/
Game::Game(void)
{
	srand (time(NULL));
	ncursesInit();
	colorsInit();
	initBackground();
	playersInit(_player0, _player1, _size_y, _size_x);
	_time = time(0);
	_score = 0;
	_keep_count = true;
	_boss.justKilled = false;
}

Game::Game(const Game& that)
{
	*this = that;
}

Game& Game::operator =(const Game& that)
{
	_time = that._time;
	_time_last = that._time_last;
	_score = that._score;
	_kills = that._kills;
	return *this;
}

Game::~Game(void)
{
	endwin();
}

/*** Main Loop ***/
void Game::loop(void)
{
	while (true) {
		time_t start = time(0);	
		int key = getch();
		update(key);
		render();
		if (_keep_count) {
			++_score;
			_time_last = time(0);
		}
		usleep(difftime(time(0), start) + 36384);
	}
}

/*** Game Update ***/
void Game::update(int key)
{
	updateBackground();
	updatePlayers(key);
	updateBullets();
	updateShips();
	updateBoss();
	updateState();
}

void Game::updateBullets(void)
{
	for (int idx = 0; idx < MAX_BULLETS; ++idx) {
		if (_bullets[idx].alive) {  // Player bullets
			_bullets[idx].x += 1;
		}
		if (_bullets[idx].counter >= 0) {
			_bullets[idx].counter -= 1;
		}
	}
	for (int idx = 0; idx < MAX_SHIPS; idx++) {
		_enemy_bullets[idx].counter--;
		_enemy_bullets[idx].x -= 2;
		_enemy_bullets[idx].alive = _enemy_bullets[idx].counter > 0;
	}
}

void Game::makeBullets(const Entity& entity, bool alive)
{
	int cnt = 0;
	for (int idx = 0; idx < MAX_BULLETS; ++idx) {
		if (cnt == MAX_ENTITY_BULLETS) {
			break ;
		}
		if (_bullets[idx].counter <= 0) {
			_bullets[idx].counter = _entity_cooldown;
			_bullets[idx].alive = alive;
			_bullets[idx].x = entity.x + cnt + 1;
			_bullets[idx].y = entity.y;
			++cnt;
		}
	}
}

void Game::updateBoss(void)
{
	if (difftime(_time_last, _time) == 21) {
		_boss.x = (_size_x * 3) / 4;
		_boss.y = _size_y / 2;
		_boss.alive = true;
		_boss.justKilled = false;
		_boss.counter = 4200;
		_laser.alive = false;
		_laser.justKilled = false;
		_laser.counter = _entity_cooldown;
		_laser.counter1 = 0;
	}
	if (!_boss.alive) {
		return ;
	}
	
	// Update laser
	_laser.x = _boss.x;
	--_laser.counter;
	--_laser.counter1;  // Damage cooldown
	if (_laser.counter == -(_entity_cooldown * 2)) {
		_laser.counter = _entity_cooldown;
		_laser.alive = true;
	}
	if (_laser.alive && _laser.counter <= 0) {  // Longer cooldown
		_laser.counter = _entity_cooldown;
		_laser.alive = false;
		_laser.justKilled = true;
	}

	const Entity& player = (_player0.alive) ? _player0 : _player1;
	if (player.alive) {
		// Follow player
		if (_boss.y < player.y) {
			_boss.y += rand() % 2;
		}
		if (_boss.y > player.y) {
			_boss.y -= rand() % 2;
		}
		// Move forward.
		if (!_laser.alive && ((int)difftime(_time_last, _time) % 8 == 0 ||
			(int)difftime(_time_last, _time) % 9 == 0 ||
			(int)difftime(_time_last, _time) % 10 == 0)) {  // Every 8 sec
			_boss.x = (_boss.x >= 1) ? _boss.x - 1 : _boss.x;
		} else {
			_boss.x = (_size_x * 3) / 4;
		}
	}
}

void Game::updateShips(void)
{
	for (int idx = 0; idx < MAX_SHIPS; ++idx) {
		if (_ships[idx].justKilled && _ships[idx].alive) {
			_ships[idx].justKilled = false;
		}
		if (_ships[idx].alive) {
			if (_ships[idx].x <= 0) {
				_ships[idx].x = (_size_x - 1) - rand() % 2;
				_ships[idx].alive = false;
				continue ;
			}
			_ships[idx].x -= rand() % 3;
//			_ships[idx].y += (rand() % 2) * ((idx % 2) * (-1));
			_ships[idx].y = (_ships[idx].y < 0)
				? _size_y 
				: _ships[idx].y;
			_ships[idx].y = (_ships[idx].y >= _size_y)
				? _size_y
				: _ships[idx].y;
			enemyShoot(_ships[idx].x, _ships[idx].y, idx);
		} else {
			if (_ships[idx].counter <= 0) {
				_ships[idx].alive = true;
				_ships[idx].y = rand() % (_size_y + 2);
			}
			_ships[idx].counter -= 1;
		}
	}
}

void Game::updatePlayers(int key)
{
	if (_player0.alive) {
		if (key == '\t') {
			makeBullets(_player0, true);
		} else if ((key == 'w' || key == 'W') && (_player0.y > 0)) {
			_player0.y -= 1;
		} else if ((key == 'a' || key == 'A') && (_player0.x > 0)) {
			_player0.x -= 1;
		} else if ((key == 's' || key == 'S') && (_player0.y < _size_y)) {
			_player0.y += 1;
		} else if ((key == 'd' || key == 'D') && (_player0.x < _size_x)) {
			_player0.x += 1;
		}
	}
	if (_player1.alive) {
		if (key == ' ') {
			makeBullets(_player1, true);
		} else if ((key == 'k' || key == 'K') && (_player1.y > 0)) {
			_player1.y -= 1;
		} else if ((key == 'h' || key == 'H') && (_player1.x > 0)) {
			_player1.x -= 1;
		} else if ((key == 'j' || key == 'J') && (_player1.y < _size_y)) {
			_player1.y += 1;
		} else if ((key == 'l' || key == 'L') && (_player1.x < _size_x)) {
			_player1.x += 1;
		}
	}
}

static int overlap(const Entity& e1, const Entity& e2)
{
	return ((e1.alive && e2.alive) && (e1.x == e2.x) && (e1.y == e2.y));
}

void Game::updateState(void)
{
	// Stop counting when players die
	if (!_player0.alive && !_player1.alive) {
		_keep_count = false;
	}
	// Check player against ships
	// This will kill the enemy on contact as well.
	for (int idx = 0; idx < MAX_SHIPS; ++idx) {
		if (overlap(_player0, _ships[idx])) {
			_ships[idx].alive = false;
			_ships[idx].justKilled = true;
			++_kills; _score += 1000;
			_player0.counter -= 1;
		}
		if (overlap(_player1, _ships[idx])) {
			_ships[idx].alive = false;
			_enemy_bullets[idx].alive = false;
			++_kills; _score += 1000;
			_player1.counter -= 1;
		}
	}
	// Check player against boss.
	if (_player0.x == _boss.x - 1 || _player0.x == _boss.x) {
		_player0.counter -= 1;
		if (_player0.counter <= 0) {
			_player0.alive = false;
			_player0.justKilled = true;
		}
	}
	if (_player1.x == _boss.x - 1 || _player1.x == _boss.x) {
		_player1.counter -= 1;
		if (_player1.counter <= 0) {
			_player1.alive = false;
			_player1.justKilled = true;
		}
	}
	// Check player against laser
	if (_laser.alive && _laser.counter1 <= 0
		&& _player0.y == _boss.y && _player0.x <= _boss.x) {
		_player0.counter -= 2;
		if (_player0.counter <= 0) {
			_player0.alive = false;
			_player0.justKilled = true;
		}
		_laser.counter1 = _entity_cooldown;
	}
	if (_laser.alive && _laser.counter1 <= 0
		&& _player1.y == _boss.y && _player1.x <= _boss.x) {
		_player1.counter -= 2;
		if (_player1.counter <= 0) {
			_player1.alive = false;
			_player1.justKilled = true;
		}
		_laser.counter1 = _entity_cooldown;
	}

	for (int idx = 0; idx < MAX_SHIPS; idx++) {
		if (overlap(_player0, _enemy_bullets[idx])) {
			_enemy_bullets[idx].alive = false;
			_player0.counter -= 1;
		}
		if (overlap(_player1, _enemy_bullets[idx])) {
			_enemy_bullets[idx].alive = false;
			_player1.counter -= 1;
		}
	}

	if (_player0.counter <= 0) {
		_player0.alive = false;
		_player0.justKilled = true;
	}
	if (_player1.counter <= 0) {
		_player1.alive = false;
		_player1.justKilled = true;
	}
	// Check ships against projectiles
	for (int i = 0; i < MAX_BULLETS; ++i) {
		if ((_bullets[i].counter > 0) && (_bullets[i].alive)) {
			for (int j = 0; j < MAX_SHIPS; ++j) {
				if (overlap(_bullets[i], _ships[j])) {
				// Kill ship
				_ships[j].alive = false;
				_ships[j].justKilled = true;
				// Kill bullet
				_bullets[i].counter = 0;
				++_kills; _score += 1000;
				}
			}
		}
	}
	// Check boss against projectiles.
	for (int i = 0; i < MAX_BULLETS; ++i) {
		if (_boss.alive && (_bullets[i].counter > 0) && (_bullets[i].alive)) {
			const Entity& bullet = _bullets[i];
			if (bullet.x == _boss.x && bullet.y == _boss.y) {
				_boss.counter -= 10;
			}
			if (bullet.x == _boss.x &&
				(bullet.y == _boss.y - 1 || bullet.y == _boss.y + 1)) {
				_boss.counter -= 10;
			}
			if (_boss.counter <= 0) {
				_boss.alive = false;
				_boss.justKilled = true;
				_score += 1000000;
				_keep_count = false;
			}
		}
	}
}

/*** Game Render ***/
void Game::render(void) const
{
	clear();
	renderBackgroundBase();
	renderBackground();
	renderBullets();
	renderEnemyBullets();
	renderBoss();
	renderShips();
	renderPlayers();
	renderScore();
	renderTime();
	renderKills();
}

void Game::renderBackgroundBase(void) const
{
	attron(COLOR_PAIR(colorWhite));
	for (int y = 0; y < _size_y; ++y) {
		for (int x = 0; x < _size_x; ++x) {
			if ((rand() % 1024) == 42) {
				mvaddch(y, x, '.' | A_BOLD);
			}
		}
	}
	attroff(COLOR_PAIR(colorWhite));
}

void Game::renderBullets(void) const
{
	for (int idx = 0; idx < MAX_BULLETS; ++idx) {
		if ((_bullets[idx].counter >= 0) &&
			(_bullets[idx].x >= 0 && _bullets[idx].x <= _size_x) &&
			(_bullets[idx].y >= 0 && _bullets[idx].y <= _size_y)) {
			if (_bullets[idx].alive) {  // Player bullets.
				attron(COLOR_PAIR(colorYellow));
				mvaddch(_bullets[idx].y, _bullets[idx].x, '~' | A_BOLD);
				attroff(COLOR_PAIR(colorYellow));
			} 
		}
	}
}

void Game::renderBoss(void) const
{
	if (!_boss.alive) {
		return ;
	}
	attron(COLOR_PAIR(colorBlue));
	// Render main body.
	attron(A_BOLD);
	mvprintw(_boss.y - 2, _boss.x + 1, "/");
	mvprintw(_boss.y - 1, _boss.x, "/#");
	mvprintw(_boss.y, _boss.x - 1, "<#");
	mvprintw(_boss.y + 1, _boss.x, "\\#");
	mvprintw(_boss.y + 2, _boss.x + 1, "\\");
	mvprintw(_boss.y, _boss.x + 1, "===");
	attroff(A_BOLD);

	// Render back
	mvprintw(_boss.y - 2, _boss.x + 2, "-");
	mvprintw(_boss.y + 2, _boss.x + 2, "-");

	// Render fire.
	attroff(COLOR_PAIR(colorBlue));
	attron(COLOR_PAIR(colorYellow));
	if ((int)difftime(_time_last, _time) % 2) {
		attron(A_BOLD);
		mvprintw(_boss.y, _boss.x, "---");
		mvprintw(_boss.y, _boss.x + 4, "~");
		attroff(A_BOLD);
	 } else {
		mvprintw(_boss.y, _boss.x, "---");
		mvprintw(_boss.y, _boss.x + 4, "~");
	 }
	// Render its laser
	if (_laser.alive) {
		mvprintw(_boss.y, 0, std::string(_boss.x - 1, '=').c_str());
	}

	attroff(COLOR_PAIR(colorYellow));
	attron(COLOR_PAIR(colorBlue));

	// Render health;
	for (int it = 0; it < (_boss.counter / 100); ++it) {
		mvaddch(_size_y + 1, _size_x - it, '#' | A_BOLD);
	}
	attroff(COLOR_PAIR(colorBlue));
}

void Game::renderShips(void) const
{

	for (int idx = 0; idx < MAX_SHIPS; ++idx) {
		if ((_ships[idx].alive) && 
			(_ships[idx].x >= 0 && _ships[idx].x <= _size_x) &&
			(_ships[idx].y >= 0 && _ships[idx].y <= _size_y)) {
			attron(COLOR_PAIR(colorBlue));
			mvaddch(_ships[idx].y, _ships[idx].x + 1, '#' | A_BOLD);
			mvaddch(_ships[idx].y, _ships[idx].x, '<' | A_BOLD);
			attroff(COLOR_PAIR(colorBlue));
		}
		if (_ships[idx].justKilled) {
			attron(COLOR_PAIR(colorYellow));
			mvaddch(_ships[idx].y - 1, _ships[idx].x + 1, '*' | A_BOLD);
			mvprintw(_ships[idx].y, _ships[idx].x, "*#*");
			mvaddch(_ships[idx].y + 1, _ships[idx].x + 1, '*' | A_BOLD);
			attroff(COLOR_PAIR(colorYellow));
		}
	}
}

void renderPlayerHealth(const Entity& player, int y)
{
	for (int it = 0; it < player.counter; ++it) {
		mvaddch(y, it, '@' | A_BOLD);
	}
}

void Game::renderPlayers(void) const
{
	const std::string win_msg0 = "* A WINNER IS YOU *";
	const std::string win_msg1 = "===================";
	if (_boss.justKilled) {
		attron(COLOR_PAIR(colorCyan));
		mvprintw((_size_y / 2), (_size_x / 2) - 4, win_msg0.c_str());
		attroff(COLOR_PAIR(colorCyan));
		attron(COLOR_PAIR(colorRed));
		mvprintw((_size_y / 2) + 1, (_size_x / 2) - 4, win_msg1.c_str());
		attroff(COLOR_PAIR(colorRed));
		return ;
	}
	if (!_player0.alive && !_player1.alive) {
		attron(COLOR_PAIR(colorYellow));
		mvprintw((_size_y / 2), (_size_x / 2) - 5, "GAME OVER");
		mvprintw((_size_y / 2) + 1, (_size_x / 2) - 5, "=========");
		attroff(COLOR_PAIR(colorYellow));
		return ;
	}
	attron(COLOR_PAIR(colorCyan));
	if (_player0.justKilled) {
		mvaddch(_player0.y - 1, _player0.x + 1, '*' | A_BOLD);
		mvprintw(_player0.y, _player0.x, "*@*");
		mvaddch(_player0.y + 1, _player0.x + 1, '*' | A_BOLD);
	}
	if (_player0.alive) {
		mvaddch(_player0.y, _player0.x, '@' | A_BOLD);
		mvaddch(_player0.y, _player0.x + 1, '>' | A_BOLD);
		renderPlayerHealth(_player0, _size_y + 1);
	}
	attroff(COLOR_PAIR(colorCyan));

	attron(COLOR_PAIR(colorRed));
	if (_player1.justKilled) {
		mvaddch(_player1.y - 1, _player1.x + 1, '*' | A_BOLD);
		mvprintw(_player1.y, _player1.x, "*@*");
		mvaddch(_player1.y + 1, _player1.x + 1, '*' | A_BOLD);
	}
	if (_player1.alive) {
		mvaddch(_player1.y, _player1.x, '@' | A_BOLD);
		mvaddch(_player1.y, _player1.x + 1, '>' | A_BOLD);
		renderPlayerHealth(_player1, _size_y + 2);
	}
	attroff(COLOR_PAIR(colorRed));

}

void Game::renderScore(void) const
{
	attron(COLOR_PAIR(colorYellow));
	mvprintw(_size_y + 3, 0, "SCORE %llu\n", _score);
	attroff(COLOR_PAIR(colorYellow));
}

void Game::renderTime(void) const
{
	attron(COLOR_PAIR(colorYellow));
	mvprintw(_size_y + 4, 0, "TIME %.0f SECONDS\n", difftime(_time_last, _time));
	attroff(COLOR_PAIR(colorYellow));
}

void Game::renderKills(void) const
{
	attron(COLOR_PAIR(colorYellow));
	mvprintw(_size_y + 5, 0, "KILLS %llu\n", _kills);
	attroff(COLOR_PAIR(colorYellow));
}

/**
 * BACKGROUND
 */

void
Game::updateBackground(void)
{
	for (int i = 0; i < MAX_STARS; i++) {
		// Refresh if out of bounds.
		if (_bgObjects[i].x < 0) {
			_bgObjects[i].x = _size_x;
		}
		if (_bgObjects[i].x > _size_x) {
			_bgObjects[i].x = 0;
		}
		_bgObjects[i].move();
	}
}

void
Game::renderBackground(void) const
{
	Star		bgObj;

	for (int i = 0; i < MAX_STARS; i++) {
		bgObj = _bgObjects[i];
		_bgObjects[i].render();
		if (bgObj.x <= 0 || bgObj.x < _size_x) {
			bgObj.x = rand() % (_size_x);
			bgObj.y = rand() % (_size_y);
		}
	}
}

void
Game::initBackground()
{
	for (int i = 0; i < MAX_STARS; i++) {
		_bgObjects[i].x = rand() % (_size_x + 1);
		_bgObjects[i].y = rand() % (_size_y + 1);
		_bgObjects[i].setColor(3 + (rand() % 4));
	}
}

/**
 * ENEMY BULLETS
 */
void
Game::enemyShoot(int x, int y, int idx)
{
	int		shouldShoot = (rand() % 100) == 0;

	if (shouldShoot && _enemy_bullets[idx].counter <= 0) {
		_enemy_bullets[idx].alive = true;
		_enemy_bullets[idx].counter = _entity_cooldown;
		_enemy_bullets[idx].x = x - 5;
		_enemy_bullets[idx].y = y;
	}
}

void
Game::renderEnemyBullets() const
{
	for (int idx = 0; idx < MAX_SHIPS; ++idx) {
		if ((_enemy_bullets[idx].alive) && _enemy_bullets[idx].counter > 0) {
			attron(COLOR_PAIR(colorYellow));
			mvaddch(_enemy_bullets[idx].y, _enemy_bullets[idx].x, 'o' | A_BOLD);
			attroff(COLOR_PAIR(colorYellow));
		}
	}
}
