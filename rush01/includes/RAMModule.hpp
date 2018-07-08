/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAMModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 01:40:40 by ikozlov           #+#    #+#             */
/*   Updated: 2018/07/08 01:41:37 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAMMODULE_HPP
# define RAMMODULE_HPP

# include "ft_gkrellm.hpp"

class RAMModule : public BaseModule
{
	public:

		RAMModule(std::string const name);
		virtual ~RAMModule(void);

		void						tick(void);

	private:

		RAMModule(void);
		RAMModule(RAMModule const &obj);
		RAMModule	&operator=(RAMModule const &r);

		std::string					_RAMinfo;
};

#endif
