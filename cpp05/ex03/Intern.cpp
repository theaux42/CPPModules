#include "Intern.hpp"
#include <cstring>

Intern::Intern() {
    ConstructorForms[0] = &Intern::createRobotomy;
    ConstructorForms[1] = &Intern::createPresidential;
    ConstructorForms[2] = &Intern::createShrubbery;

    availableForms[0] = "robotomy request";
    availableForms[1] = "presidential pardon";
    availableForms[2] = "shrubbery creation";
}

Intern::Intern(const Intern &src) {
    ConstructorForms[0] = &Intern::createRobotomy;
    ConstructorForms[1] = &Intern::createPresidential;
    ConstructorForms[2] = &Intern::createShrubbery;

    availableForms[0] = "robotomy request";
    availableForms[1] = "presidential pardon";
    availableForms[2] = "shrubbery creation";
    (void)src; // Suppress unused parameter warning
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &rhs) {
    if (this != &rhs) {
        ConstructorForms[0] = &Intern::createRobotomy;
        ConstructorForms[1] = &Intern::createPresidential;
        ConstructorForms[2] = &Intern::createShrubbery;

        availableForms[0] = "robotomy request";
        availableForms[1] = "presidential pardon";
        availableForms[2] = "shrubbery creation";
    }
    return *this;
}

AForm* Intern::createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}
AForm* Intern::createPresidential(const std::string& target) {
    return new PresidentialPardonForm(target);
}
AForm* Intern::createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(const std::string &formType, const std::string &target) {
    for (int i = 0; i < 3; i++) {
        if (strcmp(availableForms[i], formType.c_str()) == 0) {
            std::cout << "Intern creates " << availableForms[i] << std::endl;
            return (this->*ConstructorForms[i])(target);
        }
    }
    std::cout << "Cannot find the right type :(" << std::endl;
    return NULL;
}
