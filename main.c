/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:25:51 by achoquel          #+#    #+#             */
/*   Updated: 2018/12/08 12:29:08 by aguiot--         ###   ########.fr       */
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

void	print_chars(unsigned short octet)
{
	int		i;
	int		j;
	char	*str;

	i = 0b1000000000000000;
	j = 15;
	str = (char*)malloc(sizeof(char) * 17);
	while (octet >= 0 && i)
	{
		str[j] = (octet / i) ? '#': '.';
		(octet / i) ? octet -= i : 0;
		i /= 2;
		--j;
	}
	ft_putstr(str);
	ft_putchar('\n');
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
