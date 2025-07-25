/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 07:18:35 by tbabou            #+#    #+#             */
/*   Updated: 2025/07/23 20:26:16 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default Form"), _signGrade(150), _executeGrade(150) {}

Form::Form(const std::string &name, int signGrade, int executeGrade)
    : _name(name), _signGrade(signGrade), _executeGrade(executeGrade) {
    if (signGrade < 1 || executeGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || executeGrade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &other)
    : _name(other._name), _isSigned(other._isSigned),
      _signGrade(other._signGrade), _executeGrade(other._executeGrade) {}

Form::~Form() {}

Form &Form::operator=(const Form &other) {
    if (this != &other) {
        // _name is const, so we cannot assign it
        _isSigned = other._isSigned;
        // _signGrade and _executeGrade are also const, so we cannot assign them
    }
    return *this;
}

const int Form::getExecuteGrade(void) const {
    return this->_executeGrade;
}

const int   Form::getSignGrade(void) const {
    return this->_signGrade;
}

const std::string&   Form::getName() const {
    return this->_name;
}

bool    Form::getSigned(void) const {
    return this->_isSigned;
}
