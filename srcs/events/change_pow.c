/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_pow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:20:24 by mlantonn          #+#    #+#             */
/*   Updated: 2018/04/03 14:16:12 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#define POW_MAX 6
#define POW_MIN 2

void	change_pow(t_all *all, int key)
{
	if (all->data.frac == newton || all->data.frac == newtwo)
		return ;
	if (key == K_R && all->data.pow < POW_MAX)
		all->data.pow += 1;
	else if (key == K_F && all->data.pow > POW_MIN)
		all->data.pow -= 1;
	else
		return ;
	redraw(all);
}
