/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_pow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:28:27 by mlantonn          #+#    #+#             */
/*   Updated: 2018/04/03 13:56:09 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static t_comp	comp_pow6(t_comp z)
{
	t_comp tmp;
	double zre2;
	double zim2;
	double zre4;
	double zim4;

	zre2 = z.re * z.re;
	zim2 = z.im * z.im;
	zre4 = zre2 * zre2;
	zim4 = zim2 * zim2;
	tmp.re = ((zre4 * zre2) - (15 * zre4 * zim2)) + \
		((15 * zre2 * zim4) - (zim4 * zim2));
	tmp.im = (6 * zre4 * z.re * z.im) - \
		(20 * zre2 * z.re * zim2 * z.im) + (6 * z.re * zim4 * z.im);
	return (tmp);
}

static t_comp	comp_pow5(t_comp z)
{
	t_comp tmp;
	double zre2;
	double zim2;
	double zre4;
	double zim4;

	zre2 = z.re * z.re;
	zim2 = z.im * z.im;
	zre4 = zre2 * zre2;
	zim4 = zim2 * zim2;
	tmp.re = (zre4 * z.re) - (10 * zre2 * z.re * zim2) + (5 * z.re * zim4);
	tmp.im = (5 * zre4 * z.im) - (10 * zre2 * zim2 * z.im) + (zim4 * z.im);
	return (tmp);
}

static t_comp	comp_pow4(t_comp z)
{
	t_comp tmp;
	double zre2;
	double zim2;

	zre2 = z.re * z.re;
	zim2 = z.im * z.im;
	tmp.re = (zre2 * zre2) - (6 * zre2 * zim2) + (zim2 * zim2);
	tmp.im = (4 * zre2 * z.re * z.im) - (4 * z.re * zim2 * z.im);
	return (tmp);
}

t_comp			comp_pow(t_comp z, int pow)
{
	if (pow == 6)
		return (comp_pow6(z));
	else if (pow == 5)
		return (comp_pow5(z));
	else if (pow == 4)
		return (comp_pow4(z));
	else if (pow == 3)
		return (comp_pow3(z));
	return (comp_pow2(z));
}

t_comp			comp_powneg(t_comp z, int pow)
{
	t_comp	tmp;
	double	nb;

	tmp = comp_pow(z, pow);
	nb = (tmp.re * tmp.re) + (tmp.im * tmp.im);
	if (nb == 0)
	{
		tmp.re = 500.0;
		tmp.im = 500.0;
	}
	else
	{
		tmp.re = tmp.re / nb;
		tmp.im = (-tmp.im) / nb;
	}
	return (tmp);
}
