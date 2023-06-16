/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bianca <bianca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:29:14 by bmuni             #+#    #+#             */
/*   Updated: 2023/06/16 18:31:28 by bianca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

Point::Point() : x(Fixed(0)) , y(Fixed(0))
{
	return;
}

Point::Point(const float x, const float y) : x(Fixed(x)) , y(Fixed(y))
{
	return;
}

Point::Point(const Fixed x, const Fixed y) : x(x) , y(y)
{
	return;
}

Point::Point(const Point &src) : x(src.getX()) , y(src.getY())
{
	return;
}

Point::~Point()
{
	return;
}

Point &Point::operator=(const Point &src)
{
	(void)src;
	return *this;
}

Fixed Point::getX() const
{
	return (this->x);
}

Fixed Point::getY() const
{
	return (this->y);
}

