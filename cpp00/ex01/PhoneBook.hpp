/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 10:37:46 by tbabou            #+#    #+#             */
/*   Updated: 2025/03/17 13:25:50 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include "Contact.hpp"

class PhoneBook
{
private:
    Contact contact_list[8];
    int current_contact;
    int contact_count;
    int max_contact;
public:
    PhoneBook();
    ~PhoneBook();
    
    std::string promptText(std::string msg);
    int         AddUser(void);
    int         SearchUser(void);
    void        ShowAllUser(void);
};

#endif