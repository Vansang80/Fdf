/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasnguye <pasnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 19:23:16 by pasnguye          #+#    #+#             */
/*   Updated: 2018/03/16 01:23:05 by pasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/* LIBRARY */
# include <mlx.h>
# include <math.h> 
# include <stdio.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"

/* SIZE WINDOWS */
# define WIDTH 1400
# define HEIGHT 1400

/* KEYCODE */
# define SPACE 49
# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define UP_ARROW 126
# define DOWN_ARROW 125
# define MINUS 78
# define PLUS 69
# define ESCAPE 53
# define PAGE_UP 116
# define PAGE_DOWN 121

# define ERROR -1
# define SUCCESS 1

/* COORDONNEES */
typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

/* INITIALISATION MLX */
typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*image;
	int			bpp;
	int			s_line;
	int			endian;

	t_point		size;
	t_point		pos;
	int			**map;
	int			zoom_plus;
	int			zoom;
	int			zoom_z;

}				t_mlx;


void		trace_line(t_point start, t_point end, int *image);
int 	    parse_file(int ac,char **av, t_mlx *mlx);
int			ft_is_int(char *str);
void		draw_map(t_mlx *mlx);
int			key_event(int key, t_mlx *mlx);
void		clear_image(int *image);

#endif
