/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 17:26:45 by mlantonn          #+#    #+#             */
/*   Updated: 2018/04/03 14:58:49 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	move_julia(t_all *all, int key)
{
	if (all->data.frac != julia && all->data.frac != julneg && \
		all->data.frac != moz)
		return ;
	if (key == K_I)
		all->data.c.im += all->data.coeff;
	else if (key == K_J)
		all->data.c.re -= all->data.coeff;
	else if (key == K_K)
		all->data.c.im -= all->data.coeff;
	else if (key == K_L)
		all->data.c.re += all->data.coeff;
	else
		return ;
	redraw(all);
}
