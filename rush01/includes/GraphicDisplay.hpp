/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicDisplay.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 22:03:23 by ikozlov           #+#    #+#             */
/*   Updated: 2018/07/08 22:20:10 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICDISPLAY_HPP
# define GRAPHICDISPLAY_HPP

# include <ft_gkrellm.hpp>

class GraphicDisplay : public IMonitorDisplay
{
	public:

		GraphicDisplay(std::vector<IMonitorModule*> const modules, sf::RenderWindow	&window);
		virtual ~GraphicDisplay(void);
		
		void		main(void);
		void		refresh(void);
		void		render(void);

	private:

		GraphicDisplay(void);
		GraphicDisplay(GraphicDisplay const &obj);
		GraphicDisplay	&operator=(GraphicDisplay const &r);

		std::vector<IMonitorModule*>	_modules;

		sf::RenderWindow				&_window;
		sf::Font						_font;
};

#endif