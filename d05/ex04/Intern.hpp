/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 14:34:57 by ikozlov           #+#    #+#             */
/*   Updated: 2018/07/01 15:37:18 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <stdexcept>
# include <map>

# include "Form.hpp"

# define PP "presidential pardon"
# define RR "robotomy request"
# define SC "shrubbery creation"

class Intern
{
	public:
		Intern(void);
		Intern(const Intern& src);

		~Intern(void);

		Intern				&operator= (const Intern& obj);

		Form				*makeForm(std::string name, std::string target);

		typedef Form* (Intern::*InternFPointer)(std::string);
		typedef std::map<std::string, InternFPointer>	funcMap;

	private:
		Form*				_searchForm(std::string n, std::string t);
		Form*				_newPresidentialPardonForm(std::string target);
		Form*				_newRobotomyRequestForm(std::string target);
		Form*				_newShrubberyCreationForm(std::string target);

		funcMap				_functions;
};

#endif