/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bianca <bianca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:29:22 by bmuni             #+#    #+#             */
/*   Updated: 2023/06/16 18:30:55 by bianca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(const float x, const float y);
		Point(const Fixed x, const Fixed y);
		Point(const Point &src);
		Point &operator=(const Point &src);
		~Point();
		Fixed getX() const;
		Fixed getY() const;
	
	private:
		const Fixed x;
		const Fixed y;
};

#endif