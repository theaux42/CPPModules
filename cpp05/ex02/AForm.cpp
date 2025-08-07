/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theaux <theaux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 07:18:35 by tbabou            #+#    #+#             */
/*   Updated: 2025/08/07 17:29:30 by theaux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default Form"), _isSigned(false), _signGrade(150), _executeGrade(150) {}

AForm::AForm(const std::string &name, int signGrade, int executeGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
    if (signGrade < 1 || executeGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || executeGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _executeGrade(other._executeGrade) {}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other) {
        // _name is const, so we cannot assign it
        _isSigned = other._isSigned;
        // _signGrade and _executeGrade are also const, so we cannot assign them
    }
    return *this;
}

int AForm::getExecuteGrade(void) const {
    return this->_executeGrade;
}

int AForm::getSignGrade(void) const {
    return this->_signGrade;
}

const std::string&   AForm::getName() const {
    return this->_name;
}

bool    AForm::getSigned(void) const {
    return this->_isSigned;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->_signGrade)
        throw AForm::GradeTooLowException();
    this->_isSigned = true;
}
