/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 16:08:07 by mlantonn          #+#    #+#             */
/*   Updated: 2018/04/03 17:19:42 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	exit_all(t_all *all, int ret)
{
	int i;

	i = -1;
	while (++i < NB_THR && all->thr[i].buf)
		free(all->thr[i].buf);
	free(all->data.buf);
	if (all->data.mlx.img && all->data.mlx.mlx)
		mlx_destroy_image(all->data.mlx.mlx, all->data.mlx.img);
	if (all->data.mlx.win && all->data.mlx.mlx)
		mlx_destroy_window(all->data.mlx.mlx, all->data.mlx.win);
	exit(ret);
}
