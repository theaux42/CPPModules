/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theaux <theaux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 17:45:44 by theaux            #+#    #+#             */
/*   Updated: 2025/05/12 17:29:12 by theaux           ###   ########.fr       */
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

		// Assignment operator
		Fixed &operator=(const Fixed &rhs);	
		
		// Arithmetic operators
		float operator+(const Fixed &rhs) const;
		float operator-(const Fixed &rhs) const;
		float operator*(const Fixed &rhs) const;
		float operator/(const Fixed &rhs) const;

		// Pre-increment and Pre-decrement operators
		Fixed operator++();
		Fixed operator--();
		
		// Post-increment and Post-decrement operators
		Fixed operator++(int);
		Fixed operator--(int);

		// Comparison operators
		bool operator>(const Fixed &rhs) const;
		bool operator<(const Fixed &rhs) const;
		bool operator>=(const Fixed &rhs) const;
		bool operator<=(const Fixed &rhs) const;
		bool operator==(const Fixed &rhs) const;
		bool operator!=(const Fixed &rhs) const;

		// Min and Max functions
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
		
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