#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_fractionalBits = 8;

std::ostream &operator<<(std::ostream &o, const Fixed &i)
{
	o << i.toFloat();
	return (o);
}

Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int Constructor called" << std::endl;
	this->_rawBits = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = roundf(value * (1 << this->_fractionalBits));
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}

void	Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
}

int		Fixed::toInt(void) const
{
	int	result;

	result = this->_rawBits >> this->_fractionalBits;
	return (result);
}

float	Fixed::toFloat(void) const
{
	float	result;

	result = static_cast<float>(this->_rawBits) / (1 << this->_fractionalBits);
	return (result);
}

//rhs: Right Hand Side
Fixed &Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignmment operator called" << std::endl;
	if (this == &rhs)
		return (*this);
	this->_rawBits = rhs.getRawBits();
	return (*this);
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	return (this->_rawBits < rhs.getRawBits());
}

bool	Fixed::operator>(const Fixed &rhs) const
{
	return (this->_rawBits > rhs.getRawBits());
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
	return (this->_rawBits <= rhs.getRawBits());
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
	return (this->_rawBits >= rhs.getRawBits());
}

bool	Fixed::operator==(const Fixed &rhs) const
{
	return (this->_rawBits == rhs.getRawBits());
}

bool	Fixed::operator!=(const Fixed &rhs) const
{
	return (this->_rawBits != rhs.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &rhs) const
{
	Fixed	result;

	result.setRawBits(this->_rawBits + rhs.getRawBits());
	return (result);
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	Fixed	result;

	result.setRawBits(this->_rawBits - rhs.getRawBits());
	return (result);
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	Fixed	result(this->toFloat() * rhs.toFloat());
	return (result);
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	Fixed	result(this->toFloat() / rhs.toFloat());
	return (result);
}
