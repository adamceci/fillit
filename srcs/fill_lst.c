/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 12:26:06 by aceciora          #+#    #+#             */
/*   Updated: 2018/09/03 14:09:07 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**topleft(char **array, char letter)
{
	int			i;
	int			j;
	int			min_i;
	int			min_j;

	min_i = 16;
	min_j = 16;
	find_min(array, letter, &min_i, &min_j);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (array[i][j] == letter)
			{
				array[i][j] = '.';
				array[i - min_i][j - min_j] = letter;
			}
			j++;
		}
		i++;
	}
	return (array);
}

static char		**remap(char *tab)
{
	int			i;
	int			j;
	int			k;
	char		**array;

	if (!(array = (char**)malloc(sizeof(*array) * 4)))
		return (0);
	i = 0;
	k = 0;
	while (i < 4)
	{
		if (!(array[i] = (char*)malloc(sizeof(array) * 6)))
			return (0);
		j = 0;
		while (j < 5)
		{
			array[i][j] = tab[k];
			j++;
			k++;
		}
		array[i][4] = '\n';
		array[i][5] = '\0';
		i++;
	}
	return (array);
}

static int		get_pos(t_tetri *lst)
{
	int			i;
	int			j;
	int			k;

	if (!(lst->tabx = (int*)malloc(sizeof(lst->tabx) * 4)))
		return (0);
	if (!(lst->taby = (int*)malloc(sizeof(lst->taby) * 4)))
		return (0);
	k = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (lst->array[i][j] == lst->fill_char)
			{
				lst->tabx[k] = i;
				lst->taby[k] = j;
				k++;
			}
		}
	}
	return (1);
}

static t_tetri	*fill_elem(char *tmp, int i)
{
	t_tetri		*lst;
	char		letter;

	letter = ('A' + i);
	lst = NULL;
	if (!(lst = malloc(sizeof(t_tetri))))
		return (NULL);
	if (lst)
	{
		lst->tab = tmp;
		lst->fill_char = letter;
		change_char(lst->tab, lst->fill_char);
		lst->array = remap(lst->tab);
		lst->array = topleft(lst->array, lst->fill_char);
		if (!get_pos(lst))
			return (NULL);
		if (!(lst->tabx) || !(lst->taby))
			return (NULL);
		lst->next = NULL;
	}
	return (lst);
}

int				fill_lst(char *tmp, int i, t_tetri **lst_tetri)
{
	t_tetri		*lst;

	lst = *lst_tetri;
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		lst->next = fill_elem(tmp, i);
		if (!lst->next)
			return (0);
	}
	else
	{
		*lst_tetri = fill_elem(tmp, i);
		if (!(*lst_tetri))
			return (0);
	}
	return (1);
}
