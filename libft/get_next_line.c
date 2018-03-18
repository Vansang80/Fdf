/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasnguye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 00:26:59 by pasnguye          #+#    #+#             */
/*   Updated: 2018/03/17 19:05:23 by pasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

static int		check_buf_and_free(char *buf, char **line)
{
	char	*tmp;
	int		i;
	char	n;

	tmp = NULL;
	i = 0;
	n = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!(tmp = ft_strnew((ft_strlen(*line) + i))))
		return (0);
	ft_strcpy(tmp, *line);
	if (*line)
		free(*line);
	ft_strncat(tmp, buf, i);
	*line = tmp;
	n = (buf[i] == '\n') ? 1 : 0;
	ft_strcpy(buf, &(buf[i + n]));
	return (n);
}

int				get_next_line(const int fd, char **line)
{
	static char		buf[BUFF_SIZE + 1];
	int				ret;

	if (fd < 0 || (read(fd, &ret, 0) == -1) || !line)
		return (-1);
	*line = NULL;
	if (buf[0] && check_buf_and_free(buf, line))
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (check_buf_and_free(buf, line) == 1)
			return (1);
	}
	if (*line)
		return (1);
	return (0);
}
