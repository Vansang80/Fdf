/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasnguye <pasnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 17:32:41 by pasnguye          #+#    #+#             */
/*   Updated: 2018/03/17 18:49:55 by pasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_int(char *str)
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
	number = ft_atol((const char *)str);
	if (number > 2147483647 || number < -2147483647)
		return (0);
	return (1);
}
