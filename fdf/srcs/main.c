/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasnguye <pasnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 19:21:17 by pasnguye          #+#    #+#             */
/*   Updated: 2018/03/16 01:09:27 by pasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

void	clear_image(int *image)
{
	int	i;

	i = -1;
	while (++i < HEIGHT * HEIGHT)
		image[i] = 0;
}

void	print_map(t_mlx *mlx)
{
	printf("************** MAP *************\n");
	for (int y = 0; y < mlx->size.y; ++y) {
		for (int x = 0; x < mlx->size.x; ++x) {
			printf("%d ", mlx->map[y][x]);
		}
		printf("\n");
	}
}

void	draw_map(t_mlx *mlx)
{
	t_point p1;
	t_point p2;
	int	y;
	int	x;

	y = -1;
	while (++y < mlx->size.y)
	{
		x = -1;
		while (++x < mlx->size.x)
		{
			p1.x = (x - y) * 2 * mlx->zoom + mlx->pos.x;
			p1.y = (x + y) * mlx->zoom + mlx->pos.y;
			p1.y -= mlx->map[y][x] * mlx->zoom_z;
			if (x + 1 < mlx->size.x)
			{
				p2.x = (x+1 - y) * 2 * mlx->zoom + mlx->pos.x;
				p2.y = (x+1 + y) * mlx->zoom + mlx->pos.y;
				p2.y -= mlx->map[y][x+1] * mlx->zoom_z;
				trace_line(p1, p2, mlx->image);
			}
			if (y + 1 < mlx->size.y)
			{
				p2.x = (x - (y+1)) * 2 * mlx->zoom + mlx->pos.x;
				p2.y = (x +y+1) * mlx->zoom + mlx->pos.y;
				p2.y -= mlx->map[y+1][x] * mlx->zoom_z;
				trace_line(p1, p2, mlx->image);
			}
		}
	}
}

void	init_var(t_mlx *mlx)
{
	mlx->zoom = WIDTH / (mlx->size.x * 3);
	mlx->zoom_plus = mlx->zoom / 5;
	if (mlx->zoom_plus == 0)  mlx->zoom_plus = 1;
	mlx->zoom_z = 1;
	if (mlx->size.x > mlx->size.y)
	{
		mlx->pos.x = WIDTH / 3;
		mlx->pos.y = WIDTH / 3;
	}
	else
	{
		mlx->pos.x = WIDTH - WIDTH / 3;
		mlx->pos.y = WIDTH / 6;
	}
}

int		main(int ac, char **av)
{
	t_mlx	mlx;

	ft_bzero(&mlx, sizeof(t_mlx));
	if (parse_file(ac, av, &mlx) == ERROR)
	{
		ft_putstr("Error\n");
		system("leaks fdf");
		return (0);		
	}
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "fdf");
	mlx.img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
	mlx.image = (int *)mlx_get_data_addr(mlx.img, &(mlx.bpp), &(mlx.s_line), &(mlx.endian));

	init_var(&mlx);
	draw_map(&mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	mlx_key_hook (mlx.win, key_event, &mlx);
	mlx_loop(mlx.mlx);
}
