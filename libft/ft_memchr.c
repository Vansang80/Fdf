/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasnguye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 19:31:48 by pasnguye          #+#    #+#             */
/*   Updated: 2017/11/11 22:45:42 by pasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	find;
	size_t			t;

	src = (unsigned char*)s;
	find = (unsigned char)c;
	t = 0;
	while (t < n)
	{
		if (src[t] == find)
			return ((void*)(s + t));
		t++;
	}
	return (NULL);
}
