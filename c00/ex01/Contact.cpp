/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 10:34:41 by tbabou            #+#    #+#             */
/*   Updated: 2025/02/05 09:24:07 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact()
{
}

std::string truncateString(const std::string &str)
{
    int i = 0;
    
    if (str.length() == 10)
        return str;
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    if (str.length() < 10)
    {
        while (i < 10 - (int)str.length())
        {
            std::cout << " ";
            i++;
        }
    }
    return str;
}

void Contact::showContact(void)
{
    std::cout << truncateString(this->firstname) << "|";
    std::cout << truncateString(this->lastname) << "|";
    std::cout << truncateString(this->surname) << "|" << std::endl;
}

void Contact::showFullContact(int index)
{
    std::cout << "Contact ID: " << index << std::endl;
    std::cout << "First name: " << this->firstname << std::endl;
    std::cout << "Last name: " << this->lastname << std::endl;
    std::cout << "Surname: " << this->surname << std::endl;
    std::cout << "Phone number: " << this->phone_number << std::endl;
    std::cout << "Secret: " << this->secret << std::endl;
}
void Contact::setValues(std::string firstname, std::string lastname,
    std::string surname, std::string phone_number, std::string secret)
{
    this->firstname = firstname;
    this->lastname = lastname;
    this->surname = surname;
    this->phone_number = phone_number;
    this->secret = secret;
}

bool Contact::isEmpty(void)
{
    if (this->firstname.empty() && this->lastname.empty() &&
        this->surname.empty() && this->phone_number.empty() &&
        this->secret.empty())
        return (true);
    return (false);
}