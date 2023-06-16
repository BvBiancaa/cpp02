/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bianca <bianca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:28:40 by bmuni             #+#    #+#             */
/*   Updated: 2023/06/16 19:03:18 by bianca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : store(0)
{
  	return ;
}

Fixed::Fixed(const int i)
{
  	this->store = i << O;
}

Fixed::Fixed(const float f)
{
 	this->store = roundf(f * (1 << this->O));
}

Fixed::~Fixed()
{
 	 return ;
}

Fixed::Fixed(const Fixed &fix)
{
	this->store = fix.getRawBits();
}

void Fixed::swap(Fixed &one, Fixed &two)
{
  	std::swap(one.store, two.store);
}

Fixed &Fixed::operator=(Fixed fix)
{
	Fixed::swap(*this, fix);
	return *this;
}

Fixed &Fixed::operator++()
{
	this->store++;
	return *this;
}

Fixed Fixed::operator++(int n)
{
	(void)n;
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed &Fixed::operator--()
{
	this->store--;
	return *this;
}

Fixed Fixed::operator--(int n)
{
	(void)n;
	Fixed tmp(*this);
	operator--();
	return tmp;
}

Fixed Fixed::operator+=(const Fixed &fix)
{
  	this->store = this->store + fix.store;
	return *this;
}

Fixed Fixed::operator-=(const Fixed &fix)
{
  	this->store = this->store - fix.store;
	return *this;
}

Fixed Fixed::operator*=(const Fixed &fix)
{
	this->store = ((long long)this->store * (long long)fix.getRawBits()) >> this->O;
	return *this;
}

Fixed Fixed::operator/=(const Fixed &fix)
{
  	this->store = ((long long)this->store << this->O) / fix.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	return this->store;
}

void Fixed::setRawBits(int const raw)
{
	this->store = raw;
}

float Fixed::toFloat(void) const
{
 	return (float)this->store / (1 << this->O);
}

int Fixed::toInt(void) const
{
  	return this->store >> this->O;
}

Fixed &Fixed::min(Fixed &one, Fixed &two)
{
/*   if (one < two)
    return (one);
  else
    return (two); */
	return one < two ? one : one;
}

const Fixed &Fixed::min(const Fixed &one, const Fixed &two)
{
/*     if (one < two)
    return (one);
  else
    return (two); */
  	return one < two ? one : two;
}

Fixed &Fixed::max(Fixed &one, Fixed &two)
{
  /*     if (one > two)
    return (one);
  else
    return (two); */
	return one > two ? one : two;
}

const Fixed &Fixed::max(const Fixed &one, const Fixed &two)
{
    /*     if (one > two)
    return (one);
  else
    return (two); */
	return one > two ? one : two;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

bool operator==(const Fixed &one, const Fixed &two)
{
/*   if (one.getRawBits() == two.getRawBits())
    return (true);
  else
    return (false); */
  	return one.getRawBits() == two.getRawBits() ? true : false;
}

bool operator!=(const Fixed &one, const Fixed &two)
{
  /*   if (one.getRawBits() != two.getRawBits())
    return (true);
  else
    return (false); */
  	return one.getRawBits() != two.getRawBits() ? true : false;
}

bool operator<(const Fixed &one, const Fixed &two)
{
  /*   if (one.getRawBits() < two.getRawBits())
    return (true);
  else
    return (false); */
  	return one.getRawBits() < two.getRawBits() ? true : false;
}

bool operator>(const Fixed &one, const Fixed &two)
{
  /*   if (one.getRawBits() > two.getRawBits())
    return (true);
  else
    return (false); */
  	return one.getRawBits() > two.getRawBits() ? true : false;
}

bool operator<=(const Fixed &one, const Fixed &two)
{
  /*   if (one.getRawBits() <= two.getRawBits())
    return (true);
  else
    return (false); */
  	return one.getRawBits() <= two.getRawBits() ? true : false;
}

bool operator>=(const Fixed &one, const Fixed &two)
{
  /*   if (one.getRawBits() >= two.getRawBits())
    return (true);
  else
    return (false); */
  	return one.getRawBits() >= two.getRawBits() ? true : false;
}

Fixed operator+(Fixed one, const Fixed &two)
{
	one += two;
	return one;
}

Fixed operator-(Fixed one, const Fixed &two)
{
	one -= two;
	return one;
}

Fixed operator*(Fixed one, const Fixed &two)
{
	one *= two;
	return one;
}

Fixed operator/(Fixed one, const Fixed &two)
{
	one /= two;
	return one;
}