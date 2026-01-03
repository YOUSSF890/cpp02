#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int fixed_point;
    static const int fractional_bits;

public:
    Fixed();
    ~Fixed();
    Fixed &operator=(const Fixed &);

    Fixed(const Fixed &a);
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif