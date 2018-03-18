/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasnguye <pasnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 18:48:09 by pasnguye          #+#    #+#             */
/*   Updated: 2018/03/14 02:10:04 by pasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	horizontal_line(t_point pos, t_point delta, t_point inc, int *image)
{
	int	p;
	int	i;

	i = 0;
	p = 2 * (delta.y - delta.x);
	while (i <= delta.x)
	{
        if (pos.y < HEIGHT && pos.x >= 0 && pos.x < WIDTH && pos.y >= 0)
		    image[pos.y * WIDTH + pos.x] = 0xFFFFFF;
		if (p >= 0)
		{
			pos.y += inc.y;
			p += 2 * delta.y - 2 * delta.x;
		}
		else
			p += 2 * delta.y;
		pos.x += inc.x;
		++i;
	}
}

static void	vertical_line(t_point pos, t_point delta, t_point inc, int *image)
{
	int	p;
	int	i;

	i = 0;
	p = 2 * (delta.x - delta.y);
	while (i < delta.y)
	{
		if (pos.y < HEIGHT && pos.x >= 0 && pos.x < WIDTH && pos.y >= 0)
		    image[pos.y * WIDTH + pos.x] = 0xFFFFFF;
		if (p >= 0)
		{
			pos.x += inc.x;
			p += 2 * delta.x - 2 * delta.y;
		}
		else
			p += 2 * delta.x;
		pos.y += inc.y;
		++i;
	}
}

void		trace_line(t_point start, t_point end, int *image)
{
	t_point	delta;
	t_point	incrementation;

	delta.x = end.x - start.x;
    delta.y = end.y - start.y;
    if (delta.x > 0)
        incrementation.x = 1;
    else
        incrementation.x = -1;
    if (delta.y > 0)
        incrementation.y = 1;
    else
        incrementation.y = -1;
	delta.x = abs(delta.x);
	delta.y = abs(delta.y);
	if (delta.x > delta.y)
	    horizontal_line(start, delta, incrementation, image);
	else
	    vertical_line(start, delta, incrementation, image);
}
