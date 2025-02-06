/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:06:27 by tbabou            #+#    #+#             */
/*   Updated: 2025/02/05 21:06:27 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
    // Initisalisation of the string
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;


    // Display the address of the string, stringPTR and stringREF
    std::cout << "Addresses:" << std::endl;
    std::cout << "  Address in memory of the string: " << &str << std::endl;
    std::cout << "  Address in memory of the stringPTR: " << stringPTR << std::endl;
    std::cout << "  Address in memory of the stringREF: " << &stringREF << std::endl;

    // Display the string, stringPTR and stringREF
    std::cout << "Content:" << std::endl;
    std::cout << "  String: " << str << std::endl;
    std::cout << "  StringPTR: " << *stringPTR << std::endl;
    std::cout << "  StringREF: " << stringREF << std::endl;
    return (0);
}
