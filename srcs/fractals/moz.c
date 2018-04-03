/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moz.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 14:29:05 by mlantonn          #+#    #+#             */
/*   Updated: 2018/04/03 15:04:31 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int		moz(t_data *data, t_comp z)
{
	int	i;

	i = 0;
	while (++i <= data->imax)
	{
		if (i > 1)
			z = comp_powneg(z, data->pow);
		z.re = fabs(z.re) + data->c.re;
		z.im = fabs(z.im) + data->c.im;
		if (comp_abs(z) >= 2.0)
			return (data->col[data->nb_col][i % 5]);
	}
	return (0);
}
