#ifndef FIXED_HPP
# define FIXED_HPP
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
		Fixed& operator=(const Fixed& other);
		~Fixed(void);
		int		getRawBits(void) const;	
		void	setRawBits(const int raw);
		int		toInt(void) const;
		float	toFloat(void) const;
};

std::ostream &operator<<(std::ostream &o, const Fixed &i);

#endif
