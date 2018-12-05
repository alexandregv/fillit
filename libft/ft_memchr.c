/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 10:24:34 by achoquel          #+#    #+#             */
/*   Updated: 2018/11/23 12:19:33 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ts;
	unsigned char	tc;
	size_t			i;

	ts = (unsigned char *)s;
	tc = (unsigned char)c;
	i = 0;
	while (n--)
	{
		if (ts[i] == tc)
			return (ts + i);
		i++;
	}
	return (NULL);
}
