/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:02:25 by mlantonn          #+#    #+#             */
/*   Updated: 2018/03/20 20:08:50 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Color palettes found on :	http://www.color-hex.com/color-palettes/
**	1st = Forest Trees			http://www.color-hex.com/color-palette/57782
**	2nd = Shades of Purple		http://www.color-hex.com/color-palette/1835
**	3rd = Bohemians Jewels		http://www.color-hex.com/color-palette/57927
**	4th = Fruit Drop			http://www.color-hex.com/color-palette/54872
**	5th = Neon 0908				http://www.color-hex.com/color-palette/1131
*/

#include "fract_ol.h"

void	color_init(int color[5][5])
{
	color[0][0] = 0x3e6c60;
	color[0][1] = 0x397a4c;
	color[0][2] = 0x569358;
	color[0][3] = 0x77c063;
	color[0][4] = 0xbedb92;
	color[1][0] = 0xefbbff;
	color[1][1] = 0xd896ff;
	color[1][2] = 0xbe29ec;
	color[1][3] = 0x800080;
	color[1][4] = 0x660066;
	color[2][0] = 0xdd9933;
	color[2][1] = 0x90126f;
	color[2][2] = 0x052d72;
	color[2][3] = 0x05878a;
	color[2][4] = 0x074e67;
	color[3][0] = 0xd4637a;
	color[3][1] = 0x9a84af;
	color[3][2] = 0x77c08c;
	color[3][3] = 0xebbf72;
	color[3][4] = 0xf1de7c;
	color[4][0] = 0xfe0000;
	color[4][1] = 0xfdfe02;
	color[4][2] = 0x0bff01;
	color[4][3] = 0x011efe;
	color[4][4] = 0xfe00f6;
}
