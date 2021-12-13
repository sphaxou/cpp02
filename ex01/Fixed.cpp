/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:41:06 by vgallois          #+#    #+#             */
/*   Updated: 2021/12/13 18:59:02 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <string>
#include <iostream>
#include <math.h>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const Fixed &a)
{
	std::cout << "Copy constructor called" << std::endl;
	_value = a.getRawBits();
}

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called" << std::endl;
	_value = i << frac;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	_value = (int)roundf((f * (1 << frac)));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
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
	std::cout << "Assignation operator called" << std::endl;
	if (this == &src)
		return (*this);
	this->_value = src.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixe)
{
	out << fixe.toFloat();
	return (out);
}
