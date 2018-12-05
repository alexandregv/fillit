/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 11:19:50 by achoquel          #+#    #+#             */
/*   Updated: 2018/11/23 12:19:26 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmpsrc;
	unsigned char	*tmpdst;

	i = 0;
	tmpsrc = (unsigned char *)src;
	tmpdst = (unsigned char *)dst;
	while (i < n)
	{
		tmpdst[i] = tmpsrc[i];
		if (tmpsrc[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
