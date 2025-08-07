/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theaux <theaux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:26:06 by tbabou            #+#    #+#             */
/*   Updated: 2025/07/25 14:17:50 by theaux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << "=== EXERCISE 01: FORM TESTS ===" << std::endl;

	// Test 1: Create bureaucrats with different grades
	std::cout << "\n[+] Creating bureaucrats with different grades:" << std::endl;
	Bureaucrat lowGrade("John Doe", 150);
	Bureaucrat midGrade("Jane Doe", 50);
	Bureaucrat highGrade("Jim Doe", 1);

	std::cout << lowGrade << std::endl;
	std::cout << midGrade << std::endl;
	std::cout << highGrade << std::endl;

	// Test 2: Create forms with different grade requirements
	std::cout << "\n[+] Creating forms with different grade requirements:" << std::endl;
	try {
		Form easyForm("Easy Form", 100, 50);
		Form hardForm("Hard Form", 10, 5);
		Form impossibleForm("Impossible Form", 1, 1);

		std::cout << easyForm << std::endl;
		std::cout << hardForm << std::endl;
		std::cout << impossibleForm << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Error creating forms: " << e.what() << std::endl;
	}

	// Test 3: Test form creation with invalid grades
	std::cout << "\n[+] Testing form creation with invalid grades:" << std::endl;
	try {
		Form invalidForm1("Invalid Form 1", 0, 50);
	} catch (const std::exception &e) {
		std::cerr << "Expected error: " << e.what() << std::endl;
	}

	try {
		Form invalidForm2("Invalid Form 2", 50, 151);
	} catch (const std::exception &e) {
		std::cerr << "Expected error: " << e.what() << std::endl;
	}

	// Test 4: Test signing forms with different bureaucrats
	std::cout << "\n[+] Testing form signing:" << std::endl;
	Form testForm("Test Form", 75, 25);
	std::cout << "Initial form state: " << testForm << std::endl;

	// Low grade bureaucrat tries to sign (should fail)
	std::cout << "\nLow grade bureaucrat tries to sign:" << std::endl;
	lowGrade.signForm(testForm);
	std::cout << "Form state after attempt: " << testForm << std::endl;

	// Mid grade bureaucrat tries to sign (should succeed)
	std::cout << "\nMid grade bureaucrat tries to sign:" << std::endl;
	midGrade.signForm(testForm);
	std::cout << "Form state after signing: " << testForm << std::endl;

	// High grade bureaucrat tries to sign already signed form
	std::cout << "\nHigh grade bureaucrat tries to sign already signed form:" << std::endl;
	highGrade.signForm(testForm);

	// Test 5: Test direct beSigned method
	std::cout << "\n[+] Testing direct beSigned method:" << std::endl;
	Form directForm("Direct Form", 30, 20);
	std::cout << "Initial form state: " << directForm << std::endl;

	try {
		std::cout << "Trying to sign with low grade bureaucrat directly:" << std::endl;
		directForm.beSigned(lowGrade);
	} catch (const std::exception &e) {
		std::cerr << "Expected error: " << e.what() << std::endl;
	}

	try {
		std::cout << "Trying to sign with high grade bureaucrat directly:" << std::endl;
		directForm.beSigned(highGrade);
		std::cout << "Form signed successfully!" << std::endl;
		std::cout << "Form state: " << directForm << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Unexpected error: " << e.what() << std::endl;
	}

	// Test 6: Test edge cases
	std::cout << "\n[+] Testing edge cases:" << std::endl;
	Form edgeForm("Edge Form", 50, 25);
	Bureaucrat exactGrade("Exact Grade", 50);

	std::cout << "Bureaucrat with exact required grade:" << std::endl;
	std::cout << exactGrade << std::endl;
	std::cout << edgeForm << std::endl;
	exactGrade.signForm(edgeForm);

	return 0;
}
