#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class Bureaucrat 
{
    private:
        const std::string   _name;
        unsigned int        _grade;
    public:
        Bureaucrat() : _name("George"), _grade(150) {};
        Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade) {};
        Bureaucrat &operator=(const Bureaucrat &rhs);
        ~Bureaucrat() {};
        Bureaucrat(const std::string name, unsigned int grade);

        void                increaseGrade(void);
        void                decreaseGrade(void);
        void                signForm(AForm &form);
        void                executeForm(AForm const & form) const;

        const std::string   getName(void) const { return this->_name; };
        unsigned int        getGrade(void) const { return this->_grade; };

        class TooHighException : public std::exception {
            const char* what() const throw() {
                return "The grade is too high.";
            }
        };

        class TooLowException : public std::exception {
            public:
            const char* what() const throw() {
                return "The grade is too low";
            }
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& meow);

#endif