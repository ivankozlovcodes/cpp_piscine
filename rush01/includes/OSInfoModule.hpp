/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSInfoModule.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 20:37:08 by ikozlov           #+#    #+#             */
/*   Updated: 2018/07/07 20:38:08 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSINFOMODULE_HPP
# define OSINFOMODULE_HPP

# include "ft_gkrellm.hpp"

class OSInfoModule : public BaseModule
{
	public:

		OSInfoModule(std::string const name);
		virtual ~OSInfoModule(void);

		void						tick(void);

	private:

		OSInfoModule(void);
		OSInfoModule(OSInfoModule const &obj);
		OSInfoModule	&operator=(OSInfoModule const &r);

};

#endif
