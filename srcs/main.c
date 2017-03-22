/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <abourgeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:16:44 by abourgeu          #+#    #+#             */
/*   Updated: 2017/03/22 13:18:38 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			ft_loop(t_env *e)
{
	if (e->redraw)
	{
		e->iter++;
		ft_draw(e);
		e->redraw = 0;
	}
	return (0);
}

int			ft_expose(t_env *e)
{
	e->redraw = 1;
	if (!WIN)
		exit(0);
	return (0);
}

int			ft_check_args(char **av, t_env *e)
{
	e->fractol = 0;
	if (ft_strcmp(av[1], "Julia") == 0)
		e->fractol = 1;
	else if (ft_strcmp(av[1], "Mandelbrot") == 0)
		e->fractol = 2;
	else if (ft_strcmp(av[1], "Burning") == 0)
		e->fractol = 3;
	else if (e->fractol == 0)
		write(1, "Insert map:\n- Julia\n- Mandelbrot\n- Burning\n", 43);
	return (0);
}

void		ft_coffee(t_env *e)
{
	ft_initialise(e);
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, LENGTH, HEIGHT, "=> Fractol <=");
	mlx_key_hook(WIN, event, e);
	mlx_mouse_hook(WIN, ft_mouse_hook, e);
	mlx_hook(WIN, 6, (1L << 8), ft_mouse, e);
	mlx_loop_hook(MLX, ft_loop, e);
	mlx_expose_hook(WIN, ft_expose, e);
	ft_putstr("key:\n-c for color\n-space for stop mouse\n-1/2/3 for\
	change map\n-arrows for move\n-z for reinitialise map\n-esc for exit.\n");
	mlx_loop(MLX);
}

int			main(int ac, char **av)
{
	t_env	*e;

	if (!(e = ft_init_env()))
		exit(write(1, "Init failed.\n", 13));
	if (ac != 2)
		exit(write(1, "Insert map:\n- Julia\n- Mandelbrot\n- Burning\n", 43));
	ft_check_args(av, e);
	if (e->fractol > 0)
		ft_coffee(e);
	return (0);
}
