/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 10:36:26 by tbabou            #+#    #+#             */
/*   Updated: 2025/03/17 13:27:41 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook repertory;
    
    std::cout << "Welcome to the phonebook!" << std::endl;
    std::string command;

    while (1)
    {
        std::cout << "Enter a command (ADD, SEARCH or EXIT): ";
        command = repertory.promptText("> ");
        if (std::cin.eof())
            break;
        if (command == "EXIT")
            break;
        else if (command == "ADD")
        {
            if (repertory.AddUser())
            {
                std::cout << "An error occured. Exiting..." << std::endl;
                break;
            }
        }
        else if (command == "SEARCH")
        {
            if (repertory.SearchUser())
            {
                std::cout << "An error occured. Exiting..." << std::endl;
                break;
            }
        }
        else
            std::cout << "Invalid command. Please enter ADD, SEARCH or EXIT." << std::endl;
    }
    
}
