/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 15:55:11 by ikozlov           #+#    #+#             */
/*   Updated: 2018/06/30 16:09:05 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"

int
main(void)
{
    Bureaucrat  asd("Asd", 10);

    std::cout << asd.getGrade() << std::endl;
    std::cout << asd.getName() << std::endl;
    asd.incGrade(150);
    return (0);
}
