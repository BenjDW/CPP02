/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 00:39:57 by bde-wits          #+#    #+#             */
/*   Updated: 2025/01/13 10:23:23 by bde-wits         ###   ########.fr       */
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
		int		around(const float fraction);
		Fixed& 	operator=(const Fixed& src);
		
		bool	operator>(const Fixed& src) const;
		bool	operator<(const Fixed& src) const;
		bool	operator>=(const Fixed& src) const;
		bool	operator<=(const Fixed& src) const;
		bool	operator==(const Fixed& src) const;
		bool	operator!=(const Fixed& src) const;

		Fixed		operator+(const Fixed& src) const;
		Fixed		operator-(const Fixed& src) const;
		Fixed		operator*(const Fixed& src) const;
		Fixed		operator/(const Fixed& src) const;

		Fixed		operator++(int i);
		Fixed		operator++();
		Fixed		operator--(int i);
		Fixed		operator--();
		
		static Fixed&			min(Fixed &ref1, Fixed &ref2);
		static const Fixed&		min(Fixed const &ref1, Fixed const &ref2);
		static Fixed&			max(Fixed &ref1, Fixed &ref2);
		static const Fixed&		max(Fixed const &ref1, Fixed const &ref2);

	private:
		int					fix;
		static const int	virgule = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif