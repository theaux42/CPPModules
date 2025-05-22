/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:54:55 by tbabou            #+#    #+#             */
/*   Updated: 2025/05/22 14:16:33 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}
Dog::Dog(const Dog &src) : Animal(src) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->brain = new Brain(*src.brain);
}
Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
}
Dog &Dog::operator=(const Dog &rhs) {
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &rhs) {
		this->type = rhs.type;
		delete this->brain;
		this->brain = new Brain(*rhs.brain);
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "[SOUND] Woof" << std::endl;
}