/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 01:51:29 by ivankozlov        #+#    #+#             */
/*   Updated: 2018/07/07 01:59:30 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

class IMonitorDisplay
{
	public:

		IMonitorDisplay(void);
		virtual ~IMonitorDisplay(void);

		// virtual void		refreshOutput(void) = 0;
		// virtual void		renderOutput(void) = 0;
		// virtual void		drawPony(int i) = 0;
		
	private:

		IMonitorDisplay(IMonitorDisplay const &obj);
		IMonitorDisplay	&operator=(IMonitorDisplay const &r);
};

#endif
