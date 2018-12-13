/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:41:21 by aguiot--          #+#    #+#             */
/*   Updated: 2018/12/13 13:44:18 by aguiot--         ###   ########.fr       */
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

int			is_placable(char **map, int size, t_tetri tetri, int xx, int y)
{
	int i;
	int x;

	i = 0;
	while (map[y])
	{
		x = xx;
		size -= xx;
		while (map[y][x + (size - 4)])
		{
			if (tetri.tetri[i] == '#' && map[y][x] != '.')
			{
				printf("%c x: %d y:%d %d\n", tetri.letter, x, y, 0);
				return (0);	
			}
			++x;
			++i;
			if (tetri.tetri[i] == '\0')
			{
				printf("%c x: %d y:%d %d i: %d \\0 \n", tetri.letter, x, y, i, 1);
				return (1);
			}
		}
		printf("%c x: %d y:%d %d\n", tetri.letter, x, y, 1);
		++y;
	}
	return (1);
}

int			ppplace_tetri(char **map, int size, t_tetri tetri, int xx, int y)
{
	int	i;
	int x;

	i = 0;
	if(is_placable(map, size, tetri, xx, y))
	{
		
		size -= xx;
		while (map[y])
		{
			x = xx;
			while (map[y][x + (size - 4)])
			{
				if (tetri.tetri[i] == '#' && map[y][x + (size - 4)] == '.')
					map[y][x] = tetri.letter;
				++x;
				++i;
				if (tetri.tetri[i] == '\0')
					return (1);
			}
			++y;
		}
		printf("WTF ????");
	}
	return (0);
}

int	backtrack(char **map, int size,  t_tetri tetri_list[], int i)
{
	int	x;
	int	y;

	y = 0;
	if (tetri_list[i].tetri == NULL)
		return (1);
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (place_tetri(map, size, tetri_list[i], x, y))
			{
				//print_map(map);
				//ft_putchar('\n');
				if (backtrack(map, size, tetri_list, i + 1))
					return (1);
				else
				{
					//printf("on remove %c\n", tetri_list[i].letter);
					remove_tetri(map, tetri_list[i].letter);
				}
			}
			++x;
		}
		++y;
	}
	return (0);
}

char	**solve(t_tetri tetri_list[], int size)
{
	char	**map;
	int		ret;
	int		y = 0;

	map = new_map(size);
	while (!backtrack(map, size, tetri_list, 0))
		map = new_map(++size);
	return (map);
}
