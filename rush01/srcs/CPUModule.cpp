/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 21:26:13 by ikozlov           #+#    #+#             */
/*   Updated: 2018/07/08 01:42:03 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gkrellm.hpp"

#include <stdio.h>

CPUModule::CPUModule(std::string name) : BaseModule(name)
{
	std::ifstream				file;
	std::string					line = "";
	const char		*cmd =  "sysctl -n machdep.cpu.brand_string > ./.cpuinfo";

	std::system(cmd);
	file.open(".cpuinfo");
	getline(file, line);
	file.close();
	_cpuinfo = line;
	tick();
}

CPUModule::~CPUModule(void) { }

void
CPUModule::tick(void)
{
	std::string					line = "";
	std::ifstream				file;
	std::vector<std::string>	tmp;
	const char		*cmd =  "top -l 1 | grep -E \"^CPU\" > ./.cpuusage";
	
	
	std::system(cmd);
	file.open(".cpuusage");
	while (getline(file, line, ' '))
		tmp.push_back(line);
	file.close();
	_out.clear();
	_out.push_back(_cpuinfo);
	_out.push_back("User: " + tmp[2] + "%");
	_out.push_back("System: " + tmp[4] + "%");
	_out.push_back("Idle: " + tmp[6] + "%");
	tmp.clear();
}
