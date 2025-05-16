/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:18:00 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/16 14:40:42 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static bool magic_formula(Point const a, Point const b, Point const point)
{
    if ((a.getX() - point.getX()) * (b.getY() - point.getY()) - (a.getY() - point.getY()) * (b.getX() - point.getX()) >= 0) {
        return (true);
    }
    return (false);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	bool ab = magic_formula(a, b, point);
	bool bc = magic_formula(b, c, point);
	bool ca = magic_formula(c, a, point);
	if (ab == bc && bc == ca)
		return (true);
	return (false);
}
