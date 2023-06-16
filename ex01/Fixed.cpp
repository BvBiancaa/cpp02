/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bianca <bianca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:23:56 by bmuni             #+#    #+#             */
/*   Updated: 2023/06/16 17:51:44 by bianca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
    os << (obj.toFloat());
    return os;
}

int Fixed::SgetRawBits( void ) const
{
	return (this->store);
}

float Fixed::toFloat( void ) const
{
	return ((float)this->store / (1 << this->O));
}

int Fixed::toInt( void ) const
{
	return(this->store >> this->O);
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->store);
}

void Fixed::setRawBits(int const raw)
{
	this->store = raw;
}

Fixed	&Fixed::operator=(const Fixed &Fix)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &Fix)
		this->store = Fix.getRawBits();
	return (*this);
}

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->store = 0;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->store = (n << this->O);
}

Fixed::Fixed(const float n)
{
	this->store = ((int)roundf(n * (1 << this->O)));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}