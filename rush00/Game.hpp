/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 16:15:54 by arherrer          #+#    #+#             */
/*   Updated: 2019/05/06 13:34:03 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <time.h>
#include "Entity.hpp"
#include "Star.hpp"

#define MAX_SHIPS 16
#define MAX_BULLETS 128
#define MAX_STARS 40
#define MAX_ENTITY_BULLETS 8

class Game {

public:
	// Coplien
	Game(void);
	Game(const Game& that);
	Game& operator =(const Game& that);
	~Game(void);

	void loop(void);

private:

	static const int _size_x;
	static const int _size_y;

	time_t _time;
	time_t _time_last;
	unsigned long _score;
	unsigned long _kills;
	bool _keep_count;

	Entity _player0;
	Entity _player1;

	static const int _entity_cooldown;
	Entity _ships[MAX_SHIPS];
	Entity _enemy_bullets[MAX_SHIPS];
	Entity _bullets[MAX_BULLETS];
	Star _bgObjects[MAX_STARS];

	Entity _boss;
	Entity _laser;

	void update(int key);
	void updateBullets(void);
	void makeBullets(const Entity& entity, bool alive);
	void updateBoss(void);
	void updateShips(void);
	void updatePlayers(int key);
	void updateState(void);

	void render(void) const;
	void renderBullets(void) const;
	void renderBoss(void) const;
	void renderShips(void) const;
	void renderPlayers(void) const;
	void renderScore(void) const;
	void renderTime(void) const;
	void renderKills(void) const;

	/**
	 * BACKGOUND
	 */
	void initBackground(void);
	void updateBackground(void);
	void renderBackgroundBase(void) const;
	void renderBackground(void) const;

	/**
	 * ENEMY BULLETS
	 */
	void renderEnemyBullets() const;
	void enemyShoot(int x, int y, int idx);
};
