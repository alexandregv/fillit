/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:53:09 by achoquel          #+#    #+#             */
/*   Updated: 2018/11/23 12:22:33 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 && s2)
	{
		while (*s1 && *s2 && *s1 == *s2 && n)
		{
			s1++;
			s2++;
			n--;
		}
		if ((!*s1 && !*s2) || !n)
			return (1);
		else
			return (0);
	}
	return (0);
}
