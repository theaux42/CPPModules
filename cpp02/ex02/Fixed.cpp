/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theaux <theaux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 17:46:19 by theaux            #+#    #+#             */
/*   Updated: 2025/05/12 17:43:50 by theaux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {}
Fixed::~Fixed() {}

Fixed::Fixed(const Fixed &src) {
	*this = src;
}

Fixed::Fixed(const int raw) {
	_rawBits = raw << _fractionalBits;
}

Fixed::Fixed(const float raw) {
	_rawBits = roundf(raw * (1 << _fractionalBits));
}

int Fixed::toInt() const {
	return this->_rawBits >> _fractionalBits;
}

float Fixed::toFloat() const {
	return (float)_rawBits / (1 << _fractionalBits);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed) {
	o << fixed.toFloat();
	return (o);
}

Fixed &Fixed::operator=(const Fixed &rhs) {
	if (this != &rhs)
		this->_rawBits = rhs.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const {
	return this->_rawBits;
}

void Fixed::setRawBits(int const raw) {
	this->_rawBits = raw;
}

// Arithmetic operators
float Fixed::operator+(const Fixed &rhs) const {
	return this->toFloat() + rhs.toFloat();
}
float Fixed::operator-(const Fixed &rhs) const {
	return this->toFloat() - rhs.toFloat();
}
float Fixed::operator*(const Fixed &rhs) const {
	return this->toFloat() * rhs.toFloat();
}
float Fixed::operator/(const Fixed &rhs) const {
	if (rhs.toFloat() == 0) {
		std::cerr << "Error: Cannot divide by zero" << std::endl;
		return 0;
	}
	return this->toFloat() / rhs.toFloat();
}

// Pre-increment and Pre-decrement operators
Fixed Fixed::operator++() {
	this->_rawBits++;
	return *this;
}
Fixed Fixed::operator--() {
	this->_rawBits--;
	return *this;
}

// Post-increment and Post-decrement operators
Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	this->_rawBits++;
	return temp;
}
Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	this->_rawBits--;
	return temp;
}
// Comparison operators
bool Fixed::operator>(const Fixed &rhs) const {
	return this->toFloat() > rhs.toFloat();
}
bool Fixed::operator<(const Fixed &rhs) const {
	return this->toFloat() < rhs.toFloat();
}
bool Fixed::operator>=(const Fixed &rhs) const {
	return this->toFloat() >= rhs.toFloat();
}
bool Fixed::operator<=(const Fixed &rhs) const {
	return this->toFloat() <= rhs.toFloat();
}
bool Fixed::operator==(const Fixed &rhs) const {
	return this->toFloat() == rhs.toFloat();
}
bool Fixed::operator!=(const Fixed &rhs) const {
	return this->toFloat() != rhs.toFloat();
}
// Min and Max functions
Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a < b) ? a : b;
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b) ? a : b;
}
Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a > b) ? a : b;
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b) ? a : b;
}