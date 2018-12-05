/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:25:51 by achoquel          #+#    #+#             */
/*   Updated: 2018/12/05 14:08:56 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	printf("Fichier :\n%s", map);
	return (0);
}
