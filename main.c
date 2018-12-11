/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:25:51 by achoquel          #+#    #+#             */
/*   Updated: 2018/12/11 15:58:50 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	error()
{
	ft_putendl("error");
	return (1);
}

int round_sqrt(int n)
{
	int i;

	i = 2;
	while (i * i < n)
		++i;
	return (i);
}

int			main(int ac, char **av)
{
	char	**map;
	char	*tetri_map;
	int		size;
	t_tetri	tetri_list[26 + 1];

	if (ac != 2)
	{
		ft_putendl("usage: ./fillit [file]");
		return (1);
	}
	//ft_bzero(tetri_list, sizeof(t_tetri) * (26 + 1));
	map = NULL;
	if (check_errors(av[1], &tetri_map) != 0)
		return (error());
	size = init_tetri_list(tetri_list, tetri_map);
	//ft_putstr("\n");
	size = round_sqrt(size * 4);
	while ((map = solve(tetri_list, size)) == NULL)
		++size;
	print_map(map);
	return (0);
}
