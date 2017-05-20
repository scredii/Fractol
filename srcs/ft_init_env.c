/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <abourgeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 19:31:35 by abourgeu          #+#    #+#             */
/*   Updated: 2017/05/20 12:31:31 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_init		*ft_new(void)
{
	t_init	*comp;

	if (!(comp = (t_init *)malloc(sizeof(t_init))))
		exit(write(1, "Malloc failed.\n", 15));
	comp->re = 0;
	comp->im = 0;
	return (comp);
}

void		ft_init_julia(t_env *e)
{
	e->iter = 50;
	e->iter_step = 10;
	if (e->julia != NULL)
	{
		e->julia->re = 0.285;
		e->julia->im = 0.01;
	}
	if (e->julia_max != NULL)
	{
		e->julia_max->re = 2;
		e->julia_max->im = 0.5;
	}
	if (e->julia_min != NULL)
	{
		e->julia_min->re = -2;
		e->julia_min->re = -0.5;
	}
}

void		ft_init_mandel(t_env *e)
{
	ft_init_julia(e);
	if (e->fractol == 3)
		e->zoom = 0.5;
	if (e->fractol == 2)
	{
		e->zoom = 0.75;
		e->movex = -0.75;
		e->movey = 0.2;
	}
}

void		ft_initialise(t_env *e)
{
	e->size = 0;
	e->mouse = 1;
	e->mousex = LENGTH / 2;
	e->mousey = HEIGHT / 2;
	e->shiftx = 0;
	e->shifty = 0;
	e->movex = 0;
	e->movey = -0.2;
	e->zoom = 0.7;
	e->zoom_step = ZOOM;
	e->move_step = 0.3;
	e->r = 0x000003;
	e->g = 0x00003A;
	e->b = 0x000036;
	if (e->fractol == 1)
		ft_init_julia(e);
	else
		ft_init_mandel(e);
}

t_env		*ft_init_env(void)
{
	t_env	*e;

	if (!(e = (t_env*)malloc(sizeof(t_env))))
		exit(write(1, "Malloc failed.\n", 15));
	e->julia = ft_new();
	e->julia_max = ft_new();
	e->julia_min = ft_new();
	return (e);
}
