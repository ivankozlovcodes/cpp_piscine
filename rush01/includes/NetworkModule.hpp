/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 01:53:12 by ikozlov           #+#    #+#             */
/*   Updated: 2018/07/08 01:55:27 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORKMODULE_HPP
# define NETWORKMODULE_HPP

# include "ft_gkrellm.hpp"

class NetworkModule : public BaseModule
{
	public:

		NetworkModule(std::string const name);
		virtual ~NetworkModule(void);

		void						tick(void);

	private:

		NetworkModule(void);
		NetworkModule(NetworkModule const &obj);
		NetworkModule	&operator=(NetworkModule const &r);

};

#endif
