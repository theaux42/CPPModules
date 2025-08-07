/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theaux <theaux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 07:16:16 by tbabou            #+#    #+#             */
/*   Updated: 2025/07/25 14:01:13 by theaux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat; // Forward declaration

class Form
{
    private:
        std::string const _name;
        bool              _isSigned;
        int const         _signGrade,
                          _executeGrade;

    public:
    // Constructors and Destructor
        Form();
        Form(const std::string &name, int signGrade, int executeGrade);
        Form(const Form &other);
        ~Form();

        const std::string&  getName() const;
        int                 getSignGrade() const;
        int                 getExecuteGrade() const;
        bool                getSigned() const;
        void                beSigned(const Bureaucrat &bureaucrat);

        Form &operator=(const Form &other);

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

};

inline std::ostream& operator<<(std::ostream &out, const Form &form) {
	out << "Form named '" << form.getName() << "' require level " << form.getSignGrade()
     << " to sign and level "<< form.getExecuteGrade() <<" to execute. the form is currently "
    << (form.getSigned() ? "Signed" : "Not signed");
	return out;
}

#endif
