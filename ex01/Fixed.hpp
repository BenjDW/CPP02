/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 08:33:15 by bde-wits          #+#    #+#             */
/*   Updated: 2025/01/09 08:47:33 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <ostream>
#include <iomanip>
#include <string>
#include <cmath>

// Un constructeur prenant un entier constant en paramètre et qui convertit celui-ci en virgule fixe. Le nombre de bits de la partie fractionnaire est initialisé à 8
// comme dans l’exercice 00.
// • Un constructeur prenant un flottant constant en paramètre et qui convertit
// celui-ci en virgule fixe. Le nombre de bits de la partie fractionnaire est initialisé à
// 8 comme dans l’exercice 00.
// • Une fonction membre float toFloat( void ) const;
// qui convertit la valeur en virgule fixe en nombre à virgule flottante.
// • Une fonction membre int toInt( void ) const;
// qui convertit la valeur en virgule fixe en nombre entier.
// Ajoutez également la fonction suivante à vos fichiers de la classe Fixed :
// • Une surcharge de l’opérateur d’insertion («) qui insère une représentation en virgule flottante du nombre à virgule fixe dans le flux de sortie (objet output stream)
// passé en paramètre.

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

int	Fixed::getRawBits() const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->fix);
}

void	Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->fix = raw;
}

Fixed& Fixed::operator=(const Fixed& src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fix = src.fix;
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat()/* << std::endl*/;
	return (out);
}

// Une fonction membre int toInt( void ) const;
// qui convertit la valeur en virgule fixe en nombre entier
int	Fixed::toInt() const
{
	return (Fixed::fix >> Fixed::virgule);
}

// Une fonction membre float toFloat( void ) const;
// qui convertit la valeur en virgule fixe en nombre à virgule flottante.
float	Fixed::toFloat() const
{
	return (Fixed::fix / pow(2, Fixed::virgule));
}

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fix = 0;	
}

// entier constant en paramètre et qui convertit celui-ci en virgule fixe
// Le constructeur avec int convertit l'entier en virgule fixe en décalant les bits.
// 
Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called" << std::endl;
	this->fix = i << 8;
	// this->fix = i * 256;
}

// Exemple avec 8 bits pour la fraction :

// Si on stocke le nombre 5.75, il sera représenté en interne comme 5.75 * 2^8 = 1472 dans un entier.
// La valeur réelle sera retrouvée en divisant par 2^8, soit 1472 / 256 = 5.75.
// temp = r/pow(10, mag);      /* see if number will have a decimal */
// fpart = temp - floor(temp); /* when written in scientific notation */

// flottant constant en paramètre et qui convertit celui-ci en virgule fixe.
// Le constructeur avec float convertit le flottant en virgule fixe en multipliant par 2^8 ou 256 et arrondissant.
Fixed::Fixed(const float fraction)
{
	std::cout << "Float constructor called" <<std::endl;
	// this->fix = Fixed::toInt((void)fraction);
	this->fix = around(fraction * 256);
}

Fixed::Fixed(const Fixed &cpy)
{
	std::cout << "Copy constructor called" << std::endl;
	// this->fix = cpy.fix;
	*this = cpy;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// int	Fixed::around(const float fraction);
// fonction qui est censé aroundir nbr scientific a un nbr decimal
int	Fixed::around(const float fraction)
{
	int	temp;
	if (fraction > 0)
		temp = fraction/* / 256*/ + 0.5f;
	else if (fraction < 0)
		temp = fraction/* / 256 */- 0.5f;
	else
		temp = fraction;
	return (temp);
}

#endif