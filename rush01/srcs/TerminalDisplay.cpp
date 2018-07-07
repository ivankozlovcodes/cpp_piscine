/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TerminalDisplay.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 16:25:52 by ikozlov           #+#    #+#             */
/*   Updated: 2018/07/07 16:28:00 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gkrellm.hpp"

TerminalDisplay::TerminalDisplay(std::vector<IMonitorModule*> modules) :
	IMonitorDisplay(),
	_modules(modules) { }

TerminalDisplay::~TerminalDisplay(void) { }

void
TerminalDisplay::main(void)
{

}

void
TerminalDisplay::refresh(void)
{
	
}

void
TerminalDisplay::render(void)
{
	
}