/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:57:57 by tbabou            #+#    #+#             */
/*   Updated: 2025/02/06 16:57:57 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <fstream>

void ft_replace(std::string *str, std::string searched, std::string new_string)
{
    int start_at = -1;

    start_at = (*str).find(searched);
    while (start_at >= 0)
    {
        (*str).erase(start_at, searched.size());
        (*str).insert(start_at, new_string);
        start_at = (*str).find(searched);
    }
}

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "Wrong usage : " << av[0];
        std::cout << " <filename> <s1> <s2>." << std::endl;
        return (1);
    }
    std::string input_target = av[1];
    std::string output_target = input_target + ".replace";
    std::string buffer;
    std::ifstream input_file(input_target.c_str());
    std::ofstream output_file(output_target.c_str());
    if (!input_file.is_open()) {
        std::cerr << "Error opening the input file!" << std::endl;
        return 1;
    }
    if (!output_file.is_open()) {
        std::cerr << "Error opening the output file!" << std::endl;
        input_file.close();
        return 1;
    }
    while (getline(input_file, buffer)) {
        ft_replace(&buffer, av[2], av[3]);
        output_file << buffer << std::endl;
    }
    input_file.close();
    output_file.close();
    return 0;
}
