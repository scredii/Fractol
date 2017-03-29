/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <abourgeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 17:22:20 by abourgeu          #+#    #+#             */
/*   Updated: 2017/03/28 14:10:29 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		ft_draw(t_env *e)
{
	IMG = mlx_new_image(MLX, LENGTH, HEIGHT);
	DATA = mlx_get_data_addr(IMG, &BPP, &SIZELINE, &ENDIAN);
	if (e->fractol == 1)
		ft_julia(e);
	else
		ft_mandel(e);
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	mlx_destroy_image(MLX, IMG);
}

void		pixel(int x, int y, int i, t_env *e)
{
	int		pos;

	pos = (x * (BPP / 8)) + (y * e->size);
	if (i == e->iter)
	{
		DATA[pos] = 0;
		DATA[pos + 1] = 0;
		DATA[pos + 2] = 0;
		DATA[pos + 3] = 0;
	}
	else
	{
		DATA[pos] = i * e->b;
		DATA[pos + 1] = i * e->g;
		DATA[pos + 2] = i * e->r;
		DATA[pos + 3] = 0;
	}
}

void		ft_mandel(t_env *e)
{
	t_graph	draw;
	int		x;
	int		y;
	int		i;

	x = -1;
	while (++x < LENGTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			draw.z.re = (x - LENGTH / 2) / (e->zoom * (LENGTH / 2))
				+ e->movex + e->shiftx;
			draw.z.im = (y - HEIGHT / 2) / (e->zoom * (HEIGHT / 2))
				+ e->movey + e->shifty;
			draw.newz.re = 0;
			draw.newz.im = 0;
			draw.oldz.re = 0;
			draw.oldz.im = 0;
			i = ft_iter(&draw, e);
			pixel(x, y, i, e);
		}
	}
}

void		ft_julia(t_env *e)
{
	t_graph	draw;
	int		x;
	int		y;
	int		i;

	draw.z.re = e->julia->re;
	draw.z.im = e->julia->im;
	x = -1;
	while (++x < LENGTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			draw.newz.re = 1.5 * (x - LENGTH / 2) / (e->zoom * (LENGTH / 2))
				+ e->movex + e->shiftx;
			draw.newz.im = (y - LENGTH / 2) / (e->zoom * (LENGTH / 2))
				+ e->movey + e->shifty;
			i = ft_iter(&draw, e);
			pixel(x, y, i, e);
		}
	}
}

int			ft_iter(t_graph *draw, t_env *e)
{
	int		i;

	i = -1;
	while (++i < e->iter)
	{
		OLDRE = draw->newz.re;
		OLDIM = draw->newz.im;
		draw->newz.re = (OLDRE * OLDRE) - (OLDIM * OLDIM) + draw->z.re;
		if (e->fractol == 3)
			draw->newz.im = 2 * fabs(OLDRE * OLDIM) + draw->z.im;
		else
			draw->newz.im = 1.7 * OLDRE * OLDIM + draw->z.im;
		if ((draw->newz.re * draw->newz.re + draw->newz.im + draw->newz.im) > 4)
			break ;
	}
	return (i);
}
