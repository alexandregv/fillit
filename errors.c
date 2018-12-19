/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:32:53 by aguiot--          #+#    #+#             */
/*   Updated: 2018/12/19 14:56:47 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_line(char *line, int nline)
{
	int		pos;

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
	int		n;
	int		gnl;
	char	*tmp;

	if (!(*tetri_map = ft_strnew(0)))
		return (-1);
	n = 1;
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		if (check_line(line, n) == -1)
			free(line);
		if (check_line(line, n++) == -1)
			return (-1);
		tmp = *tetri_map;
		*tetri_map = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
	}
	close(fd);
	if ((n == 1 && gnl == 0) || (n % 5 != 0 && gnl == 0) || gnl == -1)
		return (-1);
	return (0);
}

static int	check_tetrimino(char *map)
{
	int	conn;
	int	parts;
	int	i;

	conn = 0;
	parts = 0;
	i = 0;
	while (map[i] && i < 16)
	{
		if (map[i] == '#')
		{
			if (((i + 1) % 4 != 0) && (i + 1 < 16) && map[i + 1] == '#')
				++conn;
			if ((i % 4 != 0) && (i - 1 >= 0) && map[i - 1] == '#')
				++conn;
			if ((i + 4 < 16) && map[i + 4] == '#')
				++conn;
			if ((i - 4 >= 0) && map[i - 4] == '#')
				++conn;
			++parts;
		}
		++i;
	}
	return (!(parts == 4 && (conn == 6 || conn == 8)));
}

static int	check_all_tetriminos(char *tetri_map)
{
	int		i;

	i = 0;
	while (tetri_map[i])
	{
		if (check_tetrimino(tetri_map + i) == 1)
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
	close(fd);
	return (0);
}
