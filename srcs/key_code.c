/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_code.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <abourgeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:21:26 by abourgeu          #+#    #+#             */
/*   Updated: 2017/03/27 14:00:29 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_change_map(int key, t_env *e)
{
	if (key == 83)
	{
		e->fractol = 1;
		ft_initialise(e);
	}
	if (key == 84)
	{
		e->fractol = 2;
		ft_initialise(e);
	}
	if (key == 85)
	{
		e->fractol = 3;
		ft_initialise(e);
	}
	if (key == 86)
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
		e->r = (rand() % 256) + 1;
		e->b = (rand() % 256) + 1;
		e->g = (rand() % 256) + 1;
	}
	if (key == 6)
		ft_initialise(e);
	ft_change_map(key, e);
	e->redraw = 1;
	return (0);
}
