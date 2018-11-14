/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 12:25:38 by aceciora          #+#    #+#             */
/*   Updated: 2018/09/03 14:13:26 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	del_tetri(char **board, t_tetri *lst_tetri, int a, int b)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	while (i < 4)
	{
		x = lst_tetri->tabx[i];
		y = lst_tetri->taby[i];
		board[x + a][y + b] = '.';
		i++;
	}
}

static int	fill_board(char **board, int min_size, t_tetri *lst_tetri)
{
	int		tab[2];

	if (lst_tetri)
	{
		tab[0] = -1;
		while (++tab[0] < min_size)
		{
			tab[1] = -1;
			while (++tab[1] < min_size)
			{
				if (free_place(board, lst_tetri, tab, min_size))
				{
					put_tetri(board, lst_tetri, tab[0], tab[1]);
					if (fill_board(board, min_size, lst_tetri->next))
						return (1);
					del_tetri(board, lst_tetri, tab[0], tab[1]);
				}
			}
		}
		if (tab[0] == min_size && tab[1] == min_size)
			return (0);
	}
	return (1);
}

void		free_board(char **board, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		free(board[i]);
		i++;
	}
	free(board);
}

static void	print_board(char **board, int min_size)
{
	int		i;

	i = 0;
	while (i < min_size)
	{
		ft_putstr(board[i]);
		i++;
	}
}

int			solve(t_tetri *lst_tetri, int nb_tetri)
{
	int		min_size;
	char	**board;
	int		finish;

	min_size = ft_sqrt(nb_tetri * 4);
	finish = 0;
	while (!finish)
	{
		board = create_board(min_size);
		if (!board)
			return (0);
		if (!fill_board(board, min_size, lst_tetri))
		{
			free_board(board, min_size);
			min_size++;
		}
		else
		{
			print_board(board, min_size);
			finish = 1;
		}
	}
	return (1);
}
