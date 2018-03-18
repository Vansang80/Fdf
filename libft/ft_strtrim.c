/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasnguye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 17:35:02 by pasnguye          #+#    #+#             */
/*   Updated: 2017/11/20 00:27:11 by pasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*str;
	unsigned int	i;
	size_t			j;

	i = 0;
	if (!s)
		return (NULL);
	while ((s[i] == ' ' || s[i] == ',' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	j = ft_strlen(s) - 1;
	while ((s[j] == ' ' || s[j] == ',' ||
		s[j] == '\n' || s[j] == '\t') && i < j)
		j--;
	str = (char*)malloc(sizeof(*str) * (j - i) + 1);
	if (!str)
		return (NULL);
	str = ft_strsub(s, i, ((j + 1) - i));
	return (str);
}
