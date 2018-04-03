/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blur.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:36:01 by mlantonn          #+#    #+#             */
/*   Updated: 2018/04/03 14:00:40 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static char	blend(char *buf, int i, int j)
{
	int	kern;
	int	line;
	int	nb;

	kern = (int)(unsigned char)buf[j];
	line = WIN_W * 4;
	nb = 1;
	if ((i + 4) % line && ++nb)
		kern += (int)(unsigned char)buf[j + 4];
	if (i + line < WIN_W * WIN_H * 4 && ++nb)
		kern += (int)(unsigned char)buf[j + line];
	if ((i - 4) % line && ++nb)
		kern += (int)(unsigned char)buf[j - 4];
	if (i >= line && ++nb)
		kern += (int)(unsigned char)buf[j - line];
	kern /= nb;
	return ((char)kern);
}

void		blur(t_data *data, int nb)
{
	int i;
	int	j;

	i = -1;
	while (++i < nb)
	{
		j = -1;
		while (++j < WIN_H * WIN_W * 4)
			data->buf[j] = data->mlx.img_str[j];
		j = 0;
		while (j < WIN_H * WIN_W * 4)
		{
			j += 4;
			if (data->buf[j] == 0 && data->buf[j + 1] == 0 &&
				data->buf[j + 2] == 0)
				continue ;
			data->mlx.img_str[j] = blend(data->buf, j, j);
			data->mlx.img_str[j + 1] = blend(data->buf, j, j + 1);
			data->mlx.img_str[j + 2] = blend(data->buf, j, j + 2);
		}
	}
}
