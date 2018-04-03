/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandisk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 15:33:42 by mlantonn          #+#    #+#             */
/*   Updated: 2018/04/03 15:34:33 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int		mandisk(t_data *data, t_comp c)
{
	t_comp	z;
	int		i;

	z.re = 0;
	z.im = 0;
	i = 0;
	while (++i <= data->imax)
	{
		if (i > 1)
			z = comp_powneg(z, data->pow);
		z.im *= -1;
		z.re += c.re;
		z.im += c.im;
		if (comp_abs(z) >= 2.0)
			return (data->col[data->nb_col][i % 5]);
	}
	return (0);
}
