
#include "Fixed.hpp"

Fixed::Fixed( void ) : _rawBits(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const &src )
{
    std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(src.getRawBits());
}

Fixed::~Fixed( void )
{
    std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
		this->setRawBits(rhs.getRawBits());
    return *this;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_rawBits;
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_rawBits = raw;
}

