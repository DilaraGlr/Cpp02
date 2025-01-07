#include "Fixed.hpp"

// Constructeur par défaut
Fixed::Fixed() : _fixedPointValue(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

// Constructeur prenant un entier
Fixed::Fixed(const int intValue) 
{
    std::cout << "Int constructor called" << std::endl;
    _fixedPointValue = intValue << _fractionalBits; // Décalage pour représenter l'entier en virgule fixe
}

// Constructeur prenant un flottant
Fixed::Fixed(const float floatValue) 
{
    std::cout << "Float constructor called" << std::endl;
    _fixedPointValue = roundf(floatValue * (1 << _fractionalBits)); // Conversion en virgule fixe
}

// Constructeur de recopie
Fixed::Fixed(const Fixed& other) 
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other; // On utilise l'opérateur d'affectation
}

// Destructeur
Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
}

// Opérateur d'affectation
Fixed& Fixed::operator=(const Fixed& other) 
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) 
    {
        _fixedPointValue = other._fixedPointValue;
    }
    return *this;
}

// Convertir en float
float Fixed::toFloat() const 
{
    return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

// Convertir en int
int Fixed::toInt() const 
{
    return _fixedPointValue >> _fractionalBits; // Décalage pour récupérer l'entier
}

// Surcharge de l'opérateur <<
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) 
{
    out << fixed.toFloat(); // Affiche la version flottante
    return out;
}
