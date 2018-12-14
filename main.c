/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:25:51 by achoquel          #+#    #+#             */
/*   Updated: 2018/12/14 15:29:48 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	error(void)
{
	ft_putendl("error");
	return (1);
}

int	round_sqrt(int n)
{
	int i;

	i = 2;
	while (i * i < n)
		++i;
	return (i);
}

int	main(int ac, char **av)
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
	if (check_errors(av[1], &tetri_map) != 0)
		return (error());
	size = init_tetri_list(tetri_list, tetri_map);
	if (size > 26)
		return (error());
	size = round_sqrt(size * 4);
	while ((map = solve(tetri_list, size)) == NULL)
	{
		free_map(map);
		++size;
	}
	print_map(map);
	free_map(map);
	free(tetri_map);
	return (0);
}
