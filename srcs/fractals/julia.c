/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:29:49 by mlantonn          #+#    #+#             */
/*   Updated: 2018/04/03 13:17:48 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int		julia(t_data *data, t_comp z)
{
	int	i;

	i = 0;
	while (++i <= data->imax)
	{
		z = comp_pow(z, data->pow);
		z.re += data->c.re;
		z.im += data->c.im;
		if (comp_abs(z) >= 2.0)
			return (data->col[data->nb_col][i % 5]);
	}
	return (0);
}
