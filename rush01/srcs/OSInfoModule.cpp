/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSInfoModule.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 20:38:25 by ikozlov           #+#    #+#             */
/*   Updated: 2018/07/07 21:02:52 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gkrellm.hpp"

OSInfoModule::OSInfoModule(std::string name) : BaseModule(name)
{
	struct utsname	uts;

	uname(&uts);
	_out.push_back(uts.sysname);
	_out.push_back(uts.release);
	_out.push_back(uts.version);
}

OSInfoModule::~OSInfoModule(void) { }

void
OSInfoModule::tick(void) { }