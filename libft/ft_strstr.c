/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:37:27 by achoquel          #+#    #+#             */
/*   Updated: 2018/11/23 12:23:00 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *str, const char *tofind)
{
	size_t	len2;

	if (*tofind == '\0')
		return ((char *)str);
	len2 = ft_strlen(tofind);
	while (*str != '\0')
	{
		if (*str == *tofind && ft_strncmp(str, tofind, len2) == 0)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
