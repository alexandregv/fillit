/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:25:51 by achoquel          #+#    #+#             */
/*   Updated: 2018/12/10 14:00:38 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	error()
{
	ft_putendl("error");
	return (1);
}

int			main(int ac, char **av)
{
	char	**map;
	char	*tetri_map;
	t_tetri	tetri_list[26 + 1];

	if (ac != 2)
	{
		ft_putendl("usage: ./fillit [file]");
		return (1);
	}
	ft_bzero(tetri_list, sizeof(t_tetri) * (26 + 1));
	map = NULL;
	if (check_errors(av[1], &tetri_map) != 0)
		return (error());
	init_map(map);
	init_tetri_list(tetri_list, tetri_map);
	//ft_putnbr(tetri_list->bits);// CAUSE SEGFAULT PCK TETRI_LIST PAS INIT
	ft_putstr("\n");
	//solve_fillit(tetri_list, map);
	//print_map(map);
	return (0);
}
