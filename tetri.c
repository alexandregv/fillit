/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:30:53 by aguiot--          #+#    #+#             */
/*   Updated: 2018/12/13 16:20:43 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	topleft(char **tetri)
{
	*tetri = ft_strtrim(*tetri);
	if (ft_strcmp(*tetri, "#..##...#") == 0)
		*tetri = ft_strdup(".#..##...#");
	else if (ft_strcmp(*tetri, "##.##") == 0)
		*tetri = ft_strdup(".##.##");
	else if (ft_strcmp(*tetri, "#..##..#") == 0)
		*tetri = ft_strdup(".#..##..#");
	else if (ft_strcmp(*tetri, "#.###") == 0)
		*tetri = ft_strdup("..#.###");
	else if (ft_strcmp(*tetri, "#...#..##") == 0)
		*tetri = ft_strdup(".#...#..##");
	else if (ft_strcmp(*tetri, "#..###") == 0)
		*tetri = ft_strdup(".#..###");
}

int 	iiiiinit_tetri_list(t_tetri tetri_list[], char *tetri_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tetri_map[j])
	{
		tetri_list[i].letter = 'A' + i;
		tetri_list[i].tetri  = ft_strsub(tetri_map, j, 16);
		topleft(&tetri_list[i].tetri);
		++i;
		j += 16;
	}
	return (i);
}

int 	init_tetri_list(t_tetri tetri_list[], char *tetri_map)
{
	int	i;
	int	j;
	int x;
	int y;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	while (tetri_map[j])
	{
		tetri_list[i].letter = 'A' + i;
		tetri_list[i].tetri  = ft_strsub(tetri_map, j, 16);
		topleft(&tetri_list[i].tetri);

		tetri_list[i].coords[0].x = x; 
		tetri_list[i].coords[0].y = y;
		++x;
		if (x % 4 == 0)
			++y;
		
		++i;
		j += 16;
	}
	return (i);
}
