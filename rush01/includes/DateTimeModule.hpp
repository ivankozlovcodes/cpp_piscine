/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateTimeModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 21:07:25 by ikozlov           #+#    #+#             */
/*   Updated: 2018/07/07 21:08:44 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATETIMEMODULE_HPP
# define DATETIMEMODULE_HPP

# include "ft_gkrellm.hpp"

class DateTimeModule : public BaseModule
{
	public:

		DateTimeModule(std::string const name);
		virtual ~DateTimeModule(void);

		void						tick(void);

	private:

		DateTimeModule(void);
		DateTimeModule(DateTimeModule const &obj);
		DateTimeModule	&operator=(DateTimeModule const &r);

};

#endif
