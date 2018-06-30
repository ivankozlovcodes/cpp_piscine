/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 15:29:20 by ikozlov           #+#    #+#             */
/*   Updated: 2018/06/30 16:11:18 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <exception>

# define MIN_GRADE 1
# define MAX_GRADE 150

# define TOO_LOW_MSG "Grade is too low... Should be within [1, 150]"
# define TOO_HIGH_MSG "Grade is too high... Should be within [1, 150]"

class	Bureaucrat
{
	public:
		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException(void);
				virtual ~GradeTooHighException(void) throw();

				virtual const char	*what() const throw();
		};

		Bureaucrat(std::string name, int grade);
		~Bureaucrat(void);

		int				getGrade(void);
		std::string		getName(void);

		void			setName(std::string name);
		void			incGrade(int value);
		void			decGrade(int value);

	private:
		int				_grade;
		std::string		_name;
};

#endif
