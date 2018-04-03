/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 16:59:09 by mlantonn          #+#    #+#             */
/*   Updated: 2018/04/03 16:14:38 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void	put_threads(t_all *all)
{
	int i;
	int	j;
	int	nb;

	i = -1;
	nb = WIN_W * WIN_H * 4 / NB_THR;
	while (++i < NB_THR)
	{
		j = -1;
		while (++j < nb)
			all->data.mlx.img_str[j + (i * nb)] = all->thr[i].buf[j];
	}
}

void		draw_image(t_all *all)
{
	int	i;
	int	j;

	i = -1;
	while (++i < NB_THR)
	{
		if (pthread_create(&all->thr[i].th, NULL, draw_thread, &all->thr[i]))
		{
			j = -1;
			while (++j < i)
				pthread_cancel(all->thr[j].th);
			exit_all(all, -1);
		}
	}
	i = -1;
	while (++i < NB_THR)
		pthread_join(all->thr[i].th, NULL);
	put_threads(all);
	if (all->data.blur_expose)
		blur(&all->data, all->data.blur_coeff);
}
