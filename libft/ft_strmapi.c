/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 13:42:21 by achoquel          #+#    #+#             */
/*   Updated: 2018/11/23 12:22:07 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*fresh;
	unsigned int	i;
	unsigned int	l;

	if (s)
	{
		i = 0;
		l = ft_strlen((char *)s) + 1;
		if ((fresh = (char *)malloc(sizeof(char) * l)) == NULL)
			return (NULL);
		while (s[i] != '\0')
		{
			fresh[i] = f(i, s[i]);
			i++;
		}
		fresh[i] = '\0';
		return (fresh);
	}
	return (NULL);
}
