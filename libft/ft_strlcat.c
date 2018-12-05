/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 10:41:40 by achoquel          #+#    #+#             */
/*   Updated: 2018/11/23 12:21:51 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	ret;

	i = 0;
	j = 0;
	while (s1[i] && i < size)
		i++;
	ret = ft_strlen((char *)s2);
	if (size > 0)
	{
		while (s2[j] && i < size - 1)
			s1[i++] = s2[j++];
	}
	if (j > 0)
	{
		s1[i] = '\0';
		return (ret + i - j);
	}
	return (ret + i);
}
