/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 17:49:38 by mlantonn          #+#    #+#             */
/*   Updated: 2018/04/03 16:13:51 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int		change_z(int x, int y, t_all *all)
{
	if (all->move_expose == 0 || all->aa_expose)
		return (1);
	all->data.c.re = (x - (WIN_W / 2)) * (1.0 / COEFF);
	all->data.c.im = (y - (WIN_H / 2)) * (1.0 / COEFF);
	redraw(all);
	return (0);
}

int		mouse_actions(int key, int x, int y, t_all *all)
{
	if (all->move_expose || all->aa_expose)
		return (1);
	zoom(all, key, x, y);
	return (0);
}

int		key_actions(int key, t_all *all)
{
	if (key == K_ESC)
		exit_all(all, 0);
	if (all->aa_expose != 1 && key == K_TILT && (all->data.frac == julia || \
		all->data.frac == julneg || all->data.frac == moz))
		all->move_expose = all->move_expose ? 0 : 1;
	if (all->move_expose)
		return (1);
	if (change_aa(all, key))
		return (0);
	change_color(all, key);
	change_iter(all, key);
	change_pow(all, key);
	change_blur(all, key);
	move(all, key);
	move_julia(all, key);
	zoom(all, key, WIN_W / 2, WIN_H / 2);
	reset_all(all, key);
	return (0);
}

int		main(int ac, char **av)
{
	t_all	all;

	init_all(&all, ac, av);
	mlx_mouse_hook(all.data.mlx.win, mouse_actions, &all);
	mlx_hook(all.data.mlx.win, 2, 3, key_actions, &all);
	mlx_hook(all.data.mlx.win, 6, (1L << 6), change_z, &all);
	return (mlx_loop(all.data.mlx.mlx));
}
