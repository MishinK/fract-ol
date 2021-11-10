/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 04:17:11 by ashea             #+#    #+#             */
/*   Updated: 2021/07/04 04:17:13 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "mlx.h"
# include "math.h"
# include "pthread.h"
# include "stdlib.h"
# include "stdio.h"

# define ESC_KEY 53
# define SPACE_KEY 49
# define RIGHT_KEY 124
# define LEFT_KEY 123
# define UP_KEY 126
# define DOWN_KEY 125
# define SPACE_KEY 49
# define SHIFT_KEY 257
# define THREADS 10
# define MAXITER 50

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_color;

typedef struct s_mlx
{
	void			*ptr;
	void			*win;
}					t_mlx;

typedef struct s_img
{
	void			*ptr;
	unsigned int	*addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_img;

typedef struct s_resolution
{
	int				x;
	int				y;
}					t_resolution;

typedef struct s_img_win
{
	void			*ptr;
	unsigned int	*addr;
}					t_img_win;

typedef struct s_info	t_info;

typedef struct s_thread
{
	int				id;
	t_info			*info;
}					t_thread;

typedef struct s_render
{
	pthread_t		threads[THREADS];
	t_thread		args[THREADS];
}					t_render;

typedef struct s_complex
{
	double			x;
	double			y;
}					t_complex;

typedef struct s_info
{
	t_mlx			mlx;
	t_resolution	res;
	t_img			img_win;
	unsigned int	*set_color;
	unsigned int	color_step;
	t_render		render;
	double			zoom;
	double			step_x;
	double			step_y;
	double			maxIter;
	int				id_fractal;
	unsigned	int	(*ft_frac)(int	x, int	y,	t_info	*info);
	t_complex		c;
	double			R2;
}					t_info;

t_complex		add(t_complex z1, t_complex z2);
t_complex		diff(t_complex z1, t_complex z2);
t_complex		multiply(t_complex z1, t_complex z2);
t_complex		divide(t_complex z1, t_complex z2);
double			mod(t_complex z);
t_complex		complex(double x, double y);
t_complex		polinom(t_complex z, t_complex c);
t_complex		polinom2(t_complex z, t_complex c);
int				ft_key_hook(int keycode, t_info *info);
int				ft_mouse_hook(int button, int x, int y, t_info *info);
int				ft_mousemove_hook(int x, int y, t_info *info);
int				ft_close(t_info *info);
void			ft_loop(t_info *info);
unsigned int	ft_create_color(unsigned char r,
					unsigned char g, unsigned char b);
void			ft_init_set_color(t_info *info);
t_img			ft_create_img_win(t_info *info);
void			ft_init(t_info *info);
unsigned int	ft_color_frac1(int x, int y, t_info *info);
unsigned int	ft_color_frac2(int x, int y, t_info *info);
unsigned int	ft_color_frac3(int x, int y, t_info *info);
void			*ft_render(void *part);
void			ft_drow_fractal(t_info *info);
void			ft_error(void);
void			ft_valid_arg(int argc, char **argv, t_info *info);
int				ft_atoi(const char *str);
int				ft_strcmp(const char *s1, const char *s2);

#endif