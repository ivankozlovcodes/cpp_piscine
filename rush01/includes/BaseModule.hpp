/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 16:13:14 by ikozlov           #+#    #+#             */
/*   Updated: 2018/07/08 22:49:46 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASEMODULE_HPP
# define BASEMODULE_HPP

# include "ft_gkrellm.hpp"

class BaseModule : public IMonitorModule
{
	public:

		BaseModule(std::string const name);
		virtual ~BaseModule(void);

		virtual std::string const				&getName(void);
		virtual std::vector<std::string> const	&getOutput(void) const;

		std::string								runCommand(std::string cmd);

	protected:

		std::string								_name;
		std::vector<std::string>				_out;

	private:

		BaseModule(void);
		BaseModule(BaseModule const &obj);
		BaseModule	&operator=(BaseModule const &r);

};

#endif