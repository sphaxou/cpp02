/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:41:06 by vgallois          #+#    #+#             */
/*   Updated: 2021/12/14 17:44:08 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <string>
#include <iostream>
#include <math.h>

Fixed::Fixed()
{
	_value = 0;
}

Fixed::Fixed(const Fixed &a)
{
	_value = a.getRawBits();
}

Fixed::Fixed(const int i)
{
	_value = i << frac;
}

Fixed::Fixed(const float f)
{
	_value = (int)roundf((f * (1 << frac)));
}

Fixed::~Fixed()
{
}

int	Fixed::toInt(void) const
{
	return (_value >> frac);
}

float Fixed::toFloat(void) const
{
	return ((float)_value / (float)(1 << frac));
}

int	Fixed::getRawBits() const
{
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	_value = raw;
}

Fixed	&Fixed::operator=(const Fixed &src)
{
	if (this == &src)
		return (*this);
	this->_value = src.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(const Fixed &src) const
{
	Fixed	tmp;
	tmp.setRawBits(_value + src.getRawBits());
	return (tmp);
}

Fixed	Fixed::operator-(const Fixed &src) const
{
	Fixed	tmp;
	tmp.setRawBits(_value - src.getRawBits());
	return (tmp);
}

Fixed	Fixed::operator*(const Fixed &src) const
{
	Fixed	tmp;
	tmp.setRawBits(_value * src.getRawBits() / (1 << frac));
	return (tmp);
}

Fixed	Fixed::operator/(const Fixed &src) const
{
	Fixed	tmp;
	tmp.setRawBits(_value * (1 << frac) / src.getRawBits());
	return (tmp);
}

Fixed	Fixed::operator++(void)
{
	_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	_value++;
	return (tmp);
}

Fixed	Fixed::operator--(void)
{
	_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	_value--;
	return (tmp);
}

bool Fixed::operator<(Fixed const &op) const {return (_value < op.getRawBits());}
bool Fixed::operator>(Fixed const &op) const {return (_value > op.getRawBits());}
bool Fixed::operator<=(Fixed const &op) const {return (_value <= op.getRawBits());}
bool Fixed::operator>=(Fixed const &op) const {return (_value >= op.getRawBits());}
bool Fixed::operator==(Fixed const &op) const {return (_value == op.getRawBits());}
bool Fixed::operator!=(Fixed const &op) const {return (_value != op.getRawBits());}

Fixed &Fixed::min(Fixed &a, Fixed &b) {return (a < b ? a : b);}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {return (a < b ? a : b);}
Fixed &min(Fixed &a, Fixed &b) {return (Fixed::min(a, b));}
Fixed const &min(Fixed const &a, Fixed const &b) {return(Fixed::min(a, b));}

Fixed &Fixed::max(Fixed &a, Fixed &b) {return (a > b ? a : b);}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {return (a > b ? a : b);}
Fixed &max(Fixed &a, Fixed &b) {return (Fixed::max(a, b));}
Fixed const &max(Fixed const &a, Fixed const &b) {return(Fixed::max(a, b));}

std::ostream &operator<<(std::ostream &out, const Fixed &fixe)
{
	out << fixe.toFloat();
	return (out);
}
