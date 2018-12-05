/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:18:53 by achoquel          #+#    #+#             */
/*   Updated: 2018/11/23 12:19:44 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmpdst;
	unsigned char	*tmpsrc;
	size_t			i;

	tmpdst = dst;
	tmpsrc = (void *)src;
	i = 0;
	if (n == 0)
		return (dst);
	while (i < n)
	{
		tmpdst[i] = tmpsrc[i];
		i++;
	}
	dst = tmpdst;
	return (dst);
}
