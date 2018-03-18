/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasnguye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 01:32:48 by pasnguye          #+#    #+#             */
/*   Updated: 2017/11/22 05:33:05 by pasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		count(int n, int *i)
{
	int		tempo;

	tempo = n;
	while (tempo /= 10)
		(*i)++;
	if (n < 0)
		(*i)++;
}

char			*ft_itoa(int n)
{
	char	*num;
	int		i;
	int		s;

	i = 1;
	s = 0;
	count(n, &i);
	if (n < 0)
	{
		s = 1;
		n *= -1;
	}
	if ((num = (char*)malloc(sizeof(*num) * i + 1)) == NULL)
		return (NULL);
	num[i] = '\0';
	if (n == -2147483648)
		return (ft_strcpy(num, "-2147483648"));
	while (i--)
	{
		num[i] = n % 10 + '0';
		n = n / 10;
	}
	if (s)
		num[0] = '-';
	return (num);
}
