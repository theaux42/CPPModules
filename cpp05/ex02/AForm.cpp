#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm &AForm::operator=(const AForm &rhs)
{
    if (this != &rhs)
    {
        this->_isSigned = rhs._isSigned;
        // _name, _signLevel, and _executeLevel are assumed to be const or only set in the constructor
    }
    return *this;
}

AForm::AForm(const std::string name, const int executeLevel, const int signLevel)
    : _name(name), _isSigned(false), _executeLevel(executeLevel), _signLevel(signLevel)
{
    if (executeLevel < 1 || signLevel < 1)
        throw AForm::GradeTooHighException();
    if (executeLevel > 150 || signLevel > 150)
        throw AForm::GradeTooLowException();
}

void AForm::beSigned(const Bureaucrat &signer)
{
    if (this->_isSigned)
        throw AForm::AlreadySignedExeception();

    if (signer.getGrade() > this->_signLevel)
        throw AForm::GradeTooLowException();
    else
    {
        std::cout << signer.getName() << " signed " << this->_name << std::endl;
        this->_isSigned = true;
    }
}

void AForm::execute(Bureaucrat const &executor) const
{
    if (!this->_isSigned)
        throw AForm::NotSignedException();
    if (executor.getGrade() > this->_executeLevel)
        throw AForm::GradeTooLowException();
    this->action(executor);
}

std::ostream &operator<<(std::ostream &os, const AForm &AForm)
{
    os << "The AForm \"" << AForm.getName() << "\" require level " << AForm.getSignLevel() << " to be signed,\n";
    os << "require level " << AForm.getExecuteLevel() << " to be executed and ";
    if (AForm.getSignStatus()) 
        os << "got signed";
    else
        os << "is not signed";
    return os;
}
