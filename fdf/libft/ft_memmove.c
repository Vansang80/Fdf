/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasnguye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 23:40:00 by pasnguye          #+#    #+#             */
/*   Updated: 2017/11/11 18:45:00 by pasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmpd;
	unsigned char	*tmps;

	tmpd = (unsigned char *)dst;
	tmps = (unsigned char *)src;
	if (src > dst)
		ft_memcpy(tmpd, tmps, len);
	if (dst > src)
	{
		while (len)
		{
			len--;
			tmpd[len] = tmps[len];
		}
	}
	return (tmpd);
}
