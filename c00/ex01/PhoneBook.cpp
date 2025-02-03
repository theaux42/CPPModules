/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 10:39:30 by tbabou            #+#    #+#             */
/*   Updated: 2025/02/02 16:30:34 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
    this->current_contact = 0;
}

PhoneBook::~PhoneBook(void)
{
    
}

std::string PhoneBook::promptText(std::string msg)
{
    std::string result;

    while (1)
    {
        std::cout << msg;
        std::getline(std::cin, result);
        if (!result.empty())
            return (result);
        else
            std::cout << "It cannot be empty!" << std::endl;
    }

    return result;
}

void PhoneBook::AddUser(void)
{
    std::string firstname
    // std::string firstname, lastname, surname, phone_number, secret;
    
    firstname = promptText("First name>");
    // lastname = promptText("Last name>");
    // surname = promptText("Surname>");
    // phone_number = promptText("Phone number>");
    // secret = promptText("Secret>");
    
    if (this->current_contact == 8)  // Change from 2 to 8
        this->current_contact = 0;
    
    contact_list[this->current_contact].setValues(firstname, " ", " ", " ", " ");
    std::cout << "Contact added at position " << current_contact + 1 << std::endl;  // Add 1 for human-readable index
    this->current_contact++;
}

void PhoneBook::SearchUser(void)
{
    std::cout << "Phonebook content :" << std::endl;
    for (int i = 0; i < this->current_contact; i++)
    {
        contact_list[i].showContact();
    }
    
}

// void PhoneBook::showContact(int i)
// {
//     std::cout << std::setw(10) << i << "|";
//     std::cout << std::setw(10) << this->firstname << "|";
//     std::cout << std::setw(10) << this->lastname << "|";
//     std::cout << std::setw(10) << this->surname << std::endl;
// }