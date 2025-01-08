/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 06:34:56 by bde-wits          #+#    #+#             */
/*   Updated: 2025/01/08 08:20:18 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <ostream>
#include <iomanip>
#include <string>

class Fixed
{
	public:
		Fixed();
		Fixed(int i);
		Fixed(const Fixed &cpy);
		~Fixed();
		Fixed& operator=(const Fixed& src);

		int getRawBits(void) const;
		void setRawBits(int const raw);
	private:
		int	fix;
		static const int	virgule = 8;
};

#endif