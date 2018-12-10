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
	x = 0;
	y = 0;
	while (x < size)
	{
		map[x] = ft_strnew(size);
		while (y < size)
		{
			map[x][y] = '.';
			y++;
		}
		y = 0;
		x++;
	}
	map[x] = NULL;
	return (map);
}

void    print_map(char **map)
{

	int    x;
	int    y;

	x = 0;
	y = 0;
	while (map[x])
	{
		while (map[x][y])
		{
			ft_putchar(map[x][y]);
			y++;
		}
		y = 0;
		ft_putchar('\n');
		x++;
	}
}

void	clear_map(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[x])
	{
		while (map[x][y])
		{
			map[x][y] = '.';
			y++;
		}
		y = 0;
		x ++;
	}
}

int		is_map_full(char **map)
{
	int	holes;
	int	x;
	int	y;

	holes = 0;
	x = 0;
	y = 0;
	while (map[x])
	{
		while (map[x][y])
		{
			if (map[x][y] == '.')
				holes++;
			y++;
		}
		y = 0;
		x++;
	}
	if (holes < 4)
		return (1);
	return (0);
}
