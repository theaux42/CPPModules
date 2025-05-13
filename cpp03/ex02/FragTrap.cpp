/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theaux <theaux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:39:14 by theaux            #+#    #+#             */
/*   Updated: 2025/05/13 09:43:18 by theaux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default") {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap Default constructor called" << std::endl;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap Constructor with name called" << std::endl;
}
FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src) {
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = src;
}
FragTrap::~FragTrap() {
	std::cout << "FragTrap Destructor called" << std::endl;
}
FragTrap &FragTrap::operator=(const FragTrap &rhs) {
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return *this;
}

void FragTrap::attack(const std::string &target)
{
	if (_hitPoints == 0 || _energyPoints == 0) {
		std::cout << "FragTrap " << _name << " has no energy or hit points left to attack!" << std::endl;
		return;
	}
	std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}

void FragTrap::highFivesGuys(void) {
	if (_hitPoints == 0 || _energyPoints == 0) {
		std::cout << "FragTrap " << _name << " has no energy or hit points left to high five!" << std::endl;
		return;
	}
	std::cout << "FragTrap " << _name << " is requesting a high five!" << std::endl;
}
