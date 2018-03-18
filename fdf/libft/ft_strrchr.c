/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasnguye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 21:45:25 by pasnguye          #+#    #+#             */
/*   Updated: 2017/11/22 19:40:12 by pasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	find;
	int		i;

	i = ft_strlen(s);
	find = (char)c;
	while (i >= 0)
	{
		if (s[i] == find)
			return ((char *)(s + i));
		i--;
	}
	if (c == '\0')
		return ((char *)(s + i));
	return (NULL);
}
