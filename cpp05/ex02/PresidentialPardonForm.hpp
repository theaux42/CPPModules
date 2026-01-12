#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        const std::string _target;
    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(const std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &src);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
        ~PresidentialPardonForm(void) {};

        const std::string getTarget(void) const { return this->_target; };
        void action(const Bureaucrat& executor) const;
};

#endif