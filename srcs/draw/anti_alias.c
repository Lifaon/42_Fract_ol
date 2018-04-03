/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_alias.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 15:04:48 by mlantonn          #+#    #+#             */
/*   Updated: 2018/04/03 13:50:18 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static char	blend(char *buf, int size)
{
	int i;
	int	nb;

	i = -1;
	nb = 0;
	while (++i < size)
		nb += (int)(unsigned char)buf[i];
	nb /= i;
	return ((char)nb);
}

void		anti_alias(t_thr *thr, t_comp z, int index)
{
	t_comp	z2;
	int		x;
	int		y;
	int		ret;

	y = -1;
	z2.im = z.im;
	while (++y < thr->aa)
	{
		x = -1;
		z2.re = z.re;
		while (++x < thr->aa)
		{
			ret = thr->da->frac(thr->da, z2);
			thr->r[x + (y * thr->aa)] = ret;
			thr->g[x + (y * thr->aa)] = ret >> 8;
			thr->b[x + (y * thr->aa)] = ret >> 16;
			z2.re += thr->da->coeff / (double)thr->aa;
		}
		z2.im += thr->da->coeff / (double)thr->aa;
	}
	thr->buf[index] = blend(thr->r, thr->aa * thr->aa);
	thr->buf[index + 1] = blend(thr->g, thr->aa * thr->aa);
	thr->buf[index + 2] = blend(thr->b, thr->aa * thr->aa);
}
