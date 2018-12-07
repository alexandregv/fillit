/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:25:51 by achoquel          #+#    #+#             */
/*   Updated: 2018/12/07 11:52:46 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	error()
{
	ft_putendl("error");
	return (1);
}

void	print_bits(unsigned short octet)
{
	int	i;

	i = 0b1000000000000000;
	ft_putchar('\n');
	while (octet >= 0 && i)
	{
		(octet / i) ? write(1, "1", 1) : write(1, "0", 1);
		(octet / i) ? octet -= i : 0;
		i /= 2;
	}
	ft_putchar('\n');
}

int 	init_tetri_list(t_tetri *tetri_list, char *tetri_map)
{
	int		i;
	int		j;
	t_tetri	*head;
	t_tetri	*tmp;

	head = tetri_list;
	tetri_list->letter = 'A';
	tetri_list->next = NULL;
	i = 0;
	j = 0;
	ft_putstr(tetri_map);
	while (tetri_map[i])
	{
		if (tetri_map[i] == '#')
			tetri_list->bits |= 1 << (i - (j * 16));
		if (i > 0 && i % 16 == 0)
		{
			print_bits(tetri_list->bits);
			++j;
			tmp = lstnew('A' + j);
			lstadd(&head, tmp);
			tetri_list = head;
		}
		++i;
	}
	print_bits(tetri_list->bits);
	return (0);
}

int			main(int ac, char **av)
{
	char	**map;
	char	*tetri_map;
	t_tetri	*tetri_list;

	if (ac != 2)
	{
		ft_putendl("usage: ./fillit [file]");
		return (1);
	}
	tetri_map = NULL;
	map = NULL;
	if (check_errors(av[1], &tetri_map) != 0)
		return (error());
	init_map(map);
	tetri_list = (t_tetri *)malloc(sizeof(t_tetri));
	init_tetri_list(tetri_list, tetri_map);
	ft_putnbr(tetri_list->bits);// CAUSE SEGFAULT PCK TETRI_LIST PAS INIT
	ft_putstr("\n");
	//solve_fillit(tetri_list, map);
	//print_map(map);
	return (0);
}
