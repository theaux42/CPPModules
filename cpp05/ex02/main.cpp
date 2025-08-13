/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:26:06 by tbabou            #+#    #+#             */
/*   Updated: 2025/08/12 18:35:00 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main(void)
{
	std::cout << "=== EXERCISE 02: CONCRETE FORMS TESTS ===" << std::endl;

	// Test 1: Create bureaucrats with different grades
	std::cout << "\n[+] Creating bureaucrats with different grades:" << std::endl;
	Bureaucrat lowGrade("John Doe", 150);
	Bureaucrat midGrade("Jane Doe", 50);
	Bureaucrat highGrade("Jim Doe", 1);
	Bureaucrat ceoGrade("CEO", 5);

	std::cout << lowGrade << std::endl;
	std::cout << midGrade << std::endl;
	std::cout << highGrade << std::endl;
	std::cout << ceoGrade << std::endl;

	// Test 2: Create concrete forms
	std::cout << "\n[+] Creating concrete forms:" << std::endl;
	ShrubberyCreationForm shrubbery("home");
	RobotomyRequestForm robotomy("Marvin");
	PresidentialPardonForm pardon("Arthur Dent");

	std::cout << shrubbery << std::endl;
	std::cout << robotomy << std::endl;
	std::cout << pardon << std::endl;

	// Test 3: Test ShrubberyCreationForm
	std::cout << "\n[+] Testing ShrubberyCreationForm:" << std::endl;
	std::cout << "Trying to execute unsigned form:" << std::endl;
	try {
		shrubbery.execute(midGrade);
	} catch (const std::exception &e) {
		std::cerr << "Expected error: " << e.what() << std::endl;
	}

	std::cout << "\nSigning form with sufficient grade:" << std::endl;
	midGrade.signForm(shrubbery);

	std::cout << "\nExecuting signed form:" << std::endl;
	midGrade.executeForm(shrubbery);

	std::cout << "\nTrying to execute with insufficient grade:" << std::endl;
	lowGrade.executeForm(shrubbery);

	// Test 4: Test RobotomyRequestForm
	std::cout << "\n[+] Testing RobotomyRequestForm:" << std::endl;
	midGrade.signForm(robotomy);
	std::cout << "Executing robotomy (multiple attempts to see randomness):" << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << "Attempt " << (i + 1) << ": ";
		midGrade.executeForm(robotomy);
	}

	// Test 5: Test PresidentialPardonForm
	std::cout << "\n[+] Testing PresidentialPardonForm:" << std::endl;
	std::cout << "Trying to sign with insufficient grade:" << std::endl;
	midGrade.signForm(pardon);

	std::cout << "\nSigning with sufficient grade:" << std::endl;
	highGrade.signForm(pardon);

	std::cout << "\nTrying to execute with insufficient grade:" << std::endl;
	midGrade.executeForm(pardon);

	std::cout << "\nExecuting with sufficient grade:" << std::endl;
	ceoGrade.executeForm(pardon);

	// Test 6: Test polymorphism
	std::cout << "\n[+] Testing polymorphism:" << std::endl;
	AForm* forms[] = {
		new ShrubberyCreationForm("garden"),
		new RobotomyRequestForm("Bender"),
		new PresidentialPardonForm("Ford Prefect")
	};

	for (int i = 0; i < 3; i++) {
		std::cout << "\nForm " << (i + 1) << ": " << *forms[i] << std::endl;
		highGrade.signForm(*forms[i]);
		highGrade.executeForm(*forms[i]);
		delete forms[i];
	}

	// Test 7: Edge cases
	std::cout << "\n[+] Testing edge cases:" << std::endl;

	// Test exact required grades
	std::cout << "\nTesting exact required grades for ShrubberyCreationForm:" << std::endl;
	try {
		Bureaucrat signGrade("Sign Grade", 145);
		Bureaucrat execGrade("Exec Grade", 137);
		ShrubberyCreationForm exactTest("exact");

		signGrade.signForm(exactTest);
		execGrade.executeForm(exactTest);
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== All tests completed ===" << std::endl;
	return 0;
}
