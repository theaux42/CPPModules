/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:52:08 by tbabou            #+#    #+#             */
/*   Updated: 2025/05/22 13:44:42 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Animal default constructor called" << std::endl;
}
Animal::Animal(const Animal &src) : type(src.type) {
	std::cout << "Animal copy constructor called" << std::endl;
}
Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}
Animal &Animal::operator=(const Animal &rhs) {
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &rhs) {
		this->type = rhs.type;
	}
	return *this;
}

void Animal::makeSound() const {
	std::cout << "[SOUND] Default Sound" << std::endl;
}
std::string Animal::getType() const {
	return this->type;
}
