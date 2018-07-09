/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicDisplay.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 22:04:54 by ikozlov           #+#    #+#             */
/*   Updated: 2018/07/08 23:34:12 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gkrellm.hpp"

GraphicDisplay::GraphicDisplay(std::vector<IMonitorModule*> const modules, sf::RenderWindow	&window) :
		IMonitorDisplay(), _modules(modules), _window(window)
{
	_font.loadFromFile("arial.ttf");
}

GraphicDisplay::~GraphicDisplay()
{
	this->_window.close();
}

void
GraphicDisplay::main(void)
{
	render();
	while(this->_window.isOpen())
	{
		try
		{
			sf::Event event;
			while (this->_window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					this->_window.close();
			}
			refresh();
			render();
		}
		catch (const std::exception &e)
		{
			this->_window.close();
			exit(1);
		}
	}
}

void
GraphicDisplay::render()
{
	std::vector<IMonitorModule*>::iterator	it;
	BaseModule								*cur;
	std::string								s = "";
	std::vector<std::string>				out;
	sf::Text	t1;


	this->_window.clear(sf::Color::White);

	t1.setFillColor(sf::Color::Black);
	t1.setCharacterSize(30);
	t1.setStyle(sf::Text::Bold);
	t1.setFont(_font);
	t1.setPosition(20, 100);
	for (it = _modules.begin(); it != _modules.end(); it++)
	{
		cur = dynamic_cast<BaseModule*>(*it);
		s.append(cur->getName());
		s.append("\n");
		out = cur->getOutput();
		for (int i = 0; i < out.size(); i++)
		{
			s.append(out[i]);
			s.append("\n");
		}
	}
	t1.setString(s.c_str());
	this->_window.draw(t1);
	this->_window.display();
}

void
GraphicDisplay::refresh()
{
	std::vector<IMonitorModule*>::iterator it;

	for (it = _modules.begin(); it != _modules.end(); it++)
		(**it).tick();
}
