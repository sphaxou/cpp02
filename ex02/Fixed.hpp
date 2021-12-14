/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:34:19 by vgallois          #+#    #+#             */
/*   Updated: 2021/12/14 17:35:04 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H
#include <iostream>
class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &a);
		Fixed(const int i);
		Fixed(const float f);
		~Fixed();

		int		toInt(void) const;
		float	toFloat(void) const;
	
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		Fixed &operator=(const Fixed &fixed);
	
		Fixed operator+(const Fixed &fixed) const;
		Fixed operator-(const Fixed &fixed) const;
		Fixed operator*(const Fixed &fixed) const;
		Fixed operator/(const Fixed &fixed) const;
		Fixed operator++(void);
		Fixed operator++(int);
		Fixed operator--(void);
		Fixed operator--(int);
	
		bool operator==(const Fixed &fixed) const;
		bool operator!=(const Fixed &fixed) const;
		bool operator<(const Fixed &fixed) const;
		bool operator<=(const Fixed &fixed) const;
		bool operator>(const Fixed &fixed) const;
		bool operator>=(const Fixed &fixed) const;

		static Fixed const &min(const Fixed &a, const Fixed &b);
		static Fixed const &max(const Fixed &a, const Fixed &b);
		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);

	private:
		int _value;
		const static int frac = 8;
};

std::ostream	&operator<<(std::ostream&, const Fixed&);
Fixed const &min(Fixed const &a, Fixed const &b);
Fixed const &max(Fixed const &a, Fixed const &b);
Fixed &min(Fixed &a, Fixed &b);
Fixed &max(Fixed &a, Fixed &b);
#endif
