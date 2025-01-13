/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 08:33:15 by bde-wits          #+#    #+#             */
/*   Updated: 2025/01/09 08:54:11 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <ostream>
#include <iomanip>
#include <string>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const int i);
		Fixed(const float fraction);
		Fixed(const Fixed &cpy);
		~Fixed();
		float 	toFloat( void ) const;
		int 	toInt( void ) const;
		int 	getRawBits(void) const;
		void 	setRawBits(int const raw);
		Fixed& 	operator=(const Fixed& src);
		int		around(const float fraction);
	private:
		int					fix;
		static const int	virgule = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif