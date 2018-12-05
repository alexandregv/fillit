/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:33:24 by achoquel          #+#    #+#             */
/*   Updated: 2018/11/23 12:19:55 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tsrc;
	unsigned char	*tdst;
	unsigned char	tmp[len];
	size_t			i;

	tsrc = (unsigned char *)src;
	tdst = (unsigned char *)dst;
	if (len >= 128 * 1024 * 1024)
		return (NULL);
	i = 0;
	while (i < len)
	{
		tmp[i] = tsrc[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		tdst[i] = tmp[i];
		i++;
	}
	dst = tdst;
	return (dst);
}
