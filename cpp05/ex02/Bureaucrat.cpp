#include "Bureaucrat.hpp"

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
    if (this != &rhs)
        this->_grade = rhs._grade;
    return *this;
}

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade) : _name(name), _grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::TooHighException();
    if (grade > 150)
        throw Bureaucrat::TooLowException();
}

void    Bureaucrat::increaseGrade(void)
{
    if (this->_grade - 1 < 1)
        throw Bureaucrat::TooHighException();
    this->_grade--;
}

void    Bureaucrat::decreaseGrade(void)
{
    if (this->_grade + 1 > 150)
        throw Bureaucrat::TooLowException();
    this->_grade++;
}

void    Bureaucrat::signForm(AForm &form)
{
    try {
        form.beSigned(*this);
    }
    catch (std::exception &e)
    {
        std::cerr << this->_name << " couldn't sign the form \"" << form.getName()<< "\" because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form) const
{
    try
    {
        form.execute(*this);
        std::cout << this->_name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << this->_name << " couldn't execute the form " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& meow)
{
    os << meow.getName() << " , bureaucrat grade " << meow.getGrade() << ".";
    return os;
}
