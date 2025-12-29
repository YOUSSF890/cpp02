#include "Fixed.hpp"

const int Fixed::fractional_bits = 8;

Fixed::Fixed() {
    this->fixed_point = 0;
}

Fixed::Fixed(const Fixed &a) {
    this->fixed_point = a.getRawBits();
}

Fixed::Fixed(int const b) {
    this->setRawBits(b);
    this->fixed_point *= (1 << this->fractional_bits);
}

Fixed::Fixed(float const c) {
    float value = c * (float)(1 << this->fractional_bits);
    this->fixed_point = roundf(value);
}

int Fixed::getRawBits( void ) const {
    return(fixed_point);
}

void Fixed::setRawBits( int const raw ) {
    this->fixed_point = raw;
}

float Fixed::toFloat( void ) const {
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
    c.fixed_point = this->fixed_point + fixed.fixed_point;
    return (c);
}

Fixed Fixed::operator*(const Fixed& fixed) const {
    Fixed c;
    c.fixed_point = (this->fixed_point * fixed.fixed_point) / 256;
    return (c);
}

Fixed Fixed::operator/(const Fixed& fixed) const {
    Fixed c;
    c.fixed_point = ((float)this->fixed_point / (float)fixed.fixed_point) * 256;
    return (c);
}

Fixed Fixed::operator-(const Fixed& fixed) const {
    Fixed c;
    c.fixed_point = this->fixed_point - fixed.fixed_point;
    return (c);
}
// a++  ++a

Fixed& Fixed::operator++() {

    this->fixed_point += 0.00390625 * (1 << this->fractional_bits);
    return (*this);
}

Fixed Fixed::operator++(int) {
    Fixed time(*this);
    this->fixed_point += 0.00390625 * (1 << this->fractional_bits);
    return (time);
}

Fixed& Fixed::min(Fixed& fixed1, Fixed& fixed2)
{
    if (fixed1 < fixed2)
        return (fixed1);
    else
        return (fixed2);
}

const Fixed& Fixed::min(const Fixed& fixed1, const Fixed& fixed2)
{
    if (fixed1 <= fixed2)
        return (fixed1);
    else
        return (fixed2);
}

Fixed& Fixed::max(Fixed& fixed1, Fixed& fixed2)
{
    if (fixed1 > fixed2)
        return (fixed1);
    else
        return (fixed2);
}

const Fixed& Fixed::max(const Fixed& fixed1, const Fixed & fixed2)
{
    if (fixed1 >= fixed2)
        return (fixed1);
    else
        return (fixed2);
}

Fixed::~Fixed() {}