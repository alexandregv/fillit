/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:41:21 by aguiot--          #+#    #+#             */
/*   Updated: 2018/12/11 15:57:07 by achoquel         ###   ########.fr       */
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
	//		printf("map[y][x]=%c | tetri[i]=%c | y=%d | x=%d | i=%d", map[y][x], tetri.tetri[i], y, x, i);
			if (map[y][x] == '.' && tetri.tetri[i] == '#')
			{
				map[y][x] = tetri.letter;
	//			printf("case placable");
			}
			else if (tetri.tetri[i] == '#')
			{
		//		printf("case non placable");
				remove_tetri(map, tetri.letter);
				return (0);
			}
			//printf("\n");
			++x;
			++i;
			if (tetri.tetri[i] == '\0')
			{
		//		ft_putendl("fin");
				return (1);
			}
		}
		//printf("---------------------\n");
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
			if(place_tetri(map, size, tetri_list[i], x, y))
				++i;
			++x;
		}
		++y;
	}
	if (x == size - 1 && y == size - 1)
		return (0);
	return (1);

	/*
	x = 0;
	y = 0;
	while (!place_tetri(map, size, tetri_list[i], x, y))
	{
		++x;
		if (x == size - 1)
		{
			x = 0;
			++y;
		}
		if (x == size - 1 && y == size - 1)
			return (0);
	}
	if (backtrack(map, size, tetri_list, i + 1) == 1)
		return (1);
	if (tetri_list[i].tetri == NULL)
		return (0);
	return (1);
	*/
}

char	**solve(t_tetri tetri_list[], int size)
{
	char	**map;
	setbuf(stdout, NULL); //pour debug printf
	if (!(map = new_map(size)))
		error();
	if (backtrack(map, size, tetri_list))
		return (map);
	else
	{
		clear_map(map);
		return (NULL);
	}/*
		ft_putendl(tetri_list[0].tetri);
		if (place_tetri(map, size, tetri_list[0], 0, 0))
		printf("🆗 TETRI PLACE\n");
		else
		printf("\n 🚫 TETRI PAS PLACE\n");

		if (place_tetri(map, size, tetri_list[1], 1, 0))
		printf("🆗 TETRI PLACE\n");
		else
		printf("\n 🚫 TETRI PAS PLACE\n");

		if (place_tetri(map, size, tetri_list[2], 2, 0))
		printf("🆗 TETRI PLACE\n");
		else
		printf("\n 🚫 TETRI PAS PLACE\n");

		if (place_tetri(map, size, tetri_list[3], 4, 0))
		printf("🆗 TETRI PLACE\n");
		else
		printf("\n 🚫 TETRI PAS PLACE\n");
		printf("%s\n", tetri_list[4].tetri);

		if (place_tetri(map, size, tetri_list[4], 2, 2))
		printf("🆗 TETRI PLACE\n");
		else
		printf("\n 🚫 TETRI PAS PLACE\n");

		if (place_tetri(map, size, tetri_list[5], 0, 3))
		printf("🆗 TETRI PLACE\n");
		else
		printf("\n 🚫 TETRI PAS PLACE\n");

		return (map);*/
}
