/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 10:34:53 by tbabou            #+#    #+#             */
/*   Updated: 2025/02/02 12:38:20 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
private:
    std::string firstname;
    std::string lastname;
    std::string surname;
    std::string phone_number;
    std::string secret;
public:

    Contact(void);
    ~Contact();

    int setValues(std::string firstname, std::string lastname,
        std::string surname, std::string phone_number, std::string secret);
    void showContact(void);
};

#endif