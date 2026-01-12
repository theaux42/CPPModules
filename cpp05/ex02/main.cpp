#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
    Bureaucrat First("Martin", 1);
    Bureaucrat Second; // default to "George" 150

    RobotomyRequestForm first("Pierre");
    ShrubberyCreationForm second("Paul");
    PresidentialPardonForm third("Jacques");

    Second.signForm(first); // can't sign it
    
    First.signForm(first);
    First.signForm(second);
    First.signForm(third);

    Second.executeForm(first);

    First.executeForm(first);
    First.executeForm(second);
    First.executeForm(third);



    return 0;
}