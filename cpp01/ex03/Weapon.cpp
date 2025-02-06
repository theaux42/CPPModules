/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:07:31 by tbabou            #+#    #+#             */
/*   Updated: 2025/02/05 21:07:31 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type):type(type)
{
    return ;
}

Weapon::~Weapon()
{
    return ;
}

const std::string &Weapon::getType(void) const
{
    return (type);
}

void Weapon::setType(std::string type)
{
    this->type = type;
}
