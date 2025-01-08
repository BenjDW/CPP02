/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 06:34:39 by bde-wits          #+#    #+#             */
/*   Updated: 2025/01/08 08:21:01 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fix);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fix = raw;
}

Fixed& Fixed::operator=(const Fixed& src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fix = src.getRawBits();
	return (*this);
}

Fixed::Fixed(const Fixed &cpy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fix = cpy.fix;
}

Fixed::Fixed(int i)
{
	std::cout << "parameter constructor called" << std::endl;
	this->fix = i;
}

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fix = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}