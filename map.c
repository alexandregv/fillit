/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:55:24 by aguiot--          #+#    #+#             */
/*   Updated: 2018/12/10 16:33:41 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**new_map(int size)
{
	char	**map;
	int		x;
	int		y;

	if ((map = malloc(sizeof(char *) * size + 1)) == NULL)
		return (NULL);
	y = 0;
	while (y < size)
	{
		x = 0;
		map[y] = ft_strnew(size);
		while (x < size)
		{
			map[y][x] = '.';
			++x;
		}
		y++;
	}
	map[y] = NULL;
	return (map);
}

void    print_map(char **map)
{

	int    x;
	int    y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			ft_putchar(map[y][x]);
			++x;
		}
		ft_putchar('\n');
		++y;
	}
}

void	clear_map(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			map[y][x] = '.';
			++x;
		}
		++y;
	}
}

int		is_map_full(char **map)
{
	int	holes;
	int	x;
	int	y;

	holes = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '.')
				++holes;
			++x;
		}
		++y;
	}
	if (holes < 4)
		return (1);
	return (0);
}
