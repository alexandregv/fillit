/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:41:21 by aguiot--          #+#    #+#             */
/*   Updated: 2018/12/11 17:04:45 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			remove_tetri(char **map, char letter)
{
	int    x;
	int    y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == letter)
				map[y][x] = '.';
			++x;
		}
		++y;
	}
}

int			place_tetri(char **map, int size, t_tetri tetri, int xx, int yy)
{
	int	i;
	int x;
	int y;

	i = 0;
	y = yy;
	size -= xx;
	while (map[y])
	{
		x = xx;
		while (map[y][x + (size - 4)])
		{
			if (map[y][x] == '.' && tetri.tetri[i] == '#')
				map[y][x] = tetri.letter;
			else if (tetri.tetri[i] == '#')
			{
				remove_tetri(map, tetri.letter);
				return (0);
			}
			++x;
			++i;
			if (tetri.tetri[i] == '\0')
				return (1);
		}
		++y;
	}
	return (0);
}

int	backtrack(char **map, int size,  t_tetri tetri_list[])
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = 0;
	while(y < size && i < 9)
	{
		x = 0;
		while(x < size && i < 9)
		{
			if (place_tetri(map, size, tetri_list[i], x, y))
			{
				++i;
				printf("%d\n", i);
				x = 0;
				y = 0;
			}
			++x;
		}
		++y;
	}
	if (i == 8)
	{
		printf("[1]\n\n");
		return (1);
	}
	printf("[0]\n\n");
	return (0);
}

char	**solve(t_tetri tetri_list[], int size)
{
	char	**map;
	int		ret;
	int		y = 0;

	if (!(map = new_map(size)))
		error();
	if ((ret = backtrack(map, size, tetri_list)) == 1)
	{
		print_map(map);
		printf("\n");
		return (map);
	}
	else if (ret == 0)
	{
		while (map[y])
		{
			free(map[y]);
			y++;
		}
		free(map);
		return (NULL);
	}
	return (map);
}
