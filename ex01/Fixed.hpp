#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath> // Pour roundf

class Fixed {
private:
    int _fixedPointValue;      // La valeur en virgule fixe (stockée comme entier)
    static const int _fractionalBits = 8; // Nombre de bits pour la partie fractionnaire

public:
    Fixed();                          // Constructeur par défaut
    Fixed(const int intValue);        // Constructeur prenant un entier
    Fixed(const float floatValue);    // Constructeur prenant un flottant
    Fixed(const Fixed& other);        // Constructeur de recopie
    ~Fixed();                         // Destructeur

    Fixed& operator=(const Fixed& other); // Opérateur d'affectation

    float toFloat() const;            // Convertir en float
    int toInt() const;                // Convertir en int

    // Surcharge de l'opérateur <<
    friend std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
};

#endif
