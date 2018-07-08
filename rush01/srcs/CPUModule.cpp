/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 21:26:13 by ikozlov           #+#    #+#             */
/*   Updated: 2018/07/07 23:42:06 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gkrellm.hpp"

#include <stdio.h>

CPUModule::CPUModule(std::string name) : BaseModule(name)
{
	tick();
}

CPUModule::~CPUModule(void) { }

void
CPUModule::tick(void)
{
	FILE			*stream;
	char			*buff = new char[256];
	std::string		output;
	const char		*cmd =  "top -l 1 | grep -E \"^CPU\"";
	
	stream = popen(cmd, "r");
	if (stream && fgets(buff, 255, stream)) {
		output = std::string(buff);
		std::cout << output << std::endl;
	}
	pclose(stream);
	_out.clear();
	_out.push_back(output);
}
