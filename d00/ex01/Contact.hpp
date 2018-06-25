/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 19:54:56 by ikozlov           #+#    #+#             */
/*   Updated: 2018/06/24 22:07:35 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class	Contact
{
	public:
		Contact(void);
		~Contact(void);

		std::string		getFirstName(void);

		void			setFirstName(std::string name);

		void			print(void);
		int				isEmpty(void);

		static Contact	createNewContact(void);

	private:
		std::string		_firstName;
		int				_notEmpty;
};

#endif