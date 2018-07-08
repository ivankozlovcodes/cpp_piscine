/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAMModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 01:41:53 by ikozlov           #+#    #+#             */
/*   Updated: 2018/07/08 01:51:21 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gkrellm.hpp"

#include <stdio.h>

RAMModule::RAMModule(std::string name) : BaseModule(name)
{
	tick();
}

RAMModule::~RAMModule(void) { }

void
RAMModule::tick(void)
{
	std::string					line = "";
	std::ifstream				file;
	std::vector<std::string>	tmp;
	const char		*cmd =  "top -l 1 | grep -E \"^Phys\" > ./.ramusage";
	
	std::system(cmd);
	file.open(".ramusage");
	while (getline(file, line, ' '))
		tmp.push_back(line);
	file.close();
	_out.clear();
	_out.push_back("Total: " + std::to_string(stoi(tmp[1])\
		+ stoi(tmp[5])) + "M");
	_out.push_back("Used: " + tmp[1]);
	_out.push_back("Unused: " + tmp[5]);
	tmp.clear();
}
