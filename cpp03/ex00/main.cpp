/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theaux <theaux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:36:05 by theaux            #+#    #+#             */
/*   Updated: 2025/05/12 19:18:01 by theaux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap claptrap("Martin");
	
	// First batch of actions
	std::cout << "	[+] First batch" << std::endl;
	claptrap.attack("Matin");
	claptrap.takeDamage(5);
	claptrap.beRepaired(3);
	
	// Remove all energy points
	std::cout << "	[+] Removing all energy points" << std::endl;
	for (int i = 0; i < 9; i++)
		claptrap.beRepaired(1);
	
	// Second batch of actions without energy points
	std::cout << "	[+] Second batch" << std::endl;
	claptrap.attack("Matin");
	claptrap.takeDamage(20);
	claptrap.beRepaired(5);

	// dead ClapTrap
	std::cout << "	[+] Dead ClapTrap" << std::endl;
	claptrap.attack("Matin");
	claptrap.takeDamage(5);
	claptrap.beRepaired(3);
	
	return (0);
}