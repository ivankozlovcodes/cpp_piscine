/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateTimeModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 21:08:47 by ikozlov           #+#    #+#             */
/*   Updated: 2018/07/07 21:32:17 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DateTimeModule.hpp"

DateTimeModule::DateTimeModule(std::string name) : BaseModule(name)
{
	tick();
}

DateTimeModule::~DateTimeModule(void) { }

void
DateTimeModule::tick(void)
{
	std::time_t		t = std::time(0);
	std::tm*		now = std::localtime(&t);
	char			_date[30];
	char			_time[30];

	strftime(_date, sizeof(_date), "%a %b-%d-%Y", now);
	strftime(_time, sizeof(_time), "%T", now);

	_out.clear();
	_out.push_back(_date);
	_out.push_back(_time);
}
