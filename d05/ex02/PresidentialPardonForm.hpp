/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 20:31:10 by ikozlov           #+#    #+#             */
/*   Updated: 2018/07/03 16:52:47 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP

# include <fstream>

# include "Form.hpp"
# include "Bureaucrat.hpp"

class PresidentialPardonForm : public Form
{
public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &src);

	~PresidentialPardonForm(void);

	PresidentialPardonForm		&operator= (const PresidentialPardonForm &rhs);

	virtual void				execute(const Bureaucrat &executor) const;

	static const std::string	name;

private:
	static const int			_sign;
	static const int			_exec;
};

#endif
