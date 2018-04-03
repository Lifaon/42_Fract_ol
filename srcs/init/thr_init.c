/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thr_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 13:25:08 by mlantonn          #+#    #+#             */
/*   Updated: 2018/03/28 12:57:20 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	thr_init(t_all *all)
{
	int i;
	int	j;
	int nb;

	i = -1;
	nb = WIN_H / NB_THR;
	while (++i < NB_THR)
	{
		if (!(all->thr[i].buf = (char *)malloc(sizeof(char) *
		(WIN_W * WIN_H * 4 / NB_THR))))
		{
			j = -1;
			while (++j < i)
				ft_strdel(&all->thr[j].buf);
			ft_putendl("malloc(3) error");
			exit_all(all, -1);
		}
		all->thr[i].aa = 1;
		all->thr[i].y = nb * i;
		all->thr[i].da = &all->data;
	}
}
