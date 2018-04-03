/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 16:41:05 by mlantonn          #+#    #+#             */
/*   Updated: 2018/04/03 13:17:42 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int		mandelbrot(t_data *data, t_comp c)
{
	t_comp	z;
	int		i;

	z.re = 0;
	z.im = 0;
	i = 0;
	while (++i <= data->imax)
	{
		z = comp_pow(z, data->pow);
		z.re += c.re;
		z.im += c.im;
		if (comp_abs(z) >= 2.0)
			return (data->col[data->nb_col][i % 5]);
	}
	return (0);
}
