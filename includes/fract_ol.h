/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 20:44:16 by mlantonn          #+#    #+#             */
/*   Updated: 2018/04/03 16:15:11 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <pthread.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "structs.h"
# include "defines.h"
# include "keys.h"

/*
**	Drawing functions.
*/
void	draw_image(t_all *all);
void	*draw_thread(void *arg);
void	anti_alias(t_thr *thr, t_comp z, int index);
void	blur(t_data *data, int nb);

/*
**	Fractal functions.
*/
int		mandelbrot(t_data *data, t_comp c);
int		julia(t_data *data, t_comp z);
int		newton(t_data *data, t_comp z);
int		mandelneg(t_data *data, t_comp c);
int		julneg(t_data *data, t_comp z);
int		newtwo(t_data *data, t_comp z);
int		mandelbar(t_data *data, t_comp c);
int		burning_ship(t_data *data, t_comp c);
int		moz(t_data *data, t_comp z);
int		mandisk(t_data *data, t_comp c);

/*
**	Functions doing complex numbers operations, used in the fractal functions.
*/
double	comp_abs(t_comp z);
t_comp	comp_pow(t_comp z, int pow);
t_comp	comp_pow2(t_comp z);
t_comp	comp_pow3(t_comp z);
t_comp	comp_powneg(t_comp z, int pow);

/*
**	Event functions.
*/
int		change_aa(t_all *all, int key);
void	change_color(t_all *all, int key);
void	change_iter(t_all *all, int key);
void	change_pow(t_all *all, int key);
void	change_blur(t_all *all, int key);
void	move(t_all *all, int key);
void	move_julia(t_all *all, int key);
void	zoom(t_all *all, int key, int x, int y);
void	reset_all(t_all *all, int key);
void	redraw(t_all *all);

/*
**	Functions used to initialize the different structures.
*/
void	init_all(t_all *all, int ac, char **av);
void	data_init(t_data *data);
void	thr_init(t_all *all);
void	t_mlx_init(t_mlx *mlx, char *file);
int		img_init(t_mlx *mlx);
void	color_init(int color[5][5]);

/*
**	Checks if there is an argument and if it is valid. If there is a valid
**	argument, initialize the (*frac) ptr in t_data, or shows options. Else,
**	shows usage.
*/
void	check_arg(int ac, char **arg, t_data *data);

/*
**	Frees everything that has to be freed.
*/
void	exit_all(t_all *all, int ret);

#endif
