/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <abourgeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:45:43 by abourgeu          #+#    #+#             */
/*   Updated: 2017/03/22 12:24:49 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "get_next_line.h"
# define HEIGHT 1200
# define LENGTH 800
# define ZOOM 1.1
# define MOVE 0.3
# define SHIFT 0.5
# define MLX e->mlx
# define WIN e->win
# define IMG e->img
# define DATA e->data
# define SIZELINE e->size
# define ENDIAN e->endian
# define BPP e->bpp
# define OLDRE draw->oldz.re
# define OLDIM draw->oldz.im
# define OLDRE_CUBE OLDRE * OLDRE * OLDRE
# define OLDIM_CUBE OLDIM * OLDIM * OLDIM
# define MOUSE_REL_X (e->mousex - LENGTH / 2)
# define MOUSE_REL_Y (e->mousey - HEIGHT / 2)

typedef struct		s_comp
{
	double re;
	double im;
}					t_comp;

typedef struct		s_graph
{
	t_comp			z;
	t_comp			oldz;
	t_comp			newz;
}					t_graph;

typedef struct		s_env
{
	double			shifty;
	double			shiftx;
	double			movey;
	double			movex;
	double			zoom_step;
	double			zoom;
	double			move_step;
	int				iter;
	int				iter_step;
	int				mousex;
	int				mousey;
	int				bpp;
	int				endian;
	int				sizeline;
	int				r;
	int				g;
	int				b;
	int				size;
	int				mouse;
	int				redraw;
	int				fractol;
	char			*data;
	void			*mlx;
	void			*win;
	void			*img;
	t_comp			*julia;
	t_comp			*julia_max;
	t_comp			*julia_min;
	t_graph			*draw;
}					t_env;

void				ft_change_map(int key, t_env *e);
void				ft_coffee(t_env *e);
void				ft_initialise(t_env *e);
void				ft_mandel(t_env *e);
int					ft_mouse_hook(int button, int x, int y, t_env *e);
double				ft_calc_shift(double r, double t, t_env *e);
void				ft_range(t_env *e);
int					ft_loop(t_env *e);
int					ft_expose(t_env *e);
void				ft_move(t_env *env);
int					ft_mouse(int x, int y, t_env *env);
void				ft_draw(t_env *e);
void				ft_init(t_env *e);
int					ft_iter(t_graph *draw, t_env *e);
void				ft_julia(t_env *e);
int					ft_check_args(char **av, t_env *e);
t_env				*ft_init_env(void);
int					event(int key, t_env *e);

#endif
