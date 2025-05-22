/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:53:11 by tbabou            #+#    #+#             */
/*   Updated: 2025/05/22 13:44:13 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void test_wrong()
{
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* i = new WrongCat();
	
	i->makeSound();
	meta->makeSound();
	delete meta;
	delete i;
}

void test_good()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
}

int main()
{
	std::cout << "====================" << std::endl;
	std::cout << "TESTING WRONG" << std::endl;
	std::cout << "====================" << std::endl;
	test_wrong();
	std::cout << "====================" << std::endl;
	std::cout << "TESTING GOOD" << std::endl;
	std::cout << "====================" << std::endl;
	test_good();
	return 0;
}