/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_utility.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 04:24:18 by ashea             #+#    #+#             */
/*   Updated: 2021/07/04 04:24:20 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_complex	add(t_complex z1, t_complex z2)
{
	t_complex	z;

	z.x = z1.x + z2.x;
	z.y = z1.y + z2.y;
	return (z);
}

t_complex	diff(t_complex z1, t_complex z2)
{
	t_complex	z;

	z.x = z1.x - z2.x;
	z.y = z1.y - z2.y;
	return (z);
}

t_complex	multiply(t_complex z1, t_complex z2)
{
	t_complex	z;

	z.x = z1.x * z2.x - z1.y * z2.y;
	z.y = z1.x * z2.y + z2.x * z1.y;
	return (z);
}

t_complex	divide(t_complex z1, t_complex z2)
{
	t_complex	z;

	z.x = (z1.x * z2.x + z1.y * z2.y) / (z2.x * z2.x + z2.y * z2.y);
	z.y = (z2.x * z1.y - z1.x * z2.y) / (z2.x * z2.x + z2.y * z2.y);
	return (z);
}
