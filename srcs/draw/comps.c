/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:16:29 by mlantonn          #+#    #+#             */
/*   Updated: 2018/04/03 14:03:41 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

t_comp	comp_pow2(t_comp z)
{
	t_comp tmp;

	tmp.re = (z.re * z.re) - (z.im * z.im);
	tmp.im = z.re * z.im * 2.0;
	return (tmp);
}

t_comp	comp_pow3(t_comp z)
{
	t_comp tmp;

	tmp.re = (z.re * z.re * z.re) - (3 * z.re * z.im * z.im);
	tmp.im = (3 * z.re * z.re * z.im) - (z.im * z.im * z.im);
	return (tmp);
}

double	comp_abs(t_comp z)
{
	z.re = z.re * z.re;
	z.im = z.im * z.im;
	return (sqrt(z.re + z.im));
}
