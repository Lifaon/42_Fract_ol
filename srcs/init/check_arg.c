/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 17:21:13 by mlantonn          #+#    #+#             */
/*   Updated: 2018/04/03 17:31:47 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void	print_usage(void)
{
	ft_putendl("Usage : ./fractol \'Fractal\'");
	ft_putendl("Fractals :");
	ft_putendl("- Mandelbrot");
	ft_putendl("- Julia");
	ft_putendl("- Newton");
	ft_putendl("- Mandelneg");
	ft_putendl("- Julneg");
	ft_putendl("- Newtwo");
	ft_putendl("- Mandelbar");
	ft_putendl("- Burning_ship");
	ft_putendl("- Mandisk");
	ft_putendl("- MoZ");
	ft_putendl("To show options : ./fractol \'options\'");
}

static void	print_options(void)
{
	ft_putendl("Move ___________________  W A S D / arrows\n\
Move (Julia type) ______  I J K L\n\
Move (toggle cursor) ___  ~\n\
________________________\n\
Zoom (on cursor) _______  Mouse wheel\n\
Zoom (center) __________  + / -\n\
Zoom (reset) ___________  SPACE\n\
________________________\n\
Color (next one) _______  TAB\n\
Color (choose) _________  1 / 2 / 3 / 4 / 5\n\
________________________\n\
Iterations (increase) __  Z\n\
Iterations (decrease) __  X\n\
Iterations (reset) _____  C\n\
________________________\n\
Power (increase) _______  R\n\
Power (decrease) _______  F\n\
________________________\n\
SSAA (toggle on) _______  Q + choose a factor\n\
SSAA (toggle off) ______  E\n\
SSAA (choose a factor) _  2 / 3 / 4 / 5 / 6 / 7 / 8\n________________________\n\
Blur (toggle on / off) _  V\n\
Blur (increase) ________  B\n\
Blur (decrease) ________  N\n\
Blur (reset) ___________  M");
}

static int	check_arg2(char *arg, t_data *data)
{
	data->frac = NULL;
	if (ft_strcmp(arg, "Mandelbrot") == 0)
		data->frac = mandelbrot;
	else if (ft_strcmp(arg, "Julia") == 0)
		data->frac = julia;
	else if (ft_strcmp(arg, "Newton") == 0)
		data->frac = newton;
	else if (ft_strcmp(arg, "Mandelneg") == 0)
		data->frac = mandelneg;
	else if (ft_strcmp(arg, "Julneg") == 0)
		data->frac = julneg;
	else if (ft_strcmp(arg, "Newtwo") == 0)
		data->frac = newtwo;
	else if (ft_strcmp(arg, "Mandelbar") == 0)
		data->frac = mandelbar;
	else if (ft_strcmp(arg, "Burning_ship") == 0)
		data->frac = burning_ship;
	else if (ft_strcmp(arg, "Mandisk") == 0)
		data->frac = mandisk;
	else if (ft_strcmp(arg, "MoZ") == 0)
		data->frac = moz;
	return (data->frac ? 0 : -1);
}

void		check_arg(int ac, char **arg, t_data *data)
{
	if (ac != 2)
	{
		print_usage();
		exit(-1);
	}
	if (ft_strcmp(arg[1], "options") == 0)
	{
		print_options();
		exit(0);
	}
	if (check_arg2(arg[1], data))
	{
		print_usage();
		exit(-1);
	}
}
