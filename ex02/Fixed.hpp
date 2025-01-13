/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 00:39:57 by bde-wits          #+#    #+#             */
/*   Updated: 2025/01/13 09:07:01 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <ostream>
#include <iomanip>
#include <string>
#include <cmath>

// Ajoutez à votre classe des fonctions membres publiques afin de surcharger les opérateurs suivants :
// • Les 6 opérateur de comparaison : >, <, >=, <=, == et !=.
// • Les 4 opérateurs de arithmétiques : +, -, *, et /.
// • Les 4 opérateurs d’incrémentation et de décrémentation (pré-incrémentation et
// post-incrémentation, pré-décrémentation et post-décrémentation) qui diminueront
// la valeur du nombre à virgule fixe d’unité ϵ tel que 1 + ϵ > 1.

// Ajoutez à votre classe ces quatre fonctions membres publiques surchargées :
// • Une fonction membre statique min prenant en paramètres deux références sur des
// nombres à virgule fixe et qui retourne le plus petit d’entre eux.
// • Une fonction membre statique min prenant en paramètres deux références sur des
// nombres à virgule fixe constants et qui retourne le plus petit d’entre eux.
// • Une fonction membre statique max prenant en paramètres deux références sur des
// nombres à virgule fixe et qui retourne le plus grand d’entre eux.
// • Une fonction membre statique max prenant en paramètres deux références sur des
// nombres à virgule fixe constants et qui retourne le plus grand d’entre eux.


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
		
		// operateur de comparaison
		bool	operator>(const Fixed& src) const;
		bool	operator<(const Fixed& src) const;
		bool	operator>=(const Fixed& src) const;
		bool	operator<=(const Fixed& src) const;
		bool	operator==(const Fixed& src) const;
		bool	operator!=(const Fixed& src) const;

		// operateur de arithmétiques
		Fixed		operator+(const Fixed& src) const;
		Fixed		operator-(const Fixed& src) const;
		Fixed		operator*(const Fixed& src) const;
		Fixed		operator/(const Fixed& src) const;

		// Operateur de pré-incrémentation
		Fixed		operator++(int i);
		Fixed		operator++();
		Fixed		operator--(int i);
		Fixed		operator--();
		
		// fonction membre min max
		static Fixed&			min(Fixed &ref1, Fixed &ref2);
		static const Fixed&		min(Fixed const &ref1, Fixed const &ref2);
		static Fixed&			max(Fixed &ref1, Fixed &ref2);
		static const Fixed&		max(Fixed const &ref1, Fixed const &ref2);

	private:
		int					fix;
		static const int	virgule = 8;
};

// std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

const Fixed&	Fixed::min(Fixed const &ref1, Fixed const &ref2)
{
	if (ref1 < ref2)
		return (ref1);
	else
		return (ref2);
}

Fixed&	Fixed::min(Fixed &ref1, Fixed &ref2)
{
	if (ref1 < ref2)
		return (ref1);
	else
		return (ref2);
}

Fixed&	Fixed::max(Fixed &ref1, Fixed &ref2)
{
	if (ref1 > ref2)
		return (ref1);
	else
		return (ref2);
}

const Fixed&	Fixed::max(Fixed const &ref1, Fixed const &ref2)
{
	if (ref1 > ref2)
		return (ref1);
	else
		return (ref2);
}

Fixed		Fixed::operator--(int)
{
	Fixed	temp = *this;

	this->fix--;
	return (temp);
}

Fixed		Fixed::operator--()
{
	--this->fix;
	return (*this);
}

// post-incrementation
Fixed		Fixed::operator++()
{
	++this->fix;
	return (*this);
}

// pré-incrementation
Fixed		Fixed::operator++(int)
{
	Fixed	temp = *this;
	
	this->fix++;
	return (temp);
}

Fixed		Fixed::operator/(const Fixed& src) const
{
	Fixed	result;

	result.fix = (this->fix * 256) / src.fix;
	return (result);
}

Fixed		Fixed::operator*(const Fixed& src) const
{
	Fixed	result;
	
	result.fix = (this->fix * src.fix) >> Fixed::virgule;
	return (result);
}

Fixed		Fixed::operator-(const Fixed& src) const
{
	Fixed	result;

	result.fix = this->fix - src.fix;
	return (result);
}

Fixed		Fixed::operator+(const Fixed& src) const
{
	Fixed	result;

	result.fix = this->fix + src.fix;
	return (result);
}

bool	Fixed::operator>(const Fixed& src) const
{
	if (Fixed::fix > src.fix)
		return (true);
	else
		return (false);
}

bool	Fixed::operator<(const Fixed& src) const
{
	if (Fixed::fix < src.fix)
		return (true);
	else
		return (false);
}

bool	Fixed::operator>=(const Fixed& src) const
{
	if (Fixed::fix >= src.fix)
		return (true);
	else
		return (false);
}

bool	Fixed::operator<=(const Fixed& src) const
{
	if (Fixed::fix <= src.fix)
		return (true);
	else
		return (false);
}

bool	Fixed::operator==(const Fixed& src) const
{
	if (Fixed::fix == src.fix)
		return (true);
	else
		return (false);
}

bool	Fixed::operator!=(const Fixed& src) const
{
	if (Fixed::fix != src.fix)
		return (true);
	else
		return (false);
}

Fixed& Fixed::operator=(const Fixed& src)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->fix = src.fix;
	return (*this);
}


std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

int	Fixed::getRawBits() const
{
	return (this->fix);
}

void	Fixed::setRawBits(int const raw)
{
	this->fix = raw;
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
	// std::cout << "Default constructor called" << std::endl;
	this->fix = 0;	
}

Fixed::Fixed(const int i)
{
	// std::cout << "Int constructor called" << std::endl;
	this->fix = i << 8;
}

Fixed::Fixed(const float fraction)
{
	// std::cout << "Float constructor called" <<std::endl;
	this->fix = around(fraction * 256);
}

Fixed::Fixed(const Fixed &cpy)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
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


#endif