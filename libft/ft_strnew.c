/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:16:02 by achoquel          #+#    #+#             */
/*   Updated: 2018/11/27 14:29:04 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*fresh;
	size_t	i;

	i = -1;
	if ((fresh = (char *)malloc(sizeof(char) * size + 1)) == NULL)
		return (NULL);
	while (size--)
		fresh[++i] = '\0';
	return (fresh);
}
