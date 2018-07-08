/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 21:23:35 by ikozlov           #+#    #+#             */
/*   Updated: 2018/07/08 01:32:00 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPUMODULE_HPP
# define CPUMODULE_HPP

# include "ft_gkrellm.hpp"

class CPUModule : public BaseModule
{
	public:

		CPUModule(std::string const name);
		virtual ~CPUModule(void);

		void						tick(void);

	private:

		CPUModule(void);
		CPUModule(CPUModule const &obj);
		CPUModule	&operator=(CPUModule const &r);

		std::string					_cpuinfo;
};

#endif
