/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:21:18 by mlantonn          #+#    #+#             */
/*   Updated: 2018/03/29 13:41:08 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#define ZOOM_COEFF 1.15
#define ZOOM_MIN 0.30
#define ZOOM_MAX 4000000000000.0

void	zoom(t_all *all, int key, int x, int y)
{
	double tmpy;
	double tmpx;

	if ((key == M_WHE_D || key == K_LESS || key == K_NP_LESS) &&
		all->data.zoom <= ZOOM_MIN)
		return ;
	if ((key == M_WHE_U || key == K_PLUS || key == K_NP_PLUS) &&
		all->data.zoom >= ZOOM_MAX)
		return ;
	if (key == M_WHE_U || key == K_PLUS || key == K_NP_PLUS)
		all->data.zoom *= ZOOM_COEFF;
	else if (key == M_WHE_D || key == K_LESS || key == K_NP_LESS)
		all->data.zoom /= ZOOM_COEFF;
	else
		return ;
	tmpy = (all->data.coeff * (double)y) + all->data.z0.im;
	tmpx = (all->data.coeff * (double)x) + all->data.z0.re;
	all->data.coeff = (1.000 / COEFF) / all->data.zoom;
	all->data.z0.im = tmpy - (all->data.coeff * (double)y);
	all->data.z0.re = tmpx - (all->data.coeff * (double)x);
	redraw(all);
}
