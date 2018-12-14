/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:04:28 by aguiot--          #+#    #+#             */
/*   Updated: 2018/12/13 19:14:27 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
/*
static int		sizeof_split(char const *s, char c)
{
	char		*p;

	p = (char*)s;
	while (p && *p && *p != c)
		++p;
	return (p - s);
}

static int		count_splits(char const *s, char c)
{
	int			count;
	int			mode;

	mode = 0;
	count = 0;
	while (s && *s)
	{
		if (mode && *s == c)
			mode = 0;
		if (!mode && *s != c)
		{
			mode = 1;
			++count;
		}
		++s;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**arr;
	int			split_id;
	int			i;

	if (!s || !c)
		return (NULL);
	i = 0;
	split_id = count_splits((char const *)s, c);
	if ((arr = (char**)malloc(sizeof(char*)
					* (count_splits((char const *)s, c) + 1))) == NULL)
		return (NULL);
	while (split_id-- > 0)
	{
		while (s && *s && *s == c)
			++s;
		if ((arr[i] = ft_strsub((char const*)s, 0
						, sizeof_split((char const *)s, c))) == NULL)
			return (NULL);
		s += sizeof_split(s, c);
		++i;
	}
	arr[i] = 0;
	return (arr);
}
*/

static int    ft_countwords(char const *s, char c)
{
	int			i;
	int        j;
	int        words;

	i = 0;
	j = 0;
	words = 0;
	if (!s)
		return (0);
	while (s[i + j])
	{

		while (s[i + j] == c)
			i++;
		if (s[i + j] != '\0')
			words++;
		while (s[i + j] != c && s[i + j] != '\0')
			j++;
	}
	return (words);
}

static char    **ft_mktab(char const *s, char c, int words)
{

	int        i;
	int        j;
	char    **tab;

	i = 0;
	j = 0;
	words = ft_countwords(s, c);
	if (!(tab = (char **)malloc(sizeof(char*) * (words + 1))))
		return (NULL);
	words = -1;
	while (s[i + j])
	{
		while (s[i + j] == c)
			i++;
		if (s[i + j] != '\0')
			words++;
		while (s[i + j] != c && s[i + j] != '\0')
			j++;
		if (!(tab[words] = (char *)malloc(sizeof(char) * (j + 1))))
			return (NULL);
		i = i + j;
		j = 0;
	}
	return (tab);
}

char        **ft_strsplit(char const *s, char c)
{

	int        i;
	int        j;
	char    **tab;
	int        words;

	i = 0;
	j = 0;
	if (!s || !c)
		return (NULL);
	words = ft_countwords(s, c);
	tab = ft_mktab(s, c, words);
	words = 0;
	while (s[i + j] && words < ft_countwords(s, c))
	{
		while (s[i + j] == c)
			i++;
		while (s[i + j] != c && s[i + j] != '\0')
		{
			tab[words][j] = s[i + j];
			j++;
		}
		tab[words][j] = '\0';
		words++;
		i = i + j;
		j = 0;
	}
	tab[words] = 0;
	return (tab);
}
