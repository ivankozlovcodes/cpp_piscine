/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 16:16:58 by ikozlov           #+#    #+#             */
/*   Updated: 2018/07/07 16:20:54 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gkrellm.hpp"

BaseModule::BaseModule(std::string name) :
	IMonitorModule(),
	_name(name),
	_out() { }

std::string const&
BaseModule::getName(void)
{
	return (_name);
}

std::vector<std::string> const&
BaseModule::getOutput(void) const
{
	return (_out);
}
