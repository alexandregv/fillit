/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:32:04 by achoquel          #+#    #+#             */
/*   Updated: 2018/11/21 13:46:15 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh;
	size_t	i;

	i = 0;
	if (s)
	{
		if ((fresh = (char *)malloc(sizeof(char) * len + 1)) == NULL)
			return (NULL);
		while (i != len)
		{
			fresh[i] = s[start + i];
			i++;
		}
		fresh[i] = '\0';
		return (fresh);
	}
	return (NULL);
}
