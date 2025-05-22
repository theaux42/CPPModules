/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:51:01 by tbabou            #+#    #+#             */
/*   Updated: 2025/05/22 16:45:52 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal {
	protected:
		std::string type;
		Animal();
		Animal(const Animal &src);
	public:
		virtual ~Animal();
		Animal &operator=(const Animal &rhs);

		virtual void makeSound() const = 0;
		std::string getType() const;
};

#endif