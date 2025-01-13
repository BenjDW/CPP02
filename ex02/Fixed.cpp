#include "Fixed.hpp"

const Fixed&	Fixed::min(Fixed const &ref1, Fixed const &ref2)
{
	if (ref1 < ref2)
		return (ref1);
	else
		return (ref2);
}

Fixed&	Fixed::min(Fixed &ref1, Fixed &ref2)
{
	if (ref1 < ref2)
		return (ref1);
	else
		return (ref2);
}

Fixed&	Fixed::max(Fixed &ref1, Fixed &ref2)
{
	if (ref1 > ref2)
		return (ref1);
	else
		return (ref2);
}

const Fixed&	Fixed::max(Fixed const &ref1, Fixed const &ref2)
{
	if (ref1 > ref2)
		return (ref1);
	else
		return (ref2);
}

Fixed		Fixed::operator--(int)
{
	Fixed	temp = *this;

	this->fix--;
	return (temp);
}

Fixed		Fixed::operator--()
{
	--this->fix;
	return (*this);
}

// post-incrementation
Fixed		Fixed::operator++()
{
	++this->fix;
	return (*this);
}

// pré-incrementation
Fixed		Fixed::operator++(int)
{
	Fixed	temp = *this;
	
	this->fix++;
	return (temp);
}

Fixed		Fixed::operator/(const Fixed& src) const
{
	Fixed	result;

	result.fix = (this->fix * 256) / src.fix;
	return (result);
}

Fixed		Fixed::operator*(const Fixed& src) const
{
	Fixed	result;
	
	result.fix = (this->fix * src.fix) >> Fixed::virgule;
	return (result);
}

Fixed		Fixed::operator-(const Fixed& src) const
{
	Fixed	result;

	result.fix = this->fix - src.fix;
	return (result);
}

Fixed		Fixed::operator+(const Fixed& src) const
{
	Fixed	result;

	result.fix = this->fix + src.fix;
	return (result);
}

bool	Fixed::operator>(const Fixed& src) const
{
	if (Fixed::fix > src.fix)
		return (true);
	else
		return (false);
}

bool	Fixed::operator<(const Fixed& src) const
{
	if (Fixed::fix < src.fix)
		return (true);
	else
		return (false);
}

bool	Fixed::operator>=(const Fixed& src) const
{
	if (Fixed::fix >= src.fix)
		return (true);
	else
		return (false);
}

bool	Fixed::operator<=(const Fixed& src) const
{
	if (Fixed::fix <= src.fix)
		return (true);
	else
		return (false);
}

bool	Fixed::operator==(const Fixed& src) const
{
	if (Fixed::fix == src.fix)
		return (true);
	else
		return (false);
}

bool	Fixed::operator!=(const Fixed& src) const
{
	if (Fixed::fix != src.fix)
		return (true);
	else
		return (false);
}

Fixed& Fixed::operator=(const Fixed& src)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->fix = src.fix;
	return (*this);
}


std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

int	Fixed::getRawBits() const
{
	return (this->fix);
}

void	Fixed::setRawBits(int const raw)
{
	this->fix = raw;
}


int	Fixed::toInt() const
{
	return (Fixed::fix >> Fixed::virgule);
}

float	Fixed::toFloat() const
{
	return (Fixed::fix / pow(2, Fixed::virgule));
}

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	this->fix = 0;	
}

Fixed::Fixed(const int i)
{
	// std::cout << "Int constructor called" << std::endl;
	this->fix = i << 8;
}

Fixed::Fixed(const float fraction)
{
	// std::cout << "Float constructor called" <<std::endl;
	this->fix = around(fraction * 256);
}

Fixed::Fixed(const Fixed &cpy)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int	Fixed::around(const float fraction)
{
	int	temp;
	if (fraction > 0)
		temp = fraction + 0.5f;
	else if (fraction < 0)
		temp = fraction - 0.5f;
	else
		temp = fraction;
	return (temp);
}
