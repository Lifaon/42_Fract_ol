/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:48:05 by mlantonn          #+#    #+#             */
/*   Updated: 2018/04/03 16:13:49 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	data_init(t_data *data)
{
	data->z0.im = -1.0 * (WIN_H + 1) / COEFF / 2.0;
	data->z0.re = -1.5 * WIN_W / COEFF / 3.0;
	data->c.im = -0.085;
	data->c.re = -0.77;
	data->zoom = 1.0;
	data->coeff = (1.0 / COEFF) / data->zoom;
	data->blur_expose = 0;
	data->blur_coeff = 2;
	data->pow = 2;
	if (data->frac == newton)
		data->imax = 20;
	else if (data->frac == mandelneg || data->frac == mandisk)
		data->imax = 25;
	else if (data->frac == newtwo)
		data->imax = 30;
	else if (data->frac == julneg || data->frac == moz)
		data->imax = 40;
	else
		data->imax = 100;
	data->nb_col = 0;
	color_init(data->col);
}
