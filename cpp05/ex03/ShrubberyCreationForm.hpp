#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <fstream>

class ShrubberyCreationForm : public AForm
{
    private:
        const std::string _target;
    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(const std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &src);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
        ~ShrubberyCreationForm(void) {};

        const std::string getTarget(void) const { return this->_target; };
        void action(const Bureaucrat& executor) const;
};

#endif