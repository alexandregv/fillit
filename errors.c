/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:32:53 by aguiot--          #+#    #+#             */
/*   Updated: 2018/12/10 13:00:12 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_line(char *line, int nline)
{
	int			pos;

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

static int		check_file(int fd, char **tetri_map)
{

	char		*line;
	int			nline;
	int			gnl;

	if (!(line = ft_strnew(0)) || !(*tetri_map = ft_strnew(0)))
		return (-1);
	nline = 1;
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		if (check_line(line, nline) == -1)
			return (-1);
		char *tmp = *tetri_map;
		*tetri_map = ft_strjoin(*tetri_map, line);
		free(tmp);
		nline++;
	}
	close(fd);
	if (nline == 1 && gnl == 0)
		return (-1);
	if (gnl == -1)
		return (-1);
	return (0);
}

int		check_tetrimino(char *grid)
{
	int	conn;
	int	i;

	conn = 0;
	i = 0;
	while (grid[i] && i < 16)
	{
		if (grid[i] == '#')
		{
			if ((i + 1 % 4 != 0) && (i + 1 < 16) && grid[i + 1] == '#')
				++conn;
			if ((i % 4 != 0) && (i - 1 >= 0) && grid[i - 1] == '#')
				++conn;
			if ((i + 4 < 16) && grid[i + 4] == '#')
				++conn;
			if ((i - 4 >= 0) && grid[i - 4] == '#')
				++conn;
		}
		++i;
	}
	return (conn != 6 && conn != 8);
}

static int	check_all_tetriminos(char *tetri_map)
{
	char	*tetri;
	int		i;

	i = 0;
	while (tetri_map[i])
	{
		tetri = ft_strsub(tetri_map, i, 16);
		if (check_tetrimino(tetri) == 1)
			return (1);
		i += 16;
	}
	return (0);
}

int			check_errors(char *path, char **tetri_map)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (check_file(fd, tetri_map) == -1)
		return (1);
	if (check_all_tetriminos(*tetri_map) == 1)
		return (1);
	close(fd); //TODO: gerer erreurs open/close
	return (0);
}
