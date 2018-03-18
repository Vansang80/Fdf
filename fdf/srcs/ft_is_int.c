/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasnguye <pasnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 21:46:30 by pasnguye          #+#    #+#             */
/*   Updated: 2018/03/15 21:18:26 by pasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static long	ft_atol(const char *str)
{
	int			i;
	int			signe;
	long		result;

	i = 0;
	while ((str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)) && str[i])
		++i;
	signe = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -1;
		++i;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		++i;
	}
	return (result * signe);
}

int			ft_is_int(char *str)
{
	int		i;
	long	number;

	if (!str)
		return (0);
	i = 0;
	if (str[0] == '-')
	{
		++i;
		if (str[i] == '\0')
			return (0);
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		++i;
	}
	if (i > 11)
		return (0);
	number = ft_atol(str);
	if (number > 2147483647 || number < -2147483647)
		return (0);
	return (1);
}