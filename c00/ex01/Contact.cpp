/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 10:34:41 by tbabou            #+#    #+#             */
/*   Updated: 2025/02/02 16:20:28 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact()
{
}

void Contact::showContact(void)
{
    std::cout << " | " << this->firstname;
    std::cout << " | " << this->lastname;
    std::cout << " | " << this->surname;
    std::cout << " | " << this->phone_number;
    std::cout << " | " << this->secret << std::endl;
}

int Contact::setValues(std::string firstname, std::string lastname,
    std::string surname, std::string phone_number, std::string secret)
{

    this->firstname = firstname;
    this->lastname = lastname;
    this->surname = surname;
    this->phone_number = phone_number;
    this->secret = secret;
    this->showContact();
    return (0);
}