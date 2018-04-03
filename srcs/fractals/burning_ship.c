/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 14:19:21 by mlantonn          #+#    #+#             */
/*   Updated: 2018/04/03 14:27:59 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int		burning_ship(t_data *data, t_comp c)
{
	t_comp	z;
	int		i;

	z.re = 0;
	z.im = 0;
	i = 0;
	while (++i <= data->imax)
	{
		z = comp_pow(z, data->pow);
		z.im = fabs(z.im);
		z.re += c.re;
		z.im += c.im;
		if (comp_abs(z) >= 2.0)
			return (data->col[data->nb_col][i % 5]);
	}
	return (0);
}
