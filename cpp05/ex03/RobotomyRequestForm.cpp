#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target) :
    AForm("RobotomyRequestForm", 45, 72), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) :
    AForm("RobotomyRequestForm", 45, 72), _target(src.getTarget()) { *this = src; }

RobotomyRequestForm::RobotomyRequestForm(void) :
    AForm("RobotomyRequestForm", 45, 72) , _target("default") {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) { (void)rhs; return *this; }

void RobotomyRequestForm::action(const Bureaucrat &executor) const
{
    (void)executor;
    std::cout << "*** DRILLING NOOOOISE ***" << std::endl;
    srand(time(NULL));
    if (rand() % 100 > 50) {
        std::cout << this->_target << " has been succesfully robotomised." << std::endl;
    } else {
        std::cout << this->_target << " escaped and made the robotomisation failed." << std::endl;
    }
}