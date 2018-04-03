/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 17:03:22 by mlantonn          #+#    #+#             */
/*   Updated: 2018/04/03 14:07:09 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static int	check_newton(t_comp z, t_comp r, t_data *data, int index)
{
	t_comp tmp;

	tmp.re = z.re - r.re;
	tmp.im = z.im - r.im;
	if (comp_abs(tmp) < 0.0001)
		return (data->col[data->nb_col][index % 5]);
	return (0);
}

static void	calc(t_comp *z)
{
	t_comp	tmp[3];
	double	nb;

	tmp[0] = comp_pow3(*z);
	tmp[0].re -= 1.0;
	tmp[1] = comp_pow2(*z);
	tmp[1].re *= 3.0;
	tmp[1].im *= 3.0;
	nb = (tmp[1].re * tmp[1].re) + (tmp[1].im * tmp[1].im);
	tmp[2].re = ((tmp[0].re * tmp[1].re) + (tmp[0].im * tmp[1].im)) / nb;
	tmp[2].im = ((tmp[0].im * tmp[1].re) - (tmp[0].re * tmp[1].im)) / nb;
	z->re -= tmp[2].re;
	z->im -= tmp[2].im;
}

int			newton(t_data *data, t_comp z)
{
	t_comp	r[3];
	int		col;
	int		i;

	r[0].re = 1;
	r[0].im = 0;
	r[1].re = -0.5;
	r[1].im = sin(2 * PI / 3);
	r[2].re = -0.5;
	r[2].im = -sin(2 * PI / 3);
	i = 0;
	while (++i <= data->imax)
	{
		if ((col = check_newton(z, r[0], data, i)))
			return (col);
		if ((col = check_newton(z, r[1], data, i)))
			return (col);
		if ((col = check_newton(z, r[2], data, i)))
			return (col);
		calc(&z);
	}
	return (0);
}
