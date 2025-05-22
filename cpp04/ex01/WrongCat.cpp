/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:25:42 by tbabou            #+#    #+#             */
/*   Updated: 2025/05/22 13:43:49 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "WrongCat default constructor called" << std::endl;
	this->type = "WrongCat";
}
WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src) {
	std::cout << "WrongCat copy constructor called" << std::endl;
}
WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}
WrongCat &WrongCat::operator=(const WrongCat &rhs) {
	std::cout << "WrongCat assignment operator called" << std::endl;
	if (this != &rhs) {
		this->type = rhs.type;
	}
	return *this;
}
void WrongCat::makeSound() const {
	std::cout << "Wrong cat sound" << std::endl;
}
