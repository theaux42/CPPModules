/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 23:46:12 by tbabou            #+#    #+#             */
/*   Updated: 2025/02/06 23:46:12 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Harl 
{
    private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void); 

    std::string message_types[4];
    void (Harl::*message_functions[4])(void);

    public:
    Harl();
    ~Harl();
    void complain(std::string level); 
};