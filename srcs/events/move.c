/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 19:18:14 by mlantonn          #+#    #+#             */
/*   Updated: 2018/03/29 13:39:26 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#define MOVE_COEFF 50

void	move(t_all *all, int key)
{
	if (key == K_W || key == K_ARR_U)
		all->data.z0.im -= all->data.coeff * MOVE_COEFF;
	else if (key == K_A || key == K_ARR_L)
		all->data.z0.re -= all->data.coeff * MOVE_COEFF;
	else if (key == K_S || key == K_ARR_D)
		all->data.z0.im += all->data.coeff * MOVE_COEFF;
	else if (key == K_D || key == K_ARR_R)
		all->data.z0.re += all->data.coeff * MOVE_COEFF;
	else
		return ;
	redraw(all);
}
