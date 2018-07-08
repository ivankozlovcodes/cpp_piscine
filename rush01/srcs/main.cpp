/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 02:00:41 by ivankozlov        #+#    #+#             */
/*   Updated: 2018/07/07 21:40:39 by ikozlov          ###   ########.fr       */
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
	TerminalDisplay		root(modules);

	root.main();

	return (0);
}
