/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 01:57:42 by ivankozlov        #+#    #+#             */
/*   Updated: 2018/07/07 02:32:25 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

class IMonitorModule
{
	public:

		IMonitorModule(void);
		virtual ~IMonitorModule(void);

		// virtual void							tick(void) = 0;
		// virtual std::vector<std::string> const	&getOutput(void) const = 0;
		// virtual std::string const				&getName(void) const = 0;
		
	private:

		IMonitorModule(IMonitorModule const &obj);
		IMonitorModule	&operator=(IMonitorModule const &r);
};

#endif
