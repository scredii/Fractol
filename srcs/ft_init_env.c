/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <abourgeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 19:31:35 by abourgeu          #+#    #+#             */
/*   Updated: 2017/03/22 13:18:44 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_comp		*ft_comp(void)
{
	t_comp	*comp;

	if (!(comp = (t_comp *)malloc(sizeof(t_comp))))
		exit(write(1, "Malloc failed.\n", 15));
	comp->re = 0;
	comp->im = 0;
	return (comp);
}

void		ft_init_julia(t_env *e)
{
	e->iter = 0;
	e->iter_step = 10;
	if (e->julia != NULL)
	{
		e->julia->re = -1.457022285618;
		e->julia->im = 0;
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
		e->movex = -0.5;
		e->movey = 0.2;
	}
}

void		ft_initialise(t_env *e)
{
	e->shiftx = 0;
	e->shifty = 0;
	e->movex = 0;
	e->movey = -0.2;
	e->zoom = 1;
	e->zoom_step = ZOOM;
	e->move_step = MOVE;
	e->r = 0x000000;
	e->g = 0x59f89d / 50;
	e->b = 0xc6e2ff;
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
	e->julia = ft_comp();
	e->julia_max = ft_comp();
	e->julia_min = ft_comp();
	e->size = 0;
	e->mouse = 1;
	e->mousex = LENGTH / 2;
	e->mousey = HEIGHT / 2;
	return (e);
}
