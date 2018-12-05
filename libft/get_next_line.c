/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 09:02:29 by achoquel          #+#    #+#             */
/*   Updated: 2018/12/05 12:35:28 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

static char	*get_file(char *file, int fd)
{
	int		rd;
	char	*buff;
	char	*tmp;

	if ((buff = (char*)malloc(BUFF_SIZE + 1)) == NULL)
		return (NULL);
	while (!ft_strchr(file, '\n') && (rd = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[rd] = '\0';
		tmp = file;
		if ((file = ft_strjoin(file, buff)) == NULL)
			return (NULL);
		free(tmp);
	}
	free(buff);
	return (file);
}

int			get_next_line(int fd, char **line)
{
	int			pos;
	static char	*file[1024];

	if (BUFF_SIZE <= 0 || line == NULL || read(fd, file, 0) < 0 ||
	(file[fd] == NULL && !(file[fd] = ft_strnew(0))))
		return (-1);
	file[fd] = get_file(file[fd], fd);
	pos = 0;
	if (file[fd][0])
	{
		while (file[fd][pos] != '\n' && file[fd][pos])
			pos++;
		if (pos == 0)
			*line = ft_strdup("");
		else
			*line = ft_strsub(file[fd], 0, pos);
		if (file[fd][pos] == '\n' && (file[fd] =
			ft_memmove(file[fd], (file[fd] + pos + 1), ft_strlen(file[fd]))))
			;
		else if (!(file[fd] = NULL))
			free(file[fd]);
		return (1);
	}
	*line = ft_strdup("");
	return (0);
}
