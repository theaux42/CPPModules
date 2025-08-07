/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_robotomy.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theaux <theaux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:30:00 by theaux            #+#    #+#             */
/*   Updated: 2025/08/07 17:29:30 by theaux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	std::cout << "=== ROBOTOMY REQUEST FORM TEST ===" << std::endl;

	// Create a bureaucrat with high enough grade to execute robotomy
	Bureaucrat robotomyExpert("Robotomy Expert", 40);
	std::cout << robotomyExpert << std::endl;

	// Create robotomy form
	RobotomyRequestForm robotomy("Marvin the Paranoid Android");
	std::cout << robotomy << std::endl;

	// Sign the form
	std::cout << "\nSigning form:" << std::endl;
	robotomyExpert.signForm(robotomy);

	// Execute multiple times to see the randomness
	std::cout << "\nExecuting robotomy multiple times to see randomness:" << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cout << "Attempt " << (i + 1) << ": ";
		robotomyExpert.executeForm(robotomy);
	}

	return 0;
}
