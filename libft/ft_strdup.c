/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 10:43:41 by achoquel          #+#    #+#             */
/*   Updated: 2018/11/27 15:21:32 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*dup;
	size_t	i;

	dup = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (dup == NULL)
		return (NULL);
	i = -1;
	while (*src)
		dup[++i] = *src++;
	dup[++i] = '\0';
	return (dup);
}
