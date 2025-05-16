/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:45:13 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/16 15:15:38 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main( void )
{
	const Point a(0, 0);
	const Point b(5, 0);
	const Point c(0, 5);
	
	const Point point(1, 1);
	const Point point_out(5.1, 1);
	std::cout << "Point with value: (" << point.getX() << ", " << point.getY() << ") Should be in the triangle" << std::endl;
	
	if (bsp(a, b, c, point))
		std::cout << "The point is inside the triangle." << std::endl;
	else
		std::cout << "The point is outside the triangle." << std::endl;
	std::cout << "Point with value: (" << point_out.getX() << ", " << point_out.getY() << ") Should be out of the triangle" << std::endl;
	if (bsp(a, b, c, point_out))
		std::cout << "The point is inside the triangle." << std::endl;
	else
		std::cout << "The point is outside the triangle." << std::endl;
	return (0);
}
