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

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignmment operator called" << std::endl;
	if (this != &other)
	{
		this->_rawBits = other.getRawBits();
	}
	return (*this);
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
