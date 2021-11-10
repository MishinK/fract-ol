/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 04:27:42 by ashea             #+#    #+#             */
/*   Updated: 2021/07/04 04:27:43 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

unsigned int	ft_create_color(unsigned char r,
	unsigned char g, unsigned char b)
{
	return (r << 16 | g << 8 | b);
}

void	ft_init_set_color(t_info *info)
{
	int	i;
	int	diff;

	i = 0;
	diff = 0;
	info->set_color = (unsigned int *)malloc(sizeof(unsigned int)
			* (info->maxIter + 2));
	info->set_color[0] = ft_create_color(info->color_step + diff / 2,
			info->color_step + diff, info->color_step + 250);
	while (i < info->maxIter)
	{
		diff += 35;
		i++;
		info->set_color[i] = ft_create_color(info->color_step + diff / 2,
				info->color_step + diff, info->color_step + 250);
	}
	info->set_color[i + 1] = ft_create_color(info->color_step + diff / 2,
			info->color_step + diff, info->color_step + 250);
}

t_img	ft_create_img_win(t_info *info)
{
	t_img	img;

	img.ptr = mlx_new_image(info->mlx.ptr, info->res.x, info->res.y);
	img.addr = (unsigned int *)mlx_get_data_addr(img.ptr,
			&img.bits_per_pixel, &img.size_line, &img.endian);
	return (img);
}

void	ft_init(t_info *info)
{
	info->mlx.ptr = mlx_init();
	mlx_get_screen_size(info->mlx.ptr, &info->res.x, &info->res.y);
	info->res.x /= 2;
	info->res.y /= 2;
	info->mlx.win = mlx_new_window(info->mlx.ptr,
			info->res.x, info->res.y, "THIS IS FRACTAL!!!");
	info->img_win = ft_create_img_win(info);
	info->maxIter = MAXITER;
	info->color_step = 0;
	info->zoom = 1.0;
	info->step_x = 0;
	info->step_y = 0;
	ft_init_set_color(info);
	ft_drow_fractal(info);
}
