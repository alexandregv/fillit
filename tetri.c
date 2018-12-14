/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:30:53 by aguiot--          #+#    #+#             */
/*   Updated: 2018/12/14 15:13:53 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*tetrim(char const *s)
{
	char	*trim;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && (s[i] == '.'))
		++i;
	j = ft_strlen(s) - 1;
	while (s[j] && (s[j] == '.'))
		--j;
	if (j == -1)
		i = 0;
	if ((trim = ft_strnew(j - i + 1)) == NULL)
		return (NULL);
	k = 0;
	while (i <= j)
		trim[k++] = s[i++];
	return (trim);
}

static void	topleft(char **tetri)
{
	char	*tmp;

	tmp = *tetri;
	*tetri = tetrim(*tetri);
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

static void	init_coords(t_tetri *tetri)
{
	int i;
	int y;
	int x;
	int k;

	i = 0;
	y = 0;
	x = 0;
	k = 0;
	while (tetri->tetri[i])
	{
		if (tetri->tetri[i] == '#')
		{
			tetri->coords[k].x = x;
			tetri->coords[k].y = y;
			++k;
		}
		++x;
		if (x == 4)
		{
			++y;
			x = 0;
		}
		++i;
	}
}

int			init_tetri_list(t_tetri tetri_list[], char *tetri_map)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (tetri_map[j])
	{
		tetri_list[i].letter = 'A' + i;
		tmp = tetri_list[i].tetri;
		tetri_list[i].tetri = ft_strsub(tetri_map, j, 16);
		free(tmp);
		tmp = tetri_list[i].tetri;
		topleft(&tetri_list[i].tetri);
		free(tmp);
		init_coords(&tetri_list[i]);
		++i;
		j += 16;
	}
	return (i);
}
