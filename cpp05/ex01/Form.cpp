#include "Form.hpp"
#include "Bureaucrat.hpp"

Form &Form::operator=(const Form &rhs)
{
    if (this != &rhs)
    {
        this->_isSigned = rhs._isSigned;
        // _name, _signLevel, and _executeLevel are assumed to be const or only set in the constructor
    }
    return *this;
}

Form::Form(const std::string name, const int executeLevel, const int signLevel)
    : _name(name), _isSigned(false), _executeLevel(executeLevel), _signLevel(signLevel)
{
    if (executeLevel < 1 || signLevel < 1)
        throw Form::GradeTooHighException();
    if (executeLevel > 150 || signLevel > 150)
        throw Form::GradeTooLowException();
}

void Form::beSigned(const Bureaucrat &signer)
{
    if (this->_isSigned)
        throw Form::AlreadySignedExeception();

    if (signer.getGrade() > this->_signLevel)
        throw Form::GradeTooLowException();
    else
    {
        std::cout << signer.getName() << " signed " << this->_name << std::endl;
        this->_isSigned = true;
    }
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "The form \"" << form.getName() << "\" require level " << form.getSignLevel() << " to be signed,\n";
    os << "require level " << form.getExecuteLevel() << " to be executed and ";
    if (form.getSignStatus()) 
        os << "got signed";
    else
        os << "is not signed";
    return os;
}
