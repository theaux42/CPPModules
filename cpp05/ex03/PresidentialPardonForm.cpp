#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target) :
    AForm("PresidentialPardonForm", 5, 25), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) :
    AForm("PresidentialPardonForm", 5, 25), _target(src.getTarget()) { *this = src; }

PresidentialPardonForm::PresidentialPardonForm(void) :
    AForm("PresidentialPardonForm", 5, 25) , _target("default") {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) { (void)rhs; return *this; }

void PresidentialPardonForm::action(const Bureaucrat &executor) const
{
    (void)executor;
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}