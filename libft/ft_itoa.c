/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 09:32:51 by achoquel          #+#    #+#             */
/*   Updated: 2018/11/23 12:18:38 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

static long int	ft_intsize(long int tmp)
{
	long int	size;

	size = 0;
	if (tmp == 0)
		return (1);
	else if (tmp < 0)
		++size;
	while (tmp != 0)
	{
		tmp /= 10;
		++size;
	}
	return (size);
}

static int		ft_isneg(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

char			*ft_itoa(int n)
{
	long int		size;
	long int		tmp;
	char			*str;
	int				neg;

	tmp = (long int)n;
	size = ft_intsize(tmp) + 1;
	if ((str = (char *)malloc(sizeof(char) * size)) == 0)
		return (NULL);
	else
	{
		if ((neg = ft_isneg(tmp)) == 1)
			tmp = -tmp;
		str[--size] = '\0';
		while (size != 0)
		{
			str[--size] = ((tmp % 10) + '0');
			tmp = tmp / 10;
		}
		if (neg == 1)
			str[0] = '-';
	}
	return (str);
}
