/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 11:54:41 by tbabou            #+#    #+#             */
/*   Updated: 2025/08/13 12:22:46 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
    private:
    typedef AForm* (Intern::*FormConstructor)(const std::string&);
    AForm* createRobotomy(const std::string& target);
    AForm* createPresidential(const std::string& target);
    AForm* createShrubbery(const std::string& target);

    FormConstructor ConstructorForms[3];
    const char* availableForms[3];

    public:
        Intern();
        Intern(const Intern &src);
        ~Intern();

        Intern &operator=(const Intern &rhs);

        AForm *makeForm(const std::string &formType, const std::string &target);
};

#endif
