/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasnguye <pasnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 20:17:58 by pasnguye          #+#    #+#             */
/*   Updated: 2018/03/18 15:33:55 by pasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	update_window(t_mlx *mlx)
{
	clear_image(mlx->image);
	draw_map(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

void	free_map(int **map, int size)
{
	int i;

	i = -1;
	while (++i < size)
		free(map[i]);
	free(map);
}

void	escape(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	free_map(mlx->map, mlx->size.y);
	exit(0);
}

int		key_event(int key, t_mlx *mlx)
{
	if (key == UP_ARROW)
		mlx->pos.y -= HEIGHT / 10;
	else if (key == DOWN_ARROW)
		mlx->pos.y += HEIGHT / 10;
	else if (key == LEFT_ARROW)
		mlx->pos.x -= WIDTH / 10;
	else if (key == RIGHT_ARROW)
		mlx->pos.x += WIDTH / 10;
	else if (key == MINUS)
		mlx->zoom -= mlx->zoom_plus;
	else if (key == PLUS)
		mlx->zoom += mlx->zoom_plus;
	else if (key == PAGE_DOWN)
		mlx->zoom_z -= 1;
	else if (key == PAGE_UP)
		mlx->zoom_z += 1;
	else if (key == RESET)
		init_var(mlx);
	else if (key == ESCAPE)
		escape(mlx);
	update_window(mlx);
	return (0);
}
