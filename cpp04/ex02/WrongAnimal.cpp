/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:24:54 by tbabou            #+#    #+#             */
/*   Updated: 2025/05/22 13:43:42 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &src) : type(src.type) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}
WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs) {
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	if (this != &rhs) {
		this->type = rhs.type;
	}
	return *this;
}

void WrongAnimal::makeSound() const {
	std::cout << "[SOUND] Wrong animal sound from : " << this->type << std::endl;
}

std::string WrongAnimal::getType() const {
	return this->type;
}