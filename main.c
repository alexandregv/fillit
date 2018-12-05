/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:25:51 by achoquel          #+#    #+#             */
/*   Updated: 2018/12/05 15:00:44 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_all_tetriminos(char *map)
{
	char	*tetri;
	int		i;
	
	i = 0;
	while (map[i])
	{
		tetri = ft_strsub(map, i, 20);
		if (check_tetrimino(tetri) == 1)
			return (1);
		i += 21;
	}
	return (0);
}

int	check_tetrimino(char *grid)
{
	int	parts;

	parts = 0;
	while (*grid)
	{
		if (*grid == '#')
		{
			if (parts == 4)
			{
				return (1);
			}
			if (	   *(grid + 1) == '#' 
					|| *(grid - 1) == '#' 
					|| *(grid + 5) == '#' 
					|| *(grid - 5) == '#')
			{
				++parts;
				write(1, "valide\n", 7);
			}
			else
			{
				write(1, "INVALIDE\n", 9);
				return (1);
			}
		}
		++grid;
	}
	if (parts < 4)
		return (1);
	return (0);
}

int		ft_check_line(char *line, int nline)
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

int		ft_check_file(int fd, char **map)
{
	char	*line;
	int		nline;
	int		gnl;

	if (!(line = ft_strnew(0)) || !(*map = ft_strnew(0)))
		return (-1);
	nline = 1;
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		if (ft_check_line(line, nline) == -1)
			return (-1);
		*map = ft_strjoin(*map, line);
		*map = ft_strjoin(*map, "\n");
		nline++;
	}
	close(fd);
	if (nline == 1 && gnl == 0)
		return (-1);
	if (gnl == -1)
		return (-1);
	return (0);
}

int	main(int ac, char **av)
{
	int fd;
	char	*map;

	fd = open(av[1], O_RDONLY);
	if (ft_check_file(fd, &map) == -1)
	{
		printf("Fichier non compatible\n");
		return (0);
	}
	if (check_all_tetriminos(map) == 1)
		printf("error");
	printf("Fichier :\n%s", map);
	return (0);
}
