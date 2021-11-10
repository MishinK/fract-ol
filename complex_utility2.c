/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_utility2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 04:24:25 by ashea             #+#    #+#             */
/*   Updated: 2021/07/04 04:24:27 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

double	mod(t_complex z)
{
	return (z.x * z.x + z.y * z.y);
}

t_complex	complex(double x, double y)
{
	t_complex	z;

	z.x = x;
	z.y = y;
	return (z);
}

t_complex	polinom(t_complex z, t_complex c)
{
	t_complex	f;

	f = add(multiply(z, z), c);
	return (f);
}

t_complex	polinom2(t_complex z, t_complex c)
{
	t_complex	f;
	t_complex	z2;
	t_complex	z2_3;
	t_complex	z3;
	t_complex	c1;

	z2 = multiply(z, z);
	z2_3 = complex(3 * z2.x, 3 * z2.y);
	z3 = multiply(multiply(z, z), z);
	c1 = complex(1.0, 1.0);
	f = diff(z, divide(diff(z3, c1), z2_3));
	return (f);
}
