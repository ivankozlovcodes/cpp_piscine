/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostNameModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 15:40:23 by ikozlov           #+#    #+#             */
/*   Updated: 2018/07/07 20:38:11 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOSTNAMEMODULE_HPP
# define HOSTNAMEMODULE_HPP

# include "ft_gkrellm.hpp"

class HostNameModule : public BaseModule
{
	public:

		HostNameModule(std::string const name);
		virtual ~HostNameModule(void);

		void						tick(void);

	private:

		HostNameModule(void);
		HostNameModule(HostNameModule const &obj);
		HostNameModule	&operator=(HostNameModule const &r);

};

#endif
