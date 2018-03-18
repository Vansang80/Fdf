/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasnguye <pasnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 20:20:51 by pasnguye          #+#    #+#             */
/*   Updated: 2018/03/17 19:35:24 by pasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_check_line(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
	{
		if (!ft_is_int(tab[i]))
		{
			ft_free_tab(tab);
			return (ERROR);
		}
	}
	ft_free_tab(tab);
	return (i);
}

int		check_file(int fd, t_mlx *mlx)
{
	char	*line;
	char	**split;
	int		ret;

	if (get_next_line(fd, &line) <= 0 && ft_free(&line))
		return (ERROR);
	if (!(split = ft_strsplit(line, ' ')) && ft_free(&line))
		return (ERROR);
	if ((mlx->size.x = ft_check_line(split)) <= 0 && ft_free(&line))
		return (ERROR);
	mlx->size.y = 1;
	ft_free(&line);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!(split = ft_strsplit(line, ' ')) && ft_free(&line))
			return (ERROR);
		ft_free(&line);
		if ((mlx->size.x != ft_check_line(split)))
			return (ERROR);
		mlx->size.y += 1;
	}
	if (ft_free(&line) && ret < 0)
		return (ERROR);
	return (SUCCESS);
}

int		malloc_map(t_point size, t_mlx *mlx)
{
	int	i;

	if (!(mlx->map = (int**)malloc(sizeof(int*) * mlx->size.y)))
		return (ERROR);
	i = -1;
	while (++i < size.y)
	{
		if (!(mlx->map[i] = (int*)malloc(sizeof(int) * mlx->size.x)))
		{
			while (--i >= 0)
				free(mlx->map[i]);
			free(mlx->map);
			return (ERROR);
		}
	}
	return (SUCCESS);
}

int		fill_map(int fd, t_mlx *mlx, t_point size)
{
	char	*line;
	char	**split;
	int		ret;
	int		y;
	int		x;

	y = -1;
	while ((ret = get_next_line(fd, &line)) > 0 && ++y < size.y)
	{
		if (!(split = ft_strsplit(line, ' ')) && ft_free(&line))
			return (ERROR);
		x = -1;
		while (++x < size.x && split[x])
			mlx->map[y][x] = ft_atoi(split[x]);
		ft_free_tab(split);
		ft_free(&line);
	}
	if (ft_free(&line) && ret < 0)
		return (ERROR);
	return (SUCCESS);
}

int		parse_file(int ac, char **av, t_mlx *mlx)
{
	int	fd;

	if (ac == 1 || ac > 2)
		return (ERROR);
	if ((fd = open(av[1], O_RDONLY)) < 0 || read(fd, NULL, 0) < 0)
		return (ERROR);
	if (check_file(fd, mlx) == ERROR)
	{
		return (ERROR);
		close(fd);
	}
	close(fd);
	if (malloc_map(mlx->size, mlx) == ERROR)
		return (ERROR);
	if ((fd = open(av[1], O_RDONLY)) < 0 || read(fd, NULL, 0) < 0)
		return (ERROR);
	if (fill_map(fd, mlx, mlx->size) == ERROR)
	{
		close(fd);
		return (ERROR);
	}
	close(fd);
	return (SUCCESS);
}
