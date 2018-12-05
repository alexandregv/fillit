/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:28:41 by achoquel          #+#    #+#             */
/*   Updated: 2018/11/23 12:19:22 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*fresh;

	if ((fresh = malloc(sizeof(void) * size)) == NULL)
		return (NULL);
	ft_memset(fresh, 0, size);
	return (fresh);
}
