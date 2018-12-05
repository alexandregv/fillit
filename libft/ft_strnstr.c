/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:57:23 by achoquel          #+#    #+#             */
/*   Updated: 2018/11/23 12:22:41 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *str, const char *tofind, size_t len)
{
	size_t	len2;

	if (*tofind == '\0')
		return ((char *)str);
	len2 = ft_strlen(tofind);
	while (*str != '\0' && len-- >= len2)
	{
		if (*str == *tofind && ft_strncmp(str, tofind, len2) == 0)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
