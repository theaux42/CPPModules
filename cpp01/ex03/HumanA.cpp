/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:06:47 by tbabou            #+#    #+#             */
/*   Updated: 2025/02/05 21:06:47 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
}

HumanA::~HumanA(void)
{
    return ;
}

void HumanA::attack(void)
{
    std::cout << this->name;
    std::cout << " attacks with their ";
    std::cout << this->weapon.getType();
    std::cout << std::endl;
}