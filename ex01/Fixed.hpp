/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bianca <bianca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:23:48 by bmuni             #+#    #+#             */
/*   Updated: 2023/06/16 17:50:04 by bianca           ###   ########.fr       */
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
		Fixed(void);
		Fixed(const int n);
		Fixed(const float n);
		Fixed(const Fixed &Fix);
		~Fixed();
		Fixed	&operator=(const Fixed&Fix);
		int getRawBits( void ) const;
		void setRawBits(int const raw);
		float toFloat( void ) const;
		int toInt( void ) const;
		int SgetRawBits( void ) const;
		friend std::ostream& operator<<(std::ostream&, const Fixed&);
};

#endif