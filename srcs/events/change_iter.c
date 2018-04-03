/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_iter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 13:16:24 by mlantonn          #+#    #+#             */
/*   Updated: 2018/04/03 15:37:24 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#define ITER_NB 5

void	change_iter(t_all *all, int key)
{
	if (key == K_Z && all->data.imax)
		all->data.imax += ITER_NB;
	else if (key == K_X && all->data.imax > ITER_NB)
		all->data.imax -= ITER_NB;
	else if (key == K_C)
	{
		if (all->data.frac == newton)
			all->data.imax = 20;
		else if (all->data.frac == mandelneg || all->data.frac == mandisk)
			all->data.imax = 25;
		else if (all->data.frac == newtwo)
			all->data.imax = 30;
		else if (all->data.frac == julneg || all->data.frac == moz)
			all->data.imax = 40;
		else
			all->data.imax = 100;
	}
	else
		return ;
	redraw(all);
}
