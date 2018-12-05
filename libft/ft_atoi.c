/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 15:53:56 by achoquel          #+#    #+#             */
/*   Updated: 2018/11/23 12:17:44 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int neg;
	int r;

	i = 0;
	neg = 0;
	r = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| (str[i] == '+' && ft_isdigit((int)str[i + 1])) || str[i] == '\r'
		|| str[i] == '\f')
		i++;
	if (str[i] == '-')
	{
		neg = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10;
		r = r + ((int)str[i] - '0');
		i++;
	}
	if (neg == 1)
		r = -r;
	return (r);
}
