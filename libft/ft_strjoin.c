/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasnguye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 00:58:33 by pasnguye          #+#    #+#             */
/*   Updated: 2017/11/21 19:51:54 by pasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		j;
	int		k;

	if (!s1 || !s2)
		return (NULL);
	j = ft_strlen(s1);
	k = ft_strlen(s2);
	str = (char*)malloc(sizeof(*str) * (j + k) + 1);
	if (!str)
		return (NULL);
	str = ft_strcpy(str, (const char*)s1);
	str = ft_strcat(str, (const char*)s2);
	return (str);
}
