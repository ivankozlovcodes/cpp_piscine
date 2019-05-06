/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Star.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 16:05:49 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/06 13:35:01 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Star.hpp"

#include <time.h>
#include <stdlib.h>

#include <curses.h>

/*
 * Star
*/

Star::Star(void) : _star(getRandomStar())
{
	dx = (1 + rand() % 3);
	dx = -dx;
	dy = 0;
	if (_star == COMET || (rand() % 2) == 0)
		dx = -dx;
}

Star::Star(std::string star) : _star(star) { }

Star::Star(const Star &src)
{
	*this = src;
}

Star::~Star(void) { }

Star
&Star::operator=(const Star &rhs)
{
	(void)rhs;
	return *this;
}

std::string
Star::getRandomStar(void)
{
	std::string  stars[] = { STAR_1, STAR_2, STAR_3, STAR_4, COMET };

	return stars[rand() % 5];
}

std::string
Star::getStar(void) const
{
	return _star;
}

void
Star::move(void)
{
	_skipMove++;

	if (_skipMove < 5)
		return ;

	Entity::move();
	_skipMove = 0;
}

void
Star::render(void) const
{
	size_t		r = 0, c = 0;

	attron(COLOR_PAIR(_color));
	for (size_t i = 0; i < _star.length(); i++) {
		if (_star[i] == '\n') {
			r++; c = 0;
		} else {
			c++;
			mvaddch(y + r, x + c, _star[i] | A_BOLD);
		}
	}
	attroff(COLOR_PAIR(_color));
}
