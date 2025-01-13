/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 08:32:59 by bde-wits          #+#    #+#             */
/*   Updated: 2025/01/09 08:53:54 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	Fixed::getRawBits() const
{
	return (this->fix);
}

void	Fixed::setRawBits(int const raw)
{
	this->fix = raw;
}

Fixed& Fixed::operator=(const Fixed& src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fix = src.fix;
	return (*this);
}


std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

int	Fixed::toInt() const
{
	return (Fixed::fix >> Fixed::virgule);
}

float	Fixed::toFloat() const
{
	return (Fixed::fix / pow(2, Fixed::virgule));
}

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fix = 0;	
}

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called" << std::endl;
	this->fix = i << 8;
}

Fixed::Fixed(const float fraction)
{
	std::cout << "Float constructor called" <<std::endl;
	this->fix = around(fraction * 256);
}

Fixed::Fixed(const Fixed &cpy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::around(const float fraction)
{
	int	temp;
	if (fraction > 0)
		temp = fraction + 0.5f;
	else if (fraction < 0)
		temp = fraction - 0.5f;
	else
		temp = fraction;
	return (temp);
}
