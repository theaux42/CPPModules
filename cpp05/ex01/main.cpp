/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:26:06 by tbabou            #+#    #+#             */
/*   Updated: 2025/07/23 17:51:28 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat bureaucrat("John Doe", 50);
	Bureaucrat bureaucrat2("Jane Doe", 1);
	Bureaucrat bureaucrat3("Jim Doe", 150);


	std::cout << "[+] Current state of bureaucrats:" << std::endl;
	std::cout << bureaucrat << std::endl;
	std::cout << bureaucrat2 << std::endl;
	std::cout << bureaucrat3 << std::endl;

	std::cout << "[+] Incrementing first bureaucrat grade:" << std::endl;
	try {
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "[+] Incrementing second bureaucrat grade:" << std::endl;
	try {
		bureaucrat2.incrementGrade();
		std::cout << bureaucrat2 << std::endl;
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "[+] Decrementing third bureaucrat grade:" << std::endl;
	try {
		bureaucrat3.decrementGrade();
		std::cout << bureaucrat3 << std::endl;
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "[+] Create bureaucrats with wrong grade" << std::endl;
	try {
		Bureaucrat bureaucrat4("Invalid Bureaucrat", 0);
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat bureaucrat5("Invalid Bureaucrat", 151);
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}

	// Create a bureaucrat with invalid grade and without exception
	// handling (this will cause a crash)
	// Bureaucrat bureaucrat6("Invalid Bureaucrat", 0);

	return 0;
}
