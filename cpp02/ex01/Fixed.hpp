/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theaux <theaux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 17:45:44 by theaux            #+#    #+#             */
/*   Updated: 2025/05/12 17:18:04 by theaux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &src);
		Fixed(const int raw);
		Fixed(const float raw);
		~Fixed();

		Fixed &operator=(const Fixed &rhs);		

		int getRawBits(void) const;
		int toInt(void) const;
		float toFloat(void) const;
		void setRawBits(int const raw);
	private:
		int _rawBits;
		static const int _fractionalBits = 8;
};

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);

#endif