/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 02:00:41 by ivankozlov        #+#    #+#             */
/*   Updated: 2018/07/08 18:09:25 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gkrellm.hpp"

std::vector<IMonitorModule*>
buildModules(void)
{
	std::vector<IMonitorModule*>		modules;

	modules.push_back(new HostNameModule(" Host Name "));
	modules.push_back(new OSInfoModule(" OS Info "));
	modules.push_back(new DateTimeModule(" Date and time "));
	modules.push_back(new CPUModule(" CPU Info "));
	modules.push_back(new RAMModule(" RAM Info "));
	modules.push_back(new NetworkModule(" Network "));

	return (modules);
}

int
main(int ac, char *av[])
{
	std::vector<IMonitorModule*>		modules;
	// todo: parse flags
	// todo: help command
	// todo: errors
	// todo: build modules
	modules = buildModules();
	// TerminalDisplay		root(modules);
	GraphicDisplay			root;


	// root.main();

	return (0);
}
