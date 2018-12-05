/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:21:00 by achoquel          #+#    #+#             */
/*   Updated: 2018/11/23 12:23:10 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

static int		ft_is_blank(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

static int		ft_start(char const *s)
{
	int	st;

	st = 0;
	if (!ft_is_blank(s[st]))
		return (st);
	else
	{
		while (ft_is_blank(s[st]))
		{
			st++;
		}
	}
	return (st);
}

static int		ft_stop(char const *s)
{
	int	sp;

	sp = ft_strlen((char *)s) - 1;
	if (!ft_is_blank(s[sp]))
		return (sp);
	else
	{
		while (ft_is_blank(s[sp]))
		{
			sp--;
		}
	}
	return (sp);
}

char			*ft_strtrim(char const *s)
{
	int		start;
	int		stop;
	char	*f;

	if (s)
	{
		start = ft_start(s);
		stop = ft_stop(s);
		if ((stop - start + 1) < 0)
		{
			if ((f = (char *)malloc(sizeof(char) * 1)) == NULL)
				return (NULL);
			f[0] = '\0';
		}
		else
		{
			if ((f = (char *)malloc(sizeof(char) * (stop - start + 1))) == NULL)
				return (NULL);
			f = ft_strsub(s, start, (stop - start + 1));
			f[stop - start + 1] = '\0';
		}
		return (f);
	}
	return (NULL);
}
