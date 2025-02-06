/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 23:49:18 by tbabou            #+#    #+#             */
/*   Updated: 2025/02/06 23:49:18 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
    message_types[0] = "DEBUG";
    message_types[1] = "INFO";
    message_types[2] = "WARNING";
    message_types[3] = "ERROR";
    
    message_functions[0] = &Harl::debug;
    message_functions[1] = &Harl::info;
    message_functions[2] = &Harl::warning;
    message_functions[3] = &Harl::error;
}


Harl::~Harl(void)
{
    return ;
}

void Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now" << std::endl;
}

void Harl::complain(std::string level)
{
    for (int i = 0; i < 4; i++)
    {
        if (level == this->message_types[i])
        {
            (this->*message_functions[i])();
            return ;
        }
    }
    std::cerr << "Invalid level" << std::endl;
    return ;
}