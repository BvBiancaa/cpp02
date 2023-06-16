/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bianca <bianca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:24:04 by bmuni             #+#    #+#             */
/*   Updated: 2023/06/16 17:46:12 by bianca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (Fixed::store);
}

void Fixed::setRawBits(int const raw)
{
	(void)raw;
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
	Fixed::store = 0;
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