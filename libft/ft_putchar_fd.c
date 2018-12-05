/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:11:50 by achoquel          #+#    #+#             */
/*   Updated: 2018/11/23 12:20:13 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	unsigned char tmp;

	tmp = c;
	write(fd, &tmp, 1);
}
