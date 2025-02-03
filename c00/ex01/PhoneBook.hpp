/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 10:37:46 by tbabou            #+#    #+#             */
/*   Updated: 2025/02/02 16:27:16 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook
{
private:
    Contact contact_list[2];
    int current_contact;
public:
    PhoneBook();
    ~PhoneBook();
    
    std::string promptText(std::string msg);
    void AddUser(void);
    void SearchUser(void);
};

#endif