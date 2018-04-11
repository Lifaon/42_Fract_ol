/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 13:13:18 by mlantonn          #+#    #+#             */
/*   Updated: 2018/04/11 14:19:22 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	redraw(t_all *all)
{
	draw_image(all);
	mlx_put_image_to_window(all->data.mlx.mlx, all->data.mlx.win,
		all->data.mlx.img, 0, 0);
}
