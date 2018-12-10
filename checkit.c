/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:04:07 by achoquel          #+#    #+#             */
/*   Updated: 2018/12/10 13:05:34 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_line(char *line, int nline)
{
	int	pos;
	
	pos = 0;
	if (nline > 0 && nline % 5 == 0)
	{
		if (ft_strcmp(line, "") != 0)
			return (-1);
	}
	else
	{
		if (line[4] != '\0')
			return (-1);
		while (pos < 4)
		{
			if (line[pos] == '.' || line[pos] == '#')
				pos++;
			else
				return (-1);
		}
	}
	return (0);
}

static int	check_file(int fd, char **tetri_map)
{

	char	*line;
	int		nline;
	int		gnl;
	
	if (!(line = ft_strnew(0)) || !(*tetri_map = ft_strnew(0)))
		return (-1);
	nline = 1;
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		
		if (check_line(line, nline) == -1)
			return (-1);
		*tetri_map = ft_strjoin(*tetri_map, line);
		nline++;
	}
	close(fd);
	if (nline == 1 && gnl == 0)
		return (-1);
	if (gnl == -1)
		return (-1);
	return (0);
}

void	topleftit(char **tetri)
{
	char	*tmp;

	tmp = ft_strtrim(*tetri);
	if (ft_strcmp(tmp, "#..##...#") == 0)
		*tetri = ft_strdup(".#..##...#");
	else if (ft_strcmp(tmp, "##.##") == 0)
		*tetri = ft_strdup(".##.##");
	else if (ft_strcmp(tmp, "#..##..#") == 0)
		*tetri = ft_strdup(".#..##..#");
	else if (ft_strcmp(tmp, "#.###") == 0)
		*tetri = ft_strdup("..#.###");
	else if (ft_strcmp(tmp, "#...#..##") == 0)
		*tetri = ft_strdup(".#...#..##");
	else if (ft_strcmp(tmp, "#..###") == 0)
		*tetri = ft_strdup(".#..###");
	else
		*tetri = ft_strdup(tmp);
	free(tmp);
}
