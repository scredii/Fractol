/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_code.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <abourgeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:21:26 by abourgeu          #+#    #+#             */
/*   Updated: 2017/05/20 12:40:24 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_change_map(int key, t_env *e)
{
	if (key == 18)
	{
		e->fractol = 1;
		ft_initialise(e);
	}
	if (key == 19)
	{
		e->fractol = 2;
		ft_initialise(e);
	}
	if (key == 20)
	{
		e->fractol = 3;
		ft_initialise(e);
	}
	if (key == 34)
	{
		if (e->iter < 500)
			e->iter += 10;
		else
			ft_putstr("Iter Max.");
	}
}

int		event(int key, t_env *e)
{
	if (key == 53)
		exit(write(1, "Program close.\n", 15));
	if (key == 49)
		e->mouse = (e->mouse ? 0 : 1);
	if (key == 123)
		e->movex -= e->move_step;
	if (key == 124)
		e->movex += e->move_step;
	if (key == 125)
		e->movey += e->move_step;
	if (key == 126)
		e->movey -= e->move_step;
	if (key == 8)
	{
		e->r = e->b >> 16;
		e->b = rand();
		e->g = e->b >> 8;
	}
	if (key == 6)
		ft_initialise(e);
	ft_change_map(key, e);
	e->redraw = 1;
	return (0);
}
