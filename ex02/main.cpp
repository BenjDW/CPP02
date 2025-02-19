/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 08:30:37 by bde-wits          #+#    #+#             */
/*   Updated: 2025/02/19 07:30:19 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main() {
    // Création de deux objets Fixed
    Fixed a(2);
    Fixed b(5.05f);
    Fixed c(10);
    Fixed d(2);

    std::cout << "Initial values:\n";
    std::cout << "a = " << a << ", b = " << b << ", c = " << c << ", d = " << d << "\n\n";

    // Test des opérations arithmétiques
    std::cout << "Arithmetic operations:\n";
    std::cout << "a + b = " << (a + b) << "\n";
    std::cout << "b - a = " << (b - a) << "\n";
    std::cout << "b * d = " << (b * d) << "\n";
    std::cout << "c / d = " << (c / d) << "\n\n";

    // Test des opérateurs de comparaison
    std::cout << "Comparison operators:\n";
    std::cout << "(a < b)  = " << (a < b) << "\n";
    std::cout << "(a > b)  = " << (a > b) << "\n";
    std::cout << "(a <= d) = " << (a <= d) << "\n";
    std::cout << "(a >= d) = " << (a >= d) << "\n";
    std::cout << "(a == d) = " << (a == d) << "\n";
    std::cout << "(a != d) = " << (a != d) << "\n\n";

    // Test de l'incrémentation et décrémentation
    std::cout << "Increment/Decrement operators:\n";
    std::cout << "a (before post-increment) = " << a << "\n";
    std::cout << "a++ = " << a++ << " (should be same as before)\n";
    std::cout << "a (after post-increment) = " << a << "\n";
    
    std::cout << "++a = " << ++a << " (should be incremented by 1)\n";
    
    std::cout << "b (before post-decrement) = " << b << "\n";
    std::cout << "b-- = " << b-- << " (should be same as before)\n";
    std::cout << "b (after post-decrement) = " << b << "\n";
    
    std::cout << "--b = " << --b << " (should be decremented by 1)\n\n";

    // Test des fonctions min/max
    std::cout << "Min/Max functions:\n";
    std::cout << "Fixed::min(a, b) = " << Fixed::min(a, b) << "\n";
    std::cout << "Fixed::max(a, b) = " << Fixed::max(a, b) << "\n";

    return 0;
}