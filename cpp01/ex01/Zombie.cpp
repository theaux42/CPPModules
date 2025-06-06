/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:06:34 by tbabou            #+#    #+#             */
/*   Updated: 2025/02/05 21:06:34 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie():name("Zombie")
{
	return ;
}

Zombie::Zombie(std::string name):name(name)
{
	return ;
}

Zombie::~Zombie()
{
	std::cout << name << " has been killed..." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}

void	Zombie::announce(void) const
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}