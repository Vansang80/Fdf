/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasnguye <pasnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 21:53:10 by pasnguye          #+#    #+#             */
/*   Updated: 2018/03/15 21:52:53 by pasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countword(char *s, char c)
{
	int		count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			++count;
			while (*s && *s != c)
				++s;
			--s;
		}
		++s;
	}
	return (count);
}

static int	ft_wordlen(char *s, char c, char **next)
{
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
			{
				++i;
				++len;
			}
			*next = &s[i];
			return (len);
		}
		++i;
	}
	return (0);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	char	*str;
	int		words;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	words = ft_countword((char *)s, c);
	if (!(tab = ((char **)malloc(sizeof(char *) * (words + 1)))))
		return (NULL);
	i = 0;
	(str = (char *)s);
	while (i < words)
	{
		len = ft_wordlen(str, c, &str);
		if (!(tab[i] = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		ft_strncpy(tab[i], str - len, len);
		tab[i][len] = '\0';
		++i;
	}
	tab[i] = NULL;
	return (tab);
}
