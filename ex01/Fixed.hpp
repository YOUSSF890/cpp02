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
        Fixed(int const b);
        Fixed(float const b);
        ~Fixed();
        Fixed& operator=(const Fixed& c)
        {
            std::cout << "Copy assignment operator called" << std::endl;
            this->fixed_point = c.getRawBits();
            return *this;
        }
        std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
        Fixed(const Fixed &a);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat( void ) const;
        int toInt( void ) const;

};


#endif