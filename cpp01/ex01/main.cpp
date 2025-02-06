/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:06:31 by tbabou            #+#    #+#             */
/*   Updated: 2025/02/05 21:06:31 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie *zombies = zombieHorde(5, "Zombie");
    for (int i = 0; i < 5; i++)
    {
        zombies[i].announce();
    }
    delete[] zombies;
    return (0);
}