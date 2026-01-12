#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm {
    private:
        const std::string   _name;
        bool                _isSigned;
        const unsigned int  _executeLevel;
        const unsigned int  _signLevel;
        
    protected:
        AForm(const std::string name, const int executeLevel, const int signLevel);
        AForm() : _name("Contract"), _isSigned(false), _executeLevel(150), _signLevel(150) {};
        virtual void        action(Bureaucrat const & executor) const = 0;
        
    public:
        AForm(const AForm &src) : _name(src._name), _isSigned(src._isSigned), _executeLevel(src._executeLevel), _signLevel(src._signLevel) {};
        AForm &operator=(const AForm &rhs);
        ~AForm() {};
        
        const std::string   getName(void) const {return this->_name;};
        bool                getSignStatus(void) const {return this->_isSigned;};
        int                 getExecuteLevel(void) const {return this->_executeLevel;};
        int                 getSignLevel(void) const {return this->_signLevel;};
        
        void                beSigned(const Bureaucrat &signer);
        void                execute(const Bureaucrat& executor) const;
        

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

        class NotSignedException : public std::exception {
            const char * what() const throw() {
                return "The form cannot be executed since it's not signed.";
            }
        };


};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif