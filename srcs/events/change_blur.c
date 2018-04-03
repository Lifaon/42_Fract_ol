/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_blur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 14:49:36 by mlantonn          #+#    #+#             */
/*   Updated: 2018/04/03 16:13:29 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	change_blur(t_all *all, int key)
{
	if (key == K_V)
	{
		all->data.blur_expose = all->data.blur_expose ? 0 : 1;
		redraw(all);
		return ;
	}
	if (all->data.blur_expose == 0)
		return ;
	if (key == K_B)
		all->data.blur_coeff++;
	else if (key == K_N && all->data.blur_coeff > 1)
		all->data.blur_coeff--;
	else if (key == K_M)
		all->data.blur_coeff = 3;
	else
		return ;
	redraw(all);
}
