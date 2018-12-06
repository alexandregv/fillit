/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:25:51 by achoquel          #+#    #+#             */
/*   Updated: 2018/12/06 18:27:53 by aguiot--         ###   ########.fr       */
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
	t_tetri	*curr_tetri;
	t_tetri	*tmp;

	if ((curr_tetri = (t_tetri*)malloc(sizeof(t_tetri))) == NULL)
		return (1);
	curr_tetri->letter = 'A';
	curr_tetri->next = NULL;
	
	i = 1;
	j = 0;
	ft_putstr("[");
	ft_putstr(tetri_map);
	ft_putstr("]\n");
	while (tetri_map[i - 1])
	{
		if (tetri_map[i - 1] == '#')
		{
			printf("%c\n", curr_tetri->letter);
			curr_tetri->bits |= 1 << (i - 1);
		}
		if (i % 16 == 0)
		{
			++j;
			ft_putstr("on change de tetri");
			print_bits(curr_tetri->bits);
			tmp = lstnew('A' + j);
			//print_bits(tmp->bits);
			tmp->next = curr_tetri;
			curr_tetri = tmp;
			//printf("%c\n", curr_tetri->letter);
			if (!curr_tetri->next)
				return (1);
		}
		++i;
	}
	//printf("\nbits = %d\n", curr_tetri->bits);
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
	init_tetri_list(tetri_list, tetri_map);
	ft_putnbr(tetri_list->bits);
	//solve_fillit(tetri_list, map);
	//print_map(map);
	return (0);
}
