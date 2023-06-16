/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bianca <bianca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:28:32 by bmuni             #+#    #+#             */
/*   Updated: 2023/06/16 18:59:00 by bianca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	getMedium(Point const D1, Point const D2)
{
	return (D1.getX() * D2.getY() - D1.getY() * D2.getX());
}

Point	vector(Point a, Point b)
{
  	return (Point(b.getX() - a.getX(), b.getY() - a.getY()));
}

int	getD(Point a, Point b, Point c)
{
	Point const D1 = vector(a, b);
	Point const D2 = vector(b, c);
	Fixed D = getMedium(D1, D2);
	if (D > 0)
		return (1);
	else if (D == 0)
		return (0);
	else
		return (-1);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	int condition;
  
	condition = getD(a, b, point) + getD(b, c, point) + getD(c, a, point);
	if (condition < 0)
		condition *= -1;
	if (condition == 3)
    		return (true);
  	return (false);
}