/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:58:24 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/01 15:59:21 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int 				main(void)
{
	std::string string = "HI THIS IS MY BRAIN";
	std::string *ptr = &string;
	std::string &ref = string;

	std::cout << "this is the pointer '" << *ptr << "'" << std::endl;
	std::cout << "this is the reference '" << ref << "'" << std::endl;

	return 0;
}
