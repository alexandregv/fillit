/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:41:21 by aguiot--          #+#    #+#             */
/*   Updated: 2018/12/10 17:50:30 by aguiot--         ###   ########.fr       */
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

int			is_placable(char **map, int size, t_tetri tetri, int xx, int yy)
{
	int	i;
	int x;
	int y;

	i = 0;
	if (tetri.tetri[0] == '.' && tetri.tetri[1] == '.')
		i += 2;
	else if (tetri.tetri[0] == '.')
		++i;

	y = yy;	
	while (map[y])
	{
		x = xx;
		while (map[y][x + (size - 4)])
		{
			printf("map[y][x]=%c | tetri[i]=%c | y=%d | x=%d | i=%d", map[y][x], tetri.tetri[i], y, x, i);
			if (map[y][x] == '.' && tetri.tetri[i] == '#')
			{
				map[y][x] = tetri.letter;
				printf(" ✔️  case placable");
			}
			else if (tetri.tetri[i] == '#')
			{
				printf(" ❌ case non placable");
				remove_tetri(map, tetri.letter);
				return (0);
			}
			printf("\n");
			++x;
			++i;
			if (tetri.tetri[i] == '\0')
			{
				ft_putendl("fin");
				return (1);
			}
		}
		printf("---------------------\n");
		++y;
	}
	return (0);
}

void		place_tetri(char **map, t_tetri tetri, int x, int y)
{
	
}

int	backtrack(char **map, t_tetri tetri_list[])
{
	return (1);
}

char	**solve(t_tetri tetri_list[], int size)
{
	char	**map;
setbuf(stdout, NULL); //pour debug printf
	if (!(map = new_map(size)))
		error();
	/*if (backtrack(map, tetri_list))
		return (map);
	else
	{
		clear_map(map);
		return (0);
	}*/
	ft_putendl(tetri_list[0].tetri);
	if (is_placable(map, size, tetri_list[0], 0, 0))
		printf("🆗 TETRI PLACE\n");
	else
		printf("\n 🚫 TETRI PAS PLACE\n");

	if (is_placable(map, size-1, tetri_list[1], 1, 0))
		printf("🆗 TETRI PLACE\n");
	else
		printf("\n 🚫 TETRI PAS PLACE\n");

	if (is_placable(map, size-2, tetri_list[2], 2, 0))
		printf("🆗 TETRI PLACE\n");
	else
		printf("\n 🚫 TETRI PAS PLACE\n");

	if (is_placable(map, size, tetri_list[3], 0, 4))
		printf("🆗 TETRI PLACE\n");
	else
		printf("\n 🚫 TETRI PAS PLACE\n");

	return (map);
}
