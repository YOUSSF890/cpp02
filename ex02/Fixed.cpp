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
    float value = c * (float)(1 << this->fractional_bits);
    this->fixed_point = roundf(value);
    std::cout << "Float constructor called" << std::endl;
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
    float value =  this->fixed_point / (float)(1 << this->fractional_bits);
    return (value);
}

int Fixed::toInt( void ) const
{
    int value =  this->fixed_point / (1 << this->fractional_bits);
    return (value);
}

Fixed& Fixed::operator=(const Fixed& c)
{
    this->fixed_point = c.getRawBits();
    return *this;
}


std::ostream& operator<<(std::ostream& os,const Fixed& fixed)
{
    os << fixed.toFloat();
    // int value = fixed.getRawBits() / 256;
    // fixed.setRawBits(value);
    return os;
}

//  The 6 comparison operators: >, <, >=, <=, ==, and !=.

bool Fixed::operator>(const Fixed& fixed) const {
    return (this->fixed_point > fixed.fixed_point);
}

bool Fixed::operator<(const Fixed& fixed) const {
    return (this->fixed_point < fixed.fixed_point);
}

bool Fixed::operator>=(const Fixed& fixed) const {
    return (this->fixed_point >= fixed.fixed_point);
}

bool Fixed::operator<=(const Fixed& fixed) const {
    return (this->fixed_point <= fixed.fixed_point);
}

bool Fixed::operator!=(const Fixed& fixed) const {
    return (this->fixed_point != fixed.fixed_point);
}

//  The 4 arithmetic operators: +, -, *, and /

Fixed Fixed::operator+(const Fixed& fixed) const {
    Fixed c;
    c.fixed_point = this->fixed_point + fixed.fixed_point + 1;
    return (c);
}

Fixed Fixed::operator*(const Fixed& fixed) const {
    Fixed c;
    c.fixed_point = this->fixed_point * fixed.fixed_point;
    return (c);
}

Fixed Fixed::operator/(const Fixed& fixed) const {
    Fixed c;
    c.fixed_point = this->fixed_point / fixed.fixed_point;
    return (c);
}

Fixed Fixed::operator-(const Fixed& fixed) const {
    Fixed c;
    c.fixed_point = this->fixed_point - fixed.fixed_point;
    return (c);
}

// ++a

Fixed& Fixed::operator++() {

    this->fixed_point += 0.00390625 * (1 << this->fractional_bits);
    return (*this);
}

// a++

Fixed Fixed::operator++(int) {
    Fixed time(*this);
    this->fixed_point += 0.00390625 * (1 << this->fractional_bits);
    return (time);
}

// min max

Fixed& Fixed::min(Fixed& fixed1, Fixed& fixed2)
{
    if (fixed1.fixed_point > fixed2.fixed_point)
    {
        fixed2.fixed_point = fixed2.fixed_point * (1 << fixed2.fractional_bits);
        return (fixed2);
    }
    else
    {
        fixed1.fixed_point = fixed1.fixed_point * (1 << fixed1.fractional_bits);
        return (fixed1);
    }
}

Fixed& Fixed::min(const Fixed& fixed1, const Fixed & fixed2)
{
    Fixed *fixed_min = new (Fixed);

    if (fixed1.fixed_point > fixed2.fixed_point)
        fixed_min->fixed_point = fixed2.fixed_point;
    else
        fixed_min->fixed_point = fixed1.fixed_point;
    return (*fixed_min);

}

Fixed& Fixed::max(Fixed& fixed1, Fixed& fixed2)
{
    if (fixed1.fixed_point > fixed2.fixed_point)
    {
        fixed1.fixed_point = fixed1.fixed_point * (1 << fixed1.fractional_bits);
        return (fixed1);
    }
    else
    {
        fixed2.fixed_point = fixed2.fixed_point * (1 << fixed2.fractional_bits);
        return (fixed2);
    }
}

Fixed& Fixed::max(const Fixed& fixed1, const Fixed & fixed2)
{
    Fixed *fixed_min = new (Fixed);
    if (fixed1.fixed_point < fixed2.fixed_point)
        fixed_min->fixed_point = fixed2.fixed_point;
    else
        fixed_min->fixed_point = fixed1.fixed_point;
    return (*fixed_min);
}

Fixed::~Fixed() {}