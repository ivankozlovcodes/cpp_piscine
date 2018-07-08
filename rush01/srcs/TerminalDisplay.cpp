/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TerminalDisplay.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 16:25:52 by ikozlov           #+#    #+#             */
/*   Updated: 2018/07/08 12:40:51 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gkrellm.hpp"
#include <string.h>

TerminalDisplay::TerminalDisplay(std::vector<IMonitorModule*> modules) :
	IMonitorDisplay(),
	_name("FT_GKRELLM"),
	_modules(modules)
{
	initscr(); // initialize screen
	cbreak();
	noecho(); // stop displaying user input
	nonl();
	intrflush(stdscr, FALSE);
	keypad(stdscr, TRUE);
	curs_set(0);
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);

	getmaxyx(stdscr, _rows, _cols);
	_w = stdscr;
	_mid = _cols / 2;
	_filler = buildString("-", "||", "||", _cols);
	_separator = buildString("=", "||", "||", _cols);
}

TerminalDisplay::~TerminalDisplay(void) 
{
	endwin(); // close window
}

void
TerminalDisplay::main(void)
{
	int		c = 0;

	while(1)
	{
		try
		{
			if ((c = getch()) != ERR)
			{
				endwin();
				break ;
			}
			refresh();
			render();
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
			endwin();
			break ;
		}
	}
}

void
TerminalDisplay::refresh(void)
{
	std::vector<IMonitorModule*>::iterator it;

	_x = -1;
	_y = -1;
	for (it = _modules.begin(); it != _modules.end(); it++)
		(**it).tick();
}

const char
*TerminalDisplay::buildString(const char *s, std::string head,\
	std::string tail, int len)
{
	std::string		mid;
	int				s_len = strlen(s);

	len = len - head.length() - tail.length();
	for (int i = 0; i < len; i += s_len)
		mid.append(s);
	mid.erase(len, mid.length());
	head.append(mid);
	head.append(tail);
	return (head.c_str());
}

void
TerminalDisplay::printFrame(void)
{
	mvprintw(_x++, _y, buildString("= ", "  /", "\\  ", _cols));
	mvprintw(_x++, _y, buildString("= ", " /", "\\ ", _cols));
	for (int i = _x; i < _rows - 2; i++)
	{
		mvprintw(i, _y, "||");
		mvprintw(i, _cols - 2, "||");
	}
	mvprintw(_rows - 2, _y, buildString("= ", " \\", "/ ", _cols));
	mvprintw(_rows - 1, _y, buildString("= ", "  \\", "/  ", _cols));
}

void
TerminalDisplay::printTextCenter(std::string text)
{
	mvprintw(_x, _mid - text.length() / 2, text.c_str());
}

void
TerminalDisplay::printModule(BaseModule *module)
{
	std::vector<std::string>::iterator		it;
	std::vector<std::string>				info = module->getOutput();

	mvprintw(_x++, _y, _separator.c_str());
	mvprintw(_x++, _y, _filler.c_str());
	mvprintw(_x, _y, _filler.c_str());
	printTextCenter(module->getName());
	_x++;
	mvprintw(_x++, _y, _filler.c_str());
	for (it = info.begin(); it != info.end(); it++)
	{
		mvprintw(_x, _y, _filler.c_str());
		printTextCenter(*it);
		_x++;
	}
	mvprintw(_x++, _y, _separator.c_str());
}

void
TerminalDisplay::render(void)
{
	std::vector<IMonitorModule*>::iterator	it;
	IMonitorModule							*current;

	_x = 0; _y = 0;
	printFrame();
	mvprintw(_x++, _y, _separator.c_str());
	mvprintw(_x++, _y, _filler.c_str());
	mvprintw(_x, _y, _filler.c_str());
	printTextCenter(_name);
	_x++;
	mvprintw(_x++, _y, _filler.c_str());
	mvprintw(_x++, _y, _separator.c_str());
	for (it = _modules.begin(); it != _modules.end(); it++)
		printModule(dynamic_cast<BaseModule*>(*it));
	wrefresh(_w);
}