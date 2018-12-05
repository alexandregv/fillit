/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 10:01:56 by achoquel          #+#    #+#             */
/*   Updated: 2018/11/23 12:22:54 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

static size_t	ft_countw(char const *str, char c)
{
	size_t	ret;
	size_t	i;

	ret = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
			ret++;
		while (str[i] != c && str[i] != '\0')
			i++;
		i++;
	}
	return (ret);
}

static size_t	ft_wlen(char const *str, size_t pos, char c)
{
	size_t	size;

	size = 0;
	while (str[pos] != c && str[pos++] != '\0')
		size++;
	return (size);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**tab;
	size_t		i;
	size_t		x;

	i = 0;
	x = 0;
	if (s && c)
	{
		if ((tab = malloc(sizeof(char*) * (ft_countw(s, c) + 1))) == NULL)
			return (NULL);
		while (s[i])
		{
			while (s[i] == c && s[i])
				i++;
			if (s[i] != '\0' || i == ft_wlen(s, 0, c))
			{
				tab[x] = ft_strsub(s, i, ft_wlen(s, i, c));
				tab[x++][ft_wlen(s, i, c)] = '\0';
				i = i + ft_wlen(s, i, c);
			}
		}
		tab[x] = NULL;
		return (tab);
	}
	return (NULL);
}
