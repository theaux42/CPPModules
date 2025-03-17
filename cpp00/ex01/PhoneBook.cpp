/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 10:39:30 by tbabou            #+#    #+#             */
/*   Updated: 2025/03/17 13:27:19 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
    this->current_contact = 0;
    this->max_contact = 8;
    this->contact_count = 0;
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
            if (std::cin.eof())
                return (result);
            else
                std::cout << "It cannot be empty!" << std::endl;
    }

    return result;
}

int PhoneBook::AddUser(void)
{
    std::string firstname, lastname, surname, phone_number, secret;
    
    firstname = promptText("First name>");
    if (std::cin.eof()) return (1);
    lastname = promptText("Last name>");
    if (std::cin.eof()) return (1);
    surname = promptText("Surname>");
    if (std::cin.eof()) return (1);
    phone_number = promptText("Phone number>");
    if (std::cin.eof()) return (1);
    secret = promptText("Secret>");
    if (std::cin.eof()) return (1);
    contact_list[this->current_contact % this->max_contact].setValues(firstname, lastname, surname, phone_number, secret);
    this->current_contact++;
    return (0);
}

void PhoneBook::ShowAllUser(void)
{
    int printed;
    
    printed = 0;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << " Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    for (int i = 0; i < this->max_contact; i++)
    {
        if (!this->contact_list[i].isEmpty())
        {
            std::cout << "     " << i + 1 << "|";
            this->contact_list[i].showContact();
            printed++;
        }
    }
    for (int i = printed; i < this->max_contact; i++)
        std::cout << "     " << i + 1 << "|          |          |          |" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    if (printed == 0)
        std::cout << "No contact available." << std::endl;
}

int PhoneBook::SearchUser(void)
{
    int searched;
    std::string index;

    searched = 0;
    PhoneBook::ShowAllUser();
    index = promptText("Who are you searching for > ");
    if (std::cin.eof()) return (1) ;
    if (std::isdigit(index[0]) == 0)
    {
        std::cout << "Invalid index." << std::endl;
        return (0);
    }
    searched = std::atoi(index.c_str());
    if (searched < 0 || searched > this->max_contact)
    {
        std::cout << "Invalid index." << std::endl;
        return (0);
    }
    if (!this->contact_list[searched - 1].isEmpty())
    {
        this->contact_list[searched - 1].showFullContact(searched);
        return (0);
    }
    else
        std::cout << "This contact seems empty." << std::endl;
    return (0);
}
