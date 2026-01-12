#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form {
    private:
        const std::string   _name;
        bool                _isSigned;
        const unsigned int  _executeLevel;
        const unsigned int  _signLevel;

    public:
        Form &operator=(const Form &rhs);
        Form() : _name("Contract"), _isSigned(false), _executeLevel(150), _signLevel(150) {};
        Form(const Form &src) : _name(src._name), _isSigned(src._isSigned), _executeLevel(src._executeLevel), _signLevel(src._signLevel) {};
        ~Form() {};
        Form(const std::string name, const int executeLevel, const int signLevel);

        const std::string   getName(void) const {return this->_name;};
        bool                getSignStatus(void) const {return this->_isSigned;};
        int                 getExecuteLevel(void) const {return this->_executeLevel;};
        int                 getSignLevel(void) const {return this->_signLevel;};

        void                beSigned(const Bureaucrat &signer);

        class GradeTooHighException : public std::exception {
            const char * what() const throw() {
                return "The Grade is too high.";
            }
        };

        class GradeTooLowException : public std::exception {
            const char * what() const throw() {
                return "The Grade is too low.";
            }
        };

        class AlreadySignedExeception : public std::exception {
            const char * what() const throw() {
                return "The form is already signed";
            }
        };


};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif