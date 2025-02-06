/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:05:57 by tbabou            #+#    #+#             */
/*   Updated: 2025/02/05 21:05:57 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    std::cout << " -- This zombie is stored in the heap -- " << std::endl;
    Zombie *zombie1 = newZombie("Zombie1");
    zombie1->announce();
    delete zombie1;
    Zombie *zombie2 = newZombie("Zombie2");
    zombie2->announce();
    delete zombie2;

    std::cout << "-- This zombie is stored in the stack -- " << std::endl;
    randomChump("Zombie3");
    randomChump("Zombie4");

    return (0);
}