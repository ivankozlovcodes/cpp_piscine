/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 01:54:23 by ikozlov           #+#    #+#             */
/*   Updated: 2018/07/08 01:57:25 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gkrellm.hpp"

NetworkModule::NetworkModule(std::string name) : BaseModule(name)
{
	tick();
}

NetworkModule::~NetworkModule(void) { }

void
NetworkModule::tick(void)
{
	std::string					line = "";
	std::ifstream				file;
	std::vector<std::string>	tmp;
	const char		*cmd =  "top -l 1 | grep -E \"^Networks\" > ./.network";
	
	
	std::system(cmd);
	file.open(".network");
	while (getline(file, line, ' '))
		tmp.push_back(line);
	file.close();
	_out.clear();
	_out.push_back(" Packets: ");
	_out.push_back("In: " + tmp[2]);
	_out.push_back("System: " + tmp[4]);
	tmp.clear();
}
