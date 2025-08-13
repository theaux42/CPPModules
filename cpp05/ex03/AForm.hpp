/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theaux <theaux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 07:16:16 by tbabou            #+#    #+#             */
/*   Updated: 2025/08/07 17:29:30 by theaux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

class Bureaucrat; // Forward declaration

class AForm
{
    private:
        std::string const _name;
        bool              _isSigned;
        int const         _signGrade,
                          _executeGrade;

    protected:
        // Protected constructors to make class abstract
        AForm();
        AForm(const std::string &name, int signGrade, int executeGrade);
        AForm(const AForm &other);

    public:
        // Constructors and Destructor
        virtual ~AForm();

        // Getters
        const std::string&  getName() const;
        int                 getSignGrade() const;
        int                 getExecuteGrade() const;
        bool                getSigned() const;

        // Member functions
        void                beSigned(const Bureaucrat &bureaucrat);
        virtual void        execute(const Bureaucrat &executor) const = 0; // Pure virtual function

        // Assignment operator
        AForm &operator=(const AForm &other);

        // Exception classes
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw() {
                    return "\033[0;31m Grade is too high!\033[0m";
                }
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw() {
                    return "\033[0;31m Grade is too low!\033[0m";
                }
        };
        class FormNotSignedException : public std::exception {
            public:
                const char* what() const throw() {
                    return "\033[0;31m Form is not signed!\033[0m";
                }
        };

};

inline std::ostream& operator<<(std::ostream &out, const AForm &form) {
	out << "Form named '" << form.getName() << "' require level " << form.getSignGrade()
     << " to sign and level "<< form.getExecuteGrade() <<" to execute. the form is currently "
    << (form.getSigned() ? "Signed" : "Not signed");
	return out;
}

#endif
