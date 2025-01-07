#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    _rawBits = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    _rawBits = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &other)
        _rawBits = other._rawBits;
    return *this;
}

bool Fixed::operator>(const Fixed &other) const
{
    return _rawBits > other._rawBits;
}


bool Fixed::operator<(const Fixed &other) const
{
    return _rawBits < other._rawBits;
}

bool Fixed::operator>=(const Fixed &other) const
{
    return _rawBits >= other._rawBits;
}

bool Fixed::operator<=(const Fixed &other) const
{
    return _rawBits <= other._rawBits;
}

bool Fixed::operator==(const Fixed &other) const
{
    return _rawBits == other._rawBits;
}

bool Fixed::operator!=(const Fixed &other) const
{
    return _rawBits != other._rawBits;
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;

    result._rawBits = _rawBits + other._rawBits;
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;

    result._rawBits = _rawBits - other._rawBits;
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;

    result._rawBits = (_rawBits * other._rawBits) >> _fractionalBits;
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed result;

    result._rawBits = (_rawBits << _fractionalBits) / other._rawBits;
    return result;
}

Fixed &Fixed::operator++()
{
    _rawBits++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);

    operator++();
    return tmp;
}

Fixed &Fixed::operator--()
{
    _rawBits--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);

    operator--();
    return tmp;
}

float Fixed::toFloat() const
{
    return static_cast<float>(_rawBits) / (1 << _fractionalBits);
}

int Fixed::toInt() const
{
    return _rawBits >> _fractionalBits;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return a < b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return a > b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return a > b ? a : b;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}

