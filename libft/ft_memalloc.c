/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasnguye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:06:56 by pasnguye          #+#    #+#             */
/*   Updated: 2017/11/17 17:34:35 by pasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char		*str;

	str = (char*)malloc(sizeof(*str) * (size));
	if (!str)
		return (NULL);
	ft_bzero((void*)str, size);
	return ((void *)str);
}
