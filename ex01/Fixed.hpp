/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 08:33:15 by bde-wits          #+#    #+#             */
/*   Updated: 2025/01/08 12:27:37 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <ostream>
#include <iomanip>
#include <string>

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
		// Fixed();
		Fixed(const int i);
		Fixed(const float fraction);
		~Fixed();


		int getRawBits(void) const;
		void setRawBits(int const raw);
	private:
		int					fix;
		static const int	virgule = 8;
};

// Fixed::Fixed()
// {	
// }

// entier constant en paramètre et qui convertit celui-ci en virgule fixe
Fixed::Fixed(const int i)
{

}

// flottant constant en paramètre et qui convertit celui-ci en virgule fixe.
Fixed::Fixed(const float fraction)
{
	
}

#endif