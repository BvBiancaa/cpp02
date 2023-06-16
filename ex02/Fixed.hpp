/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bianca <bianca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:23:28 by bmuni             #+#    #+#             */
/*   Updated: 2023/06/16 18:37:41 by bianca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <fstream>

class	Fixed
{
	private:
		static const int O = 8;
		int	store;
	public:
		Fixed();
		Fixed(int const num);
		Fixed(float const ft);
		Fixed(Fixed const & fx);
		~Fixed();
		bool	operator>(Fixed const & fx) const;
		bool	operator<(Fixed const & fx) const;
		bool	operator>=(Fixed const & fx) const;
		bool	operator<=(Fixed const & fx) const;
		bool	operator==(Fixed const & fx) const;
		bool	operator!=(Fixed const & fx) const;
		static	Fixed& min(Fixed& a, Fixed& b);
		static	const Fixed& min(const Fixed& a, const Fixed& b);
		static	Fixed& max(Fixed& a, Fixed& b);
		static	const Fixed& max(const Fixed& a, const Fixed& b);
		Fixed&	operator=(Fixed const & fx);
		Fixed	operator+(Fixed const & fx) const;
		Fixed	operator-(Fixed const & fx) const;
		Fixed	operator*(Fixed const & fx) const;
		Fixed	operator/(Fixed const & fx) const;
		Fixed&	operator++( void );
		Fixed	operator++( int num );
		Fixed&	operator--( void );
		Fixed	operator--( int num );	
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
		friend std::ostream& operator<<(std::ostream& os, const Fixed& obj);
};

#endif