/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 02:00:41 by ivankozlov        #+#    #+#             */
/*   Updated: 2018/07/08 23:34:08 by ikozlov          ###   ########.fr       */
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
parseFlags(int ac, char *av[])
{
	if (ac != 2)
		return (-1);
	std::string s(av[1]);
	if (s == "-t")
		return (0);
	else if (s == "-g")
		return (1);
	else
		return (-1);
}

int
main(int ac, char *av[])
{
	std::vector<IMonitorModule*>		modules;
	IMonitorDisplay						*root;
	int									flags = parseFlags(ac, av);

	if (flags < 0)
	{
		std::cout << "Usage: ./ft_gkrellm [-t | -g]" << std::endl;
		return (0);
	}
	modules = buildModules();
	if (flags == 0)
	{
		root = new TerminalDisplay(modules);
		root->main();
	}
	else
	{
		sf::RenderWindow window(sf::VideoMode(2000, 1000), "Frankenstein");
		root = new GraphicDisplay(modules, window);
		root->render();
		while(window.isOpen())
		{
			try
			{
				sf::Event event;
				while (window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						window.close();
				}
				root->refresh();
				root->render();
			}
			catch (const std::exception &e)
			{
				window.close();
				exit(1);
			}
		}
	}

	return (0);
}
