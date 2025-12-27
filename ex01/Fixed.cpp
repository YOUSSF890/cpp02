#include "Fixed.hpp"

const int Fixed::fractional_bits = 8;

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->fixed_point = 0;
}

Fixed::Fixed(const Fixed &a)
{
    this->fixed_point = a.getRawBits();
    std::cout << "Copy constructor called" << std:: endl;
}

Fixed::Fixed(int const b)
{
    this->setRawBits(b);
    this->fixed_point *= (1 << this->fractional_bits);
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const c)
{
    this->setRawBits(c);
    this->fixed_point *= (1 << this->fractional_bits);
    std::cout << "float constructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    return(fixed_point);
}

void Fixed::setRawBits( int const raw )
{
    this->fixed_point = raw;
}

float Fixed::toFloat( void ) const
{
    float value =  this->fixed_point / (1 << this->fractional_bits);
    return (value);
}

int Fixed::toInt( void ) const
{
    int value =  this->fixed_point / (1 << this->fractional_bits);
    return (value);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}