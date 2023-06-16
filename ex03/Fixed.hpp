/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bianca <bianca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:28:48 by bmuni             #+#    #+#             */
/*   Updated: 2023/06/16 19:00:41 by bianca           ###   ########.fr       */
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

class Fixed
{
	private:
		int store;
		static const int O = 8;
	public:
		Fixed();
		Fixed(const int i);
		Fixed(const float f);
		~Fixed();
		Fixed(const Fixed &fix);
		Fixed &operator=(Fixed fix);
		void swap(Fixed &one, Fixed &two); 
		Fixed& operator++();
		Fixed operator++(int n);
		Fixed& operator--();
		Fixed operator--(int n);
		Fixed operator+=(const Fixed &fix);
		Fixed operator-=(const Fixed &fix);
		Fixed operator*=(const Fixed &fix);
		Fixed operator/=(const Fixed &fix);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		static Fixed &min(Fixed &one, Fixed &two);
		static const Fixed &min(const Fixed &one, const Fixed &two);
		static Fixed &max(Fixed &one, Fixed &two);
		static const Fixed &max(const Fixed &one, const Fixed &two);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
bool operator==(const Fixed &one, const Fixed &two);
bool operator!=(const Fixed &one, const Fixed &two);
bool operator<(const Fixed &one, const Fixed &two);
bool operator>(const Fixed &one, const Fixed &two);
bool operator<=(const Fixed &one, const Fixed &two);
bool operator>=(const Fixed &one, const Fixed &two);
Fixed operator+(Fixed one, const Fixed &two);
Fixed operator-(Fixed one, const Fixed &two);
Fixed operator*(Fixed one, const Fixed &two);
Fixed operator/(Fixed one, const Fixed &two);

#endif