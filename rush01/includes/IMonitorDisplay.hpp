/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 01:51:29 by ivankozlov        #+#    #+#             */
/*   Updated: 2018/07/08 12:39:21 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

class IMonitorDisplay
{
	public:

		IMonitorDisplay(void);
		virtual ~IMonitorDisplay(void);

		virtual void				main(void) = 0;
		virtual void				refresh(void) = 0;
		virtual void				render(void)= 0;

	private:

		IMonitorDisplay(IMonitorDisplay const &obj);
		IMonitorDisplay	&operator=(IMonitorDisplay const &r);
};

#endif
