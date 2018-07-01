/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 20:33:42 by ikozlov           #+#    #+#             */
/*   Updated: 2018/06/30 21:08:58 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

const int ShrubberyCreationForm::_sign = 145;
const int ShrubberyCreationForm::_exec = 137;
const std::string
ShrubberyCreationForm::name = "Shrubbery";

ShrubberyCreationForm::ShrubberyCreationForm(void) :
	Form("Anonymous", ShrubberyCreationForm::name,\
	ShrubberyCreationForm::_sign, ShrubberyCreationForm::_exec) { }

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	Form(target, ShrubberyCreationForm::name, \
	ShrubberyCreationForm::_sign, ShrubberyCreationForm::_exec) { }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) :
	Form(src.getName(), ShrubberyCreationForm::name,\
	ShrubberyCreationForm::_sign, ShrubberyCreationForm::_exec)
{
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) { }

ShrubberyCreationForm
&ShrubberyCreationForm::operator= (const ShrubberyCreationForm &obj)
{
	(void)obj;
	return (*this);
}

void
ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	std::ofstream  out_file;

	Form::execute(executor);
	out_file.open(getTarget() + "_shrubbery",
				 std::ofstream::out | std::ofstream::trunc);
	if (out_file.fail())
	{
		std::cerr << "Error opening the outfile" << std::endl;
	}
	out_file << "          1          " << std::endl;
	out_file << "         / \\         " << std::endl;
	out_file << "        /   \\        " << std::endl;
	out_file << "       /     \\       " << std::endl;
	out_file << "      2       3      " << std::endl;
	out_file << "     / \\     / \\     " << std::endl;
	out_file << "    4   5   6   7    " << std::endl;
	out_file << "   /   / \\     / \\   " << std::endl;
	out_file << "  8   9   1   2   3  " << std::endl;
	out_file << "     /               " << std::endl;
	out_file << "    4                " << std::endl;
	out_file.close();
}
