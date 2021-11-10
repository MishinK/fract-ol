/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 04:25:56 by ashea             #+#    #+#             */
/*   Updated: 2021/07/04 04:25:57 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	ft_key_hook(int keycode, t_info *info)
{
	if (keycode == ESC_KEY)
		ft_close(info);
	if (keycode == SPACE_KEY)
	{
		info->id_fractal = 2;
		info->zoom /= 1.1;
	}
	if (keycode == SHIFT_KEY)
	{
		info->color_step += 20;
		free(info->set_color);
		ft_init_set_color(info);
	}
	if (keycode == UP_KEY)
		info->step_y += 50 * info->zoom;
	if (keycode == DOWN_KEY)
		info->step_y -= 50 * info->zoom;
	if (keycode == LEFT_KEY)
		info->step_x += 50 * info->zoom;
	if (keycode == RIGHT_KEY)
		info->step_x -= 50 * info->zoom;
	ft_drow_fractal(info);
	return (1);
}

int	ft_mouse_hook(int button, int x, int y, t_info *info)
{
	if (button == 4)
		info->zoom /= 1.1;
	if (button == 5)
		info->zoom *= 1.1;
	info->id_fractal = 2;
	ft_drow_fractal(info);
	return (1);
}

int	ft_mousemove_hook(int x, int y, t_info *info)
{
	if (info->id_fractal == 1)
	{
		info->c = complex((4.0 * (double)x
					- 2.0 * (double)info->res.x) / ((double)info->res.x),
				(2.0 * (double)info->res.y - 4.0
					* (double)y) / ((double)info->res.y));
		info->c.x -= (double)info->step_x / ((double)info->res.x) * info->zoom;
		info->c.y += (double)info->step_y / ((double)info->res.y) * info->zoom;
		info->R2 = (1.0l + sqrtl(1.0l + 4.0l * sqrtl(mod(info->c)))) / 2.0l;
		info->R2 = info->R2 * info->R2;
		ft_drow_fractal(info);
	}
	return (1);
}

int	ft_close(t_info *info)
{
	mlx_destroy_window(info->mlx.ptr, info->mlx.win);
	free(info->set_color);
	exit(0);
}

void	ft_loop(t_info *info)
{
	mlx_hook(info->mlx.win, 17, 0, ft_close, info);
	mlx_hook(info->mlx.win, 2, 0, ft_key_hook, info);
	mlx_hook(info->mlx.win, 4, 1L << 2, ft_mouse_hook, info);
	mlx_hook(info->mlx.win, 6, 1L << 6, ft_mousemove_hook, info);
	mlx_loop(info->mlx.ptr);
}
