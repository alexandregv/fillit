/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:28:23 by achoquel          #+#    #+#             */
/*   Updated: 2018/11/23 12:22:21 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ts1;
	unsigned char	*ts2;
	size_t			i;

	ts1 = (unsigned char *)s1;
	ts2 = (unsigned char *)s2;
	i = 0;
	while (n-- && (ts1[i] != '\0' || ts2[i]))
	{
		if (ts1[i] != ts2[i])
			return (ts1[i] - ts2[i]);
		i++;
	}
	return (0);
}
