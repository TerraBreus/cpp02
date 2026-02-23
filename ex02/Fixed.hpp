#pragma once
# include <iostream>

class Fixed {
	private:
		int					_rawBits;
		static const int	_fractionalBits;
	public:
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& other);
		~Fixed(void);
		int					getRawBits(void) const;	
		void				setRawBits(const int raw);
		int					toInt(void) const;
		float				toFloat(void) const;
		Fixed&				operator=(const Fixed& rhs);
		bool				operator<(const Fixed &rhs) const;
		bool				operator>(const Fixed &rhs) const;
		bool				operator<=(const Fixed &rhs) const;
		bool				operator>=(const Fixed &rhs) const;
		bool				operator==(const Fixed &rhs) const;
		bool				operator!=(const Fixed &rhs) const;
		Fixed				operator+(const Fixed &rhs) const;
		Fixed				operator-(const Fixed &rhs) const;
		Fixed				operator*(const Fixed &rhs) const;
		Fixed				operator/(const Fixed &rhs) const;
		Fixed&				operator++();
		Fixed				operator++(int);
		Fixed&				operator--();
		Fixed				operator--(int);
		static Fixed&		min(Fixed &i, Fixed &j);
		static const Fixed&	min(const Fixed &i, const Fixed &j);
		static Fixed&		max(Fixed &i, Fixed &j);
		static const Fixed&	max(const Fixed &i, const Fixed &j);
};

std::ostream &operator<<(std::ostream &o, const Fixed &i);
