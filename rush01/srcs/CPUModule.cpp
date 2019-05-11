/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 21:26:13 by ikozlov           #+#    #+#             */
/*   Updated: 2019/05/10 19:11:20 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gkrellm.hpp"

#include <stdio.h>
#include <algorithm>

CPUModule::CPUModule(std::string name) : BaseModule(name)
{
	const char		*cmd =  "sysctl -n machdep.cpu.brand_string";

	_cpuinfo = runCommand(cmd);
	_cpuinfo.erase(std::remove(_cpuinfo.begin(), _cpuinfo.end(), '\n'));
	tick();
}

CPUModule::~CPUModule(void) { }

void
CPUModule::tick(void)
{
	std::string					line = "";
	std::vector<std::string>	tmp;
	const char		*cmd =  "top -l 1 | grep -E \"^CPU\"";
	
	line = runCommand(cmd);
	std::istringstream iss(line);
	for(std::string s; iss >> s; )
		tmp.push_back(s);
	_out.clear();
	_out.push_back(_cpuinfo);
	_out.push_back("User: " + tmp[2] + "%");
	_out.push_back("System: " + tmp[4] + "%");
	_out.push_back("Idle: " + tmp[6] + "%");
	tmp.clear();
}
