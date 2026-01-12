#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main(void)
{
    Intern      coffeemaker;

    AForm* first;
    AForm* second;
    AForm* third;
    AForm* forth;

    first = coffeemaker.makeForm("presidential pardon", "Pierre");
    second = coffeemaker.makeForm("shrubbery creation", "Paul");
    third = coffeemaker.makeForm("robotomy request", "Jacques");
    forth = coffeemaker.makeForm("dance logobi", "WhoIsDat");

    (void)first;
    (void)second;
    (void)third;
    (void)forth;

    return 0;
}