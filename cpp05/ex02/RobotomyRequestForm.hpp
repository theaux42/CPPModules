#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
    private:
        const std::string _target;
    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(const std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &src);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
        ~RobotomyRequestForm(void) {};

        const std::string getTarget(void) const { return this->_target; };
        void action(const Bureaucrat& executor) const;
};

#endif