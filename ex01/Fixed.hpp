/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:34:19 by vgallois          #+#    #+#             */
/*   Updated: 2021/12/13 18:50:22 by vgallois         ###   ########.fr       */
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

		int	toInt(void) const;
		float toFloat(void) const;
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		Fixed &operator=(const Fixed &fixed);

	private:
		int _value;
		const static int frac = 8;
};

std::ostream	&operator<<(std::ostream&, const Fixed&);
#endif
