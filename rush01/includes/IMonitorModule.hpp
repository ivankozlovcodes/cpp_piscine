/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 01:57:42 by ivankozlov        #+#    #+#             */
/*   Updated: 2018/07/08 12:38:48 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

class IMonitorModule
{
	public:

		IMonitorModule(void);
		virtual ~IMonitorModule(void);

		virtual void							tick(void) = 0;

	private:

		IMonitorModule(IMonitorModule const &obj);
		IMonitorModule	&operator=(IMonitorModule const &r);

};

#endif
