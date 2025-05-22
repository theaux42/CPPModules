/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:53:53 by tbabou            #+#    #+#             */
/*   Updated: 2025/05/22 14:16:14 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}
Cat::Cat(const Cat &src) : Animal(src) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->brain = new Brain(*src.brain);
}
Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
}
Cat &Cat::operator=(const Cat &rhs) {
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &rhs) {
		this->type = rhs.type;
		delete this->brain;
		this->brain = new Brain(*rhs.brain);
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "[SOUND] Meow" << std::endl;
}
