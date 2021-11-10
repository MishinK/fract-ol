/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 04:31:29 by ashea             #+#    #+#             */
/*   Updated: 2021/07/04 04:31:30 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

unsigned int	ft_color_frac1(int x, int y, t_info *info)
{
	t_complex	z;
	int			i;

	z = complex(info->zoom * (4.0 * (double)x - 2.0
				* (double)info->res.x) / ((double)info->res.x),
			info->zoom * (2.0 * (double)info->res.y
				- 4.0 * (double)y) / ((double)info->res.y));
	z.x -= (double)info->step_x / ((double)info->res.x);
	z.y += (double)info->step_y / ((double)info->res.y);
	i = 0;
	if (mod(z) > info->R2)
		return (info->set_color[i]);
	while (i < info->maxIter)
	{
		z = polinom(z, info->c);
		if (mod(z) > info->R2)
			return (info->set_color[i + 1]);
		i++;
	}
	return (info->set_color[i + 1]);
}

unsigned int	ft_color_frac2(int x, int y, t_info *info)
{
	t_complex	c;
	t_complex	z;
	int			i;

	c = complex(info->zoom * (4.0 * (double)x
				- 2.0 * (double)info->res.x) / ((double)info->res.x),
			info->zoom * (2.0 * (double)info->res.y
				- 4.0 * (double)y) / ((double)info->res.y));
	c.x -= (double)info->step_x / ((double)info->res.x);
	c.y += (double)info->step_y / ((double)info->res.y);
	z = complex(0, 0);
	i = 0;
	while (i < info->maxIter)
	{
		z = polinom(z, c);
		if (mod(z) > 4)
			return (info->set_color[i + 1]);
		i++;
	}
	return (info->set_color[i + 1]);
}

unsigned int	ft_color_frac3(int x, int y, t_info *info)
{
	t_complex	z;
	int			i;

	z = complex(info->zoom * (4.0 * (double)x
				- 2.0 * (double)info->res.x) / ((double)info->res.x),
			info->zoom * (2.0 * (double)info->res.y
				- 4.0 * (double)y) / ((double)info->res.y));
	z.x -= (double)info->step_x / ((double)info->res.x);
	z.y += (double)info->step_y / ((double)info->res.y);
	i = 0;
	if (mod(z) > 20)
		return (info->set_color[i]);
	while (i < info->maxIter)
	{
		z = polinom2(z, info->c);
		if (mod(z) > 20)
			return (info->set_color[i + 1]);
		i++;
	}
	return (info->set_color[i + 1]);
}

void	*ft_render(void *part)
{
	t_thread	*t;
	int			i;
	int			j;
	int			pos;

	t = (t_thread *)part;
	i = t->info->res.x / THREADS * t->id;
	while (i < t->info->res.x / THREADS * (t->id + 1))
	{
		j = 0;
		while (j < t->info->res.y)
		{
			pos = j * t->info->img_win.size_line / 4 + i;
			t->info->img_win.addr[pos] = t->info->ft_frac(i, j, t->info);
			j++;
		}
		i++;
	}
	return (NULL);
}

void	ft_drow_fractal(t_info *info)
{
	int			i;
	t_render	*r;

	i = 0;
	r = &info->render;
	while (i < THREADS)
	{
		r->args[i].id = i;
		r->args[i].info = info;
		pthread_create(r->threads + i, NULL, ft_render, &(r->args[i]));
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_join(r->threads[i], NULL);
		i++;
	}
	mlx_put_image_to_window(info->mlx.ptr,
		info->mlx.win, info->img_win.ptr, 0, 0);
}
