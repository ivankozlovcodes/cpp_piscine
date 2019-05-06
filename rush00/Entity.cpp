/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arherrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 16:16:34 by arherrer          #+#    #+#             */
/*   Updated: 2019/05/05 22:14:53 by arherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Entity.hpp"

/*** Coplien ***/
Entity::Entity(void)
{
	x = 0;
	y = 0;
	alive = false;
	justKilled = false;
	counter = 0;
	counter1 = 0;
}

Entity::Entity(const Entity& that)
{
	*this = that;
}

Entity& Entity::operator =(const Entity& that)
{
	x = that.x;
	y = that.y;
	return *this;
}

Entity::~Entity(void)
{
}

void
Entity::render() const { }

void
Entity::move()
{
	x += dx;
	y += dy;
}

void
Entity::setColor(int color)
{
	_color = color;
}
