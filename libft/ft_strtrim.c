/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:57:24 by aguiot--          #+#    #+#             */
/*   Updated: 2018/12/10 11:57:47 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtrim(char const *s)
{
	char    *trim;
	int        i;
	int        j;
	int        k;
	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && (s[i] == '.'))
		++i;
	j = ft_strlen(s) - 1;
	while (s[j] && (s[j] == '.'))
		--j;
	if (j == -1)
		i = 0;
	if ((trim = ft_strnew(j - i + 1)) == NULL)
		return (NULL);
	k = 0;
	while (i <= j)
		trim[k++] = s[i++];
	return (trim);
}
