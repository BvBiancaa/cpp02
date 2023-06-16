/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bianca <bianca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:23:13 by bmuni             #+#    #+#             */
/*   Updated: 2023/06/16 17:55:22 by bianca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : store(0) 
{
//	cout << "Default constructor called" << endl;
	return;
}

Fixed::Fixed( int const num ) : store(num << this->O)
{
//	cout << "Int constructor called" << endl;
	return;
}

Fixed::Fixed( float const ft ) : store((int)roundf(ft * (1 << this->O)))
{
//	cout << "Float constructor called" << endl;
	return;
}

Fixed::Fixed( Fixed const & fx )
{
//	cout << "Copy constructor called" << endl;
	*this = fx;
	return;
}

Fixed::~Fixed( void )
{
//	cout << "Destructor called" << endl;
	return;
}

bool	Fixed::operator>(Fixed const & fx) const{
	return (this->store > fx.getRawBits());
}

bool	Fixed::operator<(Fixed const & fx) const{
	return (this->store < fx.getRawBits());
}

bool	Fixed::operator>=(Fixed const & fx) const{
	return (this->store >= fx.getRawBits());
}

bool	Fixed::operator<=(Fixed const & fx) const{
	return (this->store <= fx.getRawBits());
}

bool	Fixed::operator==(Fixed const & fx) const{
	return (this->store == fx.getRawBits());
}

bool	Fixed::operator!=(Fixed const & fx) const{
	return (this->store != fx.getRawBits());
}

Fixed&			Fixed::min(Fixed& a, Fixed& b) {
	return (a < b ? a : b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b ? a : b);
}

Fixed&			Fixed::max(Fixed& a, Fixed& b) {
	return (a > b ? a : b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b ? a : b);
}

Fixed&	Fixed::operator=( Fixed const & fx) {
//	cout << "Assignation operator called" << endl;
	this->setRawBits(fx.getRawBits());
	return *this;
}

Fixed	Fixed::operator+(Fixed const & fx) const {
	Fixed	newFx;
	newFx.setRawBits(this->store + fx.getRawBits());
	return newFx;
}

Fixed	Fixed::operator-(Fixed const & fx) const {
	Fixed	newFx;
	newFx.setRawBits(this->store - fx.getRawBits());
	return newFx;
}

Fixed	Fixed::operator*(Fixed const & fx) const {
	Fixed	newFx;
	newFx.setRawBits((this->store * fx.getRawBits()) >> this->O);
	return newFx;
}

Fixed	Fixed::operator/(Fixed const & fx) const {
	Fixed	newFx;
	newFx.setRawBits((this->store << this->O) / fx.getRawBits());
	return newFx;
}

Fixed&	Fixed::operator++( void ) {
	++(this->store);
	return *this;
}

Fixed	Fixed::operator++( int num ) {
	(void)num;
	Fixed newFx(*this);
	++(this->store);
	return newFx;
}

Fixed&	Fixed::operator--( void ) {
	--(this->store);
	return *this;
}

Fixed	Fixed::operator--( int num ) {
	(void)num;
	Fixed newFx(*this);
	--(this->store);
	return newFx;
}

int		Fixed::getRawBits( void ) const {
//	cout << "getRawBits member function called" << endl;
	return (this->store);
}

void	Fixed::setRawBits( int const raw ) {
	this->store = raw;
	return;
}

float	Fixed::toFloat( void ) const {
	return ((float)this->store / (1 << this->O));
}

int		Fixed::toInt( void ) const {
	return (this->store >> this->O);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
    os << (obj.toFloat());
    return os;
}