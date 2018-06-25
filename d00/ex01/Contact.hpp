/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 19:54:56 by ikozlov           #+#    #+#             */
/*   Updated: 2018/06/25 09:24:21 by ivankozlov       ###   ########.fr       */
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
		std::string		getLastName(void);
		std::string		getNickname(void);

		void			setFirstName(std::string name);
		void			setLastName(std::string name);
		void			setNickname(std::string name);
		void			setLogin(std::string name);
		void			setEmail(std::string name);
		void			setPhone(std::string name);
		void			setBday(std::string name);
		void			setMeal(std::string name);
		void			setUColor(std::string name);
		void			setSecret(std::string name);

		void			print(void);
		int				isEmpty(void);

		static Contact	createNewContact(void);

	private:
		std::string		_firstName;
		std::string		_lastName;
		std::string		_nickname;
		std::string		_login;
		std::string		_email;
		std::string		_phone;
		std::string		_bday;
		std::string		_meal;
		std::string		_ucolor;
		std::string		_secret;
		int				_notEmpty;
};

#endif
