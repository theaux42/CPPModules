/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:53:11 by tbabou            #+#    #+#             */
/*   Updated: 2025/05/22 16:47:26 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	// Uncomment to show that the Animal class is abstract
	
	// std::cout << "[+] Trying to create a animal instance..." << std::endl;
	// Animal *animal = new Animal();
	// std::cout << "[+] Animal created." << std::endl;
	
	const int ANIMALS_COUNT = 20;
	Animal *animals[ANIMALS_COUNT];
	
	std::cout << "[+] Creating " << ANIMALS_COUNT << " animals..." << std::endl;
	for (int i = 0; i < ANIMALS_COUNT / 2; i++)
		animals[i] = new Dog();
	for (int i = ANIMALS_COUNT / 2; i < ANIMALS_COUNT; i++)
		animals[i] = new Cat();
	std::cout << "[+] Animals created." << std::endl;
	
	std::cout << "[+] Making sounds..." << std::endl;
	for (int i = 0; i < ANIMALS_COUNT; i++)
		animals[i]->makeSound();
	std::cout << "[+] Sounds made." << std::endl;

	std::cout << "[+] Deleting animals..." << std::endl;
	for (int i = 0; i < ANIMALS_COUNT; i++)
		delete animals[i];
	std::cout << "[+] Animals deleted." << std::endl;
	return 0;
}