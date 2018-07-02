/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 16:38:56 by ikozlov           #+#    #+#             */
/*   Updated: 2018/07/01 19:04:20 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OFFICEBLOCK_H
# define OFFICEBLOCK_H

#include <iostream>
#include "Form.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"

class	OfficeBlock
{

	public:

		OfficeBlock(void);
		OfficeBlock(Intern &intern, Bureaucrat &signer, Bureaucrat &executer);
		virtual ~OfficeBlock(void);

		void			setIntern(Intern &obj);
		void			setSigner(Bureaucrat &obj);
		void			setExecutor(Bureaucrat &obj);

		Bureaucrat*		getSigner(void);
		Bureaucrat*		getExecutor(void);

		void			doBureaucracy(std::string form, std::string target);

		class NoInternException : public std::exception
		{
			public:
				
				NoInternException(void);
				NoInternException(NoInternException const &obj);
				virtual ~NoInternException(void) throw();
				NoInternException &operator=(NoInternException const &r);
				virtual const char* what() const throw();

				static const char	*message;
		};

		class NoSignerException : public std::exception
		{
			public:
				
				NoSignerException(void);
				NoSignerException(NoSignerException const &obj);
				virtual ~NoSignerException(void) throw();
				NoSignerException &operator=(NoSignerException const &r);
				virtual const char* what() const throw();

				static const char	*message;
		};

		class NoExecuterException : public std::exception
		{
			public:
				
				NoExecuterException(void);
				NoExecuterException(NoExecuterException const &obj);
				virtual ~NoExecuterException(void) throw();
				NoExecuterException &operator=(NoExecuterException const &r);
				virtual const char* what() const throw();

				static const char	*message;
		};

	private:

		OfficeBlock(OfficeBlock &obj);
		OfficeBlock &operator=(OfficeBlock const &src);

		Intern		*_intern;
		Bureaucrat	*_signer;
		Bureaucrat	*_executer;
}; 

#endif