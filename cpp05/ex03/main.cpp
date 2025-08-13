/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:26:06 by tbabou            #+#    #+#             */
/*   Updated: 2025/08/13 12:11:27 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

void testFormCreation() {
    std::cout << "\n=== TESTING FORM CREATION ===" << std::endl;
    
    Intern intern;
    AForm* form1 = intern.makeForm("robotomy request", "Bender");
    AForm* form2 = intern.makeForm("presidential pardon", "Ford");
    AForm* form3 = intern.makeForm("shrubbery creation", "Garden");
    AForm* form4 = intern.makeForm("invalid form", "Nobody");
    
    if (form1) {
        std::cout << *form1 << std::endl;
        delete form1;
    }
    if (form2) {
        std::cout << *form2 << std::endl;
        delete form2;
    }
    if (form3) {
        std::cout << *form3 << std::endl;
        delete form3;
    }
    if (form4) {
        std::cout << *form4 << std::endl;
        delete form4;
    }
}

void testFormSigningAndExecution() {
    std::cout << "\n=== TESTING FORM SIGNING AND EXECUTION ===" << std::endl;
    
    try {
        Intern intern;
        Bureaucrat ceo("CEO", 1);
        Bureaucrat manager("Manager", 50);
        Bureaucrat clerk("Clerk", 145);  // Changed to 145 to allow signing shrubbery
        
        std::cout << "\nCreated bureaucrats:" << std::endl;
        std::cout << ceo << std::endl;
        std::cout << manager << std::endl;
        std::cout << clerk << std::endl;
        
        // Test Robotomy Request Form (sign: 72, exec: 45)
        std::cout << "\n--- Testing Robotomy Request Form ---" << std::endl;
        AForm* robotomy = intern.makeForm("robotomy request", "R2D2");
        if (robotomy) {
            std::cout << *robotomy << std::endl;
            
            // Test signing with different grades
            manager.signForm(*robotomy);  // Should work (grade 50 < 72)
            ceo.executeForm(*robotomy);   // Should work (grade 1 < 45)
            
            delete robotomy;
        }
        
        // Test Presidential Pardon Form (sign: 25, exec: 5)
        std::cout << "\n--- Testing Presidential Pardon Form ---" << std::endl;
        AForm* pardon = intern.makeForm("presidential pardon", "Arthur Dent");
        if (pardon) {
            std::cout << *pardon << std::endl;
            
            ceo.signForm(*pardon);      // Should work (grade 1 < 25)
            ceo.executeForm(*pardon);   // Should work (grade 1 < 5)
            
            delete pardon;
        }
        
        // Test Shrubbery Creation Form (sign: 145, exec: 137)
        std::cout << "\n--- Testing Shrubbery Creation Form ---" << std::endl;
        AForm* shrubbery = intern.makeForm("shrubbery creation", "MyGarden");
        if (shrubbery) {
            std::cout << *shrubbery << std::endl;
            
            clerk.signForm(*shrubbery);   // Should work (grade 145 = 145)
            manager.executeForm(*shrubbery); // Should work (grade 50 < 137)
            
            delete shrubbery;
        }
        
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testErrorCases() {
    std::cout << "\n=== TESTING ERROR CASES ===" << std::endl;
    
    try {
        Intern intern;
        Bureaucrat lowLevel("LowLevel", 150);
        
        // Test with form that requires high grade to sign
        AForm* pardon = intern.makeForm("presidential pardon", "Criminal");
        if (pardon) {
            std::cout << "\nTrying to sign presidential pardon with low-level bureaucrat:" << std::endl;
            lowLevel.signForm(*pardon);  // Should fail
            
            std::cout << "\nTrying to execute unsigned form:" << std::endl;
            lowLevel.executeForm(*pardon); // Should fail (not signed + low grade)
            
            delete pardon;
        }
        
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testInternCopying() {
    std::cout << "\n=== TESTING INTERN COPYING ===" << std::endl;
    
    Intern intern1;
    Intern intern2(intern1);  // Copy constructor
    Intern intern3;
    intern3 = intern1;        // Assignment operator
    
    std::cout << "Testing if copied interns work properly:" << std::endl;
    AForm* form1 = intern1.makeForm("robotomy request", "Original");
    AForm* form2 = intern2.makeForm("robotomy request", "Copy");
    AForm* form3 = intern3.makeForm("robotomy request", "Assigned");
    
    if (form1) delete form1;
    if (form2) delete form2;
    if (form3) delete form3;
}

int main(void)
{
    std::cout << "==================================" << std::endl;
    std::cout << "    COMPREHENSIVE FORM TESTS     " << std::endl;
    std::cout << "==================================" << std::endl;
    
    testFormCreation();
    testFormSigningAndExecution();
    testErrorCases();
    testInternCopying();
    
    std::cout << "\n==================================" << std::endl;
    std::cout << "         TESTS COMPLETE          " << std::endl;
    std::cout << "==================================" << std::endl;
    
    return (0);
}
