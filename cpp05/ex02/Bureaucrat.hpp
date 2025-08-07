/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theaux <theaux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:08:20 by tbabou            #+#    #+#             */
/*   Updated: 2025/08/07 17:29:30 by theaux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class AForm; // Forward declaration

class Bureaucrat {

	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();
		Bureaucrat&	operator=(const Bureaucrat &other);

		const std::string&	getName() const;
		int					getGrade() const;
		void 				signForm(AForm &form);
		void				executeForm(const AForm &form) const;

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

		void	incrementGrade();
		void	decrementGrade();

	private:
		std::string _name;
		static const int _minGrade = 1,
						 _maxGrade = 150;
		int _grade;

};

inline std::ostream& operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}

# endif
