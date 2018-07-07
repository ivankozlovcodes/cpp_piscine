/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostNameModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 15:55:34 by ikozlov           #+#    #+#             */
/*   Updated: 2018/07/07 16:30:05 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gkrellm.hpp"

HostNameModule::HostNameModule(std::string name) : BaseModule(name)
{
	char		buff[_POSIX_HOST_NAME_MAX];

	gethostname(buff, _POSIX_HOST_NAME_MAX);
	_out.push_back(buff);
	getlogin_r(buff, _POSIX_HOST_NAME_MAX);
	_out.push_back(buff);
}

HostNameModule::~HostNameModule(void) { }

void
HostNameModule::tick(void) { }
