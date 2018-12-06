/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 11:19:03 by achoquel          #+#    #+#             */
/*   Updated: 2018/12/06 10:59:28 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "libft/includes/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		check_all_tetriminos(char *map);
int		check_tetrimino(char *map);
int		ft_check_line(char *line, int nline);
int		ft_check_file(int fd, char **map);
char	**new_map(int size);
void	print_map(char **map);
void	clear_map(char **map);
int		start_size(int tcount);
int		is_map_full(char **map);

#endif
