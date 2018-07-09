/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 16:16:58 by ikozlov           #+#    #+#             */
/*   Updated: 2018/07/08 22:50:01 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gkrellm.hpp"

BaseModule::BaseModule(std::string name) :
	IMonitorModule(),
	_name(name),
	_out() { }

BaseModule::~BaseModule(void) { }

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

std::string
BaseModule::runCommand(std::string cmd)
{
	std::string		data;
	FILE*			stream;
	const int max_buffer = 256;
	char buffer[max_buffer];

	stream = popen(cmd.c_str(), "r");
	if (stream)
	{
		while (!feof(stream))
		{
			if (fgets(buffer, max_buffer, stream) != NULL)
				data.append(buffer);
		}
		pclose(stream);
	}
	return (data);
}
