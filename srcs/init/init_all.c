/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:36:51 by mlantonn          #+#    #+#             */
/*   Updated: 2018/03/28 13:26:42 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	init_all(t_all *all, int ac, char **av)
{
	check_arg(ac, av, &all->data);
	if (!(all->data.buf = ft_strnew(WIN_H * WIN_W * 4)))
		exit(-1);
	t_mlx_init(&all->data.mlx, av[1]);
	data_init(&all->data);
	all->move_expose = 0;
	all->aa_expose = 0;
	thr_init(all);
	draw_image(all);
	mlx_put_image_to_window(all->data.mlx.mlx, all->data.mlx.win,
		all->data.mlx.img, 0, 0);
}
