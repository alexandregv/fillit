/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 11:19:03 by achoquel          #+#    #+#             */
/*   Updated: 2018/12/14 13:10:30 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "libft/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> //TODO: retirer stdio (printf)

typedef struct		s_pos{
		int			x;
		int			y;
}					t_pos;

typedef struct		s_tetri {
		char		*tetri;
		char		letter;
		t_pos		coords[4];
}					t_tetri;

int				error(void);
int				check_errors(char *path, char **tetri_map);
char			**new_map(int size);
void			print_map(char **map);
int				init_tetri_list(t_tetri tetri_list[], char *tetri_map);
int				check_tetrimino(char *grid);
char			**solve(t_tetri tetri_list[], int size);
void			free_map(char **map);
#endif
