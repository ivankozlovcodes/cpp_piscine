/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 18:24:34 by ikozlov           #+#    #+#             */
/*   Updated: 2018/07/03 16:57:10 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CENTRALBUREAUCRACY_H
# define CENTRALBUREAUCRACY_H

#include <iostream>
#include "Form.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "OfficeBlock.hpp"

class	CentralBureaucracy
{

	public:

		class TooBusyException : public std::exception
		{
			public:
				
				TooBusyException(void);
				TooBusyException(TooBusyException const &obj);
				virtual ~TooBusyException(void) throw();
				TooBusyException &operator=(TooBusyException const &r);
				virtual const char* what() const throw();

				static const char	*message;
		};

		class TooManyEmployeesException : public std::exception
		{
			public:
				
				TooManyEmployeesException(void);
				TooManyEmployeesException(TooManyEmployeesException const &obj);
				virtual ~TooManyEmployeesException(void) throw();
				TooManyEmployeesException &operator=(TooManyEmployeesException const &r);
				virtual const char* what() const throw();

				static const char	*message;
		};	

		CentralBureaucracy(void);
		CentralBureaucracy(CentralBureaucracy &obj);
		virtual ~CentralBureaucracy(void);
		CentralBureaucracy &operator=(const CentralBureaucracy &src);

		void	feedSigner(Bureaucrat &obj);
		void	feedExecuter(Bureaucrat &obj);

		void	queueUp(std::string obj);

		void	doBureaucracy(void);

	private:

		static const int	_blocks_num = 20;
		static const int	_targets_num = 100;

		void				_generateInterns(void);

		OfficeBlock			_blocks[CentralBureaucracy::_blocks_num];
		std::string			_targets[CentralBureaucracy::_targets_num];
}; 

#endif
