#include "fractal.h"

void	ft_error(void)
{
	perror("Error: invalid arg, expected:");
	perror(" |Julia [int] [int]| or |Mandelbrot| or |Newton|");
	exit(-1);
}

void	ft_valid_arg(int argc, char **argv, t_info *info)
{
	if (argc != 2 && argc != 4)
		ft_error();
	if (ft_strcmp(argv[1], "Julia") == 0 && argc == 4)
	{
		info->c = complex((double)ft_atoi(argv[2]) / 1000.0,
				(double)ft_atoi(argv[3]) / 1000.0);
		info->R2 = (1.0l + sqrtl(1.0l + 4.0l * sqrtl(mod(info->c)))) / 2.0l;
		info->R2 = info->R2 * info->R2;
		info->id_fractal = 1;
		info->ft_frac = ft_color_frac1;
		return ;
	}
	if (ft_strcmp(argv[1], "Mandelbrot") == 0 && argc == 2)
	{
		info->id_fractal = 2;
		info->ft_frac = ft_color_frac2;
		return ;
	}
	if (ft_strcmp(argv[1], "Newton") == 0 && argc == 2)
	{
		info->id_fractal = 3;
		info->ft_frac = ft_color_frac3;
		return ;
	}
	ft_error();
}

int	main(int argc, char **argv)
{
	t_info	info;

	ft_valid_arg(argc, argv, &info);
	ft_init(&info);
	ft_loop(&info);
	exit(0);
}
