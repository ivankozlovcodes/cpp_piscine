/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 18:25:56 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/06 19:41:51 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class	Form
{
	public:

		/*
		 *	GradeTooLowException class
		 */
		class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException(void);
				GradeTooLowException(const GradeTooLowException &src);
				virtual ~GradeTooLowException(void) throw();

				GradeTooLowException &operator= (const GradeTooLowException &obj);

				virtual const char	*what() const throw();

				static const char	*message;
		};

		/*
		 *	GradeTooLowException class
		 */
		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException(void);
				GradeTooHighException(const GradeTooHighException &src);
				virtual ~GradeTooHighException(void) throw();

				GradeTooHighException &operator= (const GradeTooHighException &obj);

				virtual const char	*what() const throw();

				static const char	*message;
		};

		/*
		 *	NotSignedException class
		 */
		class NotSignedException : public std::exception
		{
			public:
				NotSignedException(void);
				NotSignedException(const NotSignedException &src);
				virtual ~NotSignedException(void) throw();

				NotSignedException &operator= (const NotSignedException &obj);

				virtual const char	*what() const throw();

				static const char	*message;
		};

		Form(void);
		Form(const Form &src);
		Form(std::string targer, std::string name,\
				int grade_to_sign, int grade_to_execute);

		~Form(void);

		Form					&operator= (const Form &obj);

		void					beSigned(Bureaucrat bureaucrat);

		bool					getSigned(void) const;
		int						getGradeToSign(void) const;
		int						getGradeToExecute(void) const;
		std::string				getName(void) const;
		std::string				getTarget(void) const;

		virtual void			execute(const Bureaucrat &executor) const = 0;

	private:
		bool					_signed;
		const int				_grade_to_sign;
		const int				_grade_to_execute;
		const std::string		_name;
		const std::string		_target;
};

std::ostream		&operator<< (std::ostream &out,\
		const Form &obj);

#endif
