/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 19:55:38 by mlantonn          #+#    #+#             */
/*   Updated: 2018/04/03 16:14:21 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <pthread.h>
# include "defines.h"

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*img_str;
}					t_mlx;
/*
**	Struct used to store the necessary pointers for the mlx usage.
*/

typedef struct		s_comp
{
	double			re;
	double			im;
}					t_comp;
/*
**	Struct used to replicate usage of the complex numbers.
*/

typedef struct s_data	t_data;
struct				s_data
{
	char			*buf;
	int				blur_expose;
	int				blur_coeff;
	int				imax;
	int				nb_col;
	int				col[5][5];
	int				pow;
	double			coeff;
	double			zoom;
	t_comp			z0;
	t_comp			c;
	t_mlx			mlx;
	int				(*frac)(t_data *, t_comp);
};
/*
**	Struct used to store different variables.
*/

typedef struct		s_thr
{
	char			*buf;
	int				aa;
	char			r[64];
	char			g[64];
	char			b[64];
	int				y;
	t_data			*da;
	pthread_t		th;
}					t_thr;
/*
**	Struct used for the multi-threading option.
*/

typedef struct		s_all
{
	int				move_expose;
	int				aa_expose;
	t_thr			thr[NB_THR];
	t_data			data;
}					t_all;

#endif
