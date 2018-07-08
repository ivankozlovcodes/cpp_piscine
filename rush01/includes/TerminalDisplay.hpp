/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TerminalDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 15:45:31 by ikozlov           #+#    #+#             */
/*   Updated: 2018/07/08 12:42:46 by ikozlov          ###   ########.fr       */
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

		void		printFrame(void);
		void		printTextCenter(std::string text);
		void		printModule(BaseModule *module);
		const char	*buildString(const char *s, std::string head,\
			std::string tail, int len);

		std::vector<IMonitorModule*>	_modules;
		int								_cols;
		int								_rows;
		int								_x, _y;
		int								_mid;
		std::string						_name;
		WINDOW							*_w;

		std::string						_filler;
		std::string						_separator;
};

#endif
