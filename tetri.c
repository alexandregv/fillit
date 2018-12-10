/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:30:53 by aguiot--          #+#    #+#             */
/*   Updated: 2018/12/10 16:43:23 by aguiot--         ###   ########.fr       */
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

int 	init_tetri_list(t_tetri tetri_list[], char *tetri_map)
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
