/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:14:03 by mlantonn          #+#    #+#             */
/*   Updated: 2018/03/29 02:27:57 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void	draw_pixel(t_thr *thr, t_comp z, int index)
{
	int ret;

	if (thr->aa == 1)
	{
		ret = thr->da->frac(thr->da, z);
		thr->buf[index] = ret;
		thr->buf[index + 1] = ret >> 8;
		thr->buf[index + 2] = ret >> 16;
	}
	else
		anti_alias(thr, z, index);
}

void		*draw_thread(void *arg)
{
	t_thr	*thr;
	t_comp	z;
	int		x;
	int		y;

	thr = (t_thr *)arg;
	z.im = thr->da->z0.im + (thr->y * thr->da->coeff);
	y = -1;
	while (++y < WIN_H / NB_THR)
	{
		z.re = thr->da->z0.re;
		x = -1;
		while (++x < WIN_W)
		{
			draw_pixel(thr, z, (y * WIN_W * 4) + (x * 4));
			z.re += thr->da->coeff;
		}
		z.im += thr->da->coeff;
	}
	pthread_exit(NULL);
}
