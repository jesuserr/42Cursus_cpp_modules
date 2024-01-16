/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:40:56 by jesuserr          #+#    #+#             */
/*   Updated: 2023/12/16 00:10:06 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/*********************** ORTHODOX CANONICAL CLASS FORM ************************/

ShrubberyCreationForm::ShrubberyCreationForm(void) : \
AForm ("ShrubberyCreationForm", 145, 137, "Default")
{
	std::cout << "Unsigned Shrubbery Creation Form created." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : \
AForm ("ShrubberyCreationForm", 145, 137, target)
{
	std::cout << "Unsigned Shrubbery Creation Form for " << target;
	std::cout << " created." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & source) : \
AForm (source)
{
	std::cout << "Shrubbery Creation Form cloned." << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & source)
{
	if (this != &source)
	{
		std::cout << "Shrubbery Creation Form signature updated." << std::endl;
		this->setSignature(source.getIsSigned());
	}	
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << this->getTarget() << " Shrubbery Creation Form destroyed.";
	std::cout << std::endl;
}

/****************************** MEMBER FUNCTIONS ******************************/

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::ofstream	out_file;
	
	checkExecute(executor);
	out_file.open((this->getTarget() + "_shrubbery").c_str());
	if (!out_file.is_open())
	{
		std::cerr << "Error: Unable to open target file" << std::endl;
		return ;
	}
	out_file << "\n\
	               ,@@@@@@@,\n\
	       ,,,.   ,@@@@@@/@@,  .oo8888o.\n\
	    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n\
	   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n\
	   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n\
	   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n\
	   `&%\\ ` /%&'    |.|        \\ '|8'\n\
	       |o|        | |         | |\n\
	       |.|        | |         | |\n\
	     \\/ ._\\//_/__/  ,\\_//___\\/.  \\_//__/_\n\
	https://asciiart.website/index.php?art=plants/trees\n\n";
	out_file.close();
	std::cout << "ASCII Trees have been planted successfully on ";
	std::cout << this->getTarget() + "_shrubbery" << std::endl;
}
