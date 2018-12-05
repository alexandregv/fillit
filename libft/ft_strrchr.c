/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:18:34 by achoquel          #+#    #+#             */
/*   Updated: 2018/11/23 12:22:47 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char *tmp;

	tmp = NULL;
	if (*str == '\0' && c != '\0')
		return (NULL);
	if (c == '\0')
	{
		while (*str)
			str++;
		tmp = (char *)str;
		return (tmp);
	}
	while (*str != '\0')
	{
		while (*str != c && *str != '\0')
			str++;
		if (*str == c)
		{
			tmp = (char *)str;
			str++;
		}
	}
	return (tmp);
}
