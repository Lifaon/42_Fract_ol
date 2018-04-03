/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 19:01:08 by mlantonn          #+#    #+#             */
/*   Updated: 2018/03/28 20:27:48 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	change_color(t_all *all, int key)
{
	if (key == K_1 || key == K_NP_1)
		all->data.nb_col = 0;
	else if (key == K_2 || key == K_NP_2)
		all->data.nb_col = 1;
	else if (key == K_3 || key == K_NP_3)
		all->data.nb_col = 2;
	else if (key == K_4 || key == K_NP_4)
		all->data.nb_col = 3;
	else if (key == K_5 || key == K_NP_5)
		all->data.nb_col = 4;
	else if (key == K_TAB)
		all->data.nb_col = all->data.nb_col != 4 ? all->data.nb_col + 1 : 0;
	else
		return ;
	redraw(all);
}
