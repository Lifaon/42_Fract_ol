/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_aa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 13:00:31 by mlantonn          #+#    #+#             */
/*   Updated: 2018/03/28 15:02:55 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void	change_thr_aa(t_all *all, int nb)
{
	int i;

	i = -1;
	while (++i < NB_THR)
		all->thr[i].aa = nb;
	all->aa_expose = 0;
	redraw(all);
}

int			change_aa(t_all *all, int key)
{
	if (key == K_Q)
		all->aa_expose = 1;
	if (key == K_E)
		change_thr_aa(all, 1);
	if (all->aa_expose == 0)
		return (0);
	if (key == K_2 || key == K_NP_2)
		change_thr_aa(all, 2);
	else if (key == K_3 || key == K_NP_3)
		change_thr_aa(all, 3);
	else if (key == K_4 || key == K_NP_4)
		change_thr_aa(all, 4);
	else if (key == K_5 || key == K_NP_5)
		change_thr_aa(all, 5);
	else if (key == K_6 || key == K_NP_6)
		change_thr_aa(all, 6);
	else if (key == K_7 || key == K_NP_7)
		change_thr_aa(all, 7);
	else if (key == K_8 || key == K_NP_8)
		change_thr_aa(all, 8);
	return (1);
}
