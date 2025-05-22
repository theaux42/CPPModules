/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:22:08 by tbabou            #+#    #+#             */
/*   Updated: 2025/05/22 17:37:30 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
	std::cout << "[ Bureaucrat default constructor called ]" << std::endl;
}
// Parameterized constructor
Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) {
	std::cout << "[ Bureaucrat constructor called ]" << std::endl;
	if (grade < _minGrade)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > _maxGrade)
		throw Bureaucrat::GradeTooLowException();
}
// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {
	std::cout << "[ Bureaucrat copy constructor called ]" << std::endl;
}

// Destructor
Bureaucrat::~Bureaucrat() {
	std::cout << "[ Bureaucrat destructor called ]" << std::endl;
}

// Assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {
	std::cout << "[ Bureaucrat assignment operator called ]" << std::endl;
	if (this != &other) {
		this->_grade = other._grade;
		this->_name = other._name;
	}
	return *this;
}

// Getter

const std::string& Bureaucrat::getName() const {
	return this->_name;
}
int Bureaucrat::getGrade() const {
	return this->_grade;
}

// Increment and decrement grade
void Bureaucrat::incrementGrade() {
	if (this->_grade <= _minGrade)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade() {
	if (this->_grade >= _maxGrade)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

