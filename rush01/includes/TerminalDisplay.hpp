/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TerminalDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 15:45:31 by ikozlov           #+#    #+#             */
/*   Updated: 2018/07/07 15:49:58 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINALDISPLAY_HPP
# define TERMINALDISPLAY_HPP

# include "ft_gkrellm.hpp"

class TerminalDisplay : public IMonitorDisplay
{

	public:

		TerminalDisplay(std::vector<IMonitorModule*> modules);
		~TerminalDisplay(void);

		void		main(void);
		void		refresh(void);
		void		render(void);

	private:

		TerminalDisplay(void);
		TerminalDisplay(TerminalDisplay const &obj);
		TerminalDisplay	&operator=(TerminalDisplay const &r);

		std::vector<IMonitorModule*>	_modules;
};

#endif
