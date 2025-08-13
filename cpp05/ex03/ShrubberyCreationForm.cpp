/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:19:27 by theaux            #+#    #+#             */
/*   Updated: 2025/08/13 11:47:19 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("Shrubbery Creation Form", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
    if (!getSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getExecuteGrade())
        throw AForm::GradeTooLowException();

    std::string filename = _target + "_shrubbery";
    std::ofstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: Could not create file " << filename << std::endl;
        return;
    }

    file << "          &&& &&  & &&\n";
    file << "      && &\\/&\\|& ()|/ @, &&\n";
    file << "      &\\/(/&/&||/& /_/)_&/_&\n";
    file << "   &() &\\/&|()|/&\\/ \'%\" & ()\n";
    file << "  &_\\_&&_\\ |& |&&/&__%_/_& &&\n";
    file << "&&   && & &| &| /& & % ()& /&&\n";
    file << " ()&_---()&\\&\\|&&-&&--%---()~\n";
    file << "     &&     \\|||\n";
    file << "             |||\n";
    file << "             |||\n";
    file << "             |||\n";
    file << "       , -=-~  .-^- _\n";
    file << std::endl;

    file.close();
    std::cout << "ASCII trees have been planted in " << filename << std::endl;
}
