/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 10:36:26 by tbabou            #+#    #+#             */
/*   Updated: 2025/02/07 00:29:23 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

// Currenlty have invalid memory usage when a string is too long
// and after SEARCH command, it segfaults.

int main(void)
{
    PhoneBook repertory;
    
    std::cout << "Welcome to the phonebook!" << std::endl;
    std::string command;

    while (1)
    {
        std::cout << "Enter a command (ADD, SEARCH or EXIT): ";
        command = repertory.promptText("> ");
        if (command == "EXIT")
            break;
        else if (command == "ADD")
            repertory.AddUser();
        else if (command == "SEARCH")
            repertory.SearchUser();
        else
            std::cout << "Invalid command. Please enter ADD, SEARCH or EXIT." << std::endl;
    }
    
}
