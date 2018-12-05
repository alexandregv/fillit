/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:46:59 by achoquel          #+#    #+#             */
/*   Updated: 2018/11/14 12:45:35 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*tmp;

	i = 0;
	if (len == 0)
		return (b);
	tmp = b;
	while (i < len)
	{
		tmp[i] = (unsigned char)c;
		i++;
	}
	b = tmp;
	return (b);
}
