/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 13:49:06 by mlantonn          #+#    #+#             */
/*   Updated: 2018/03/29 13:39:43 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	reset_all(t_all *all, int key)
{
	if (key != K_SPACE)
		return ;
	all->data.z0.im = -1.0 * (WIN_H + 1) / COEFF / 2.0;
	all->data.z0.re = -1.5 * WIN_W / COEFF / 3.0;
	all->data.zoom = 1.0;
	all->data.coeff = (1.0 / COEFF) / all->data.zoom;
	redraw(all);
}
