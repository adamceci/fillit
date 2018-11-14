/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_final_board.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 12:25:29 by aceciora          #+#    #+#             */
/*   Updated: 2018/09/03 14:13:24 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**create_board(int min_size)
{
	char	**board;
	int		i;
	int		j;

	if (!(board = (char**)malloc(sizeof(*board) * min_size)))
		return (NULL);
	i = 0;
	while (i < min_size)
	{
		if (!(board[i] = (char*)malloc(sizeof(**board) * (min_size + 2))))
			return (NULL);
		j = 0;
		while (j < min_size)
		{
			board[i][j] = '.';
			j++;
		}
		board[i][min_size] = '\n';
		board[i][min_size + 1] = '\0';
		i++;
	}
	return (board);
}

int			free_place(char **board, t_tetri *lst_tetri, int *tab, int min_size)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	while (i < 4)
	{
		x = lst_tetri->tabx[i];
		y = lst_tetri->taby[i];
		if (x + tab[0] < min_size && board[x + tab[0]][y + tab[1]] == '.')
			i++;
		else
			return (0);
	}
	return (1);
}

void		put_tetri(char **board, t_tetri *lst_tetri, int a, int b)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	while (i < 4)
	{
		x = lst_tetri->tabx[i];
		y = lst_tetri->taby[i];
		board[x + a][y + b] = lst_tetri->fill_char;
		i++;
	}
}
