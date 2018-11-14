/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_modif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 12:26:14 by aceciora          #+#    #+#             */
/*   Updated: 2018/09/03 14:09:22 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		change_char(char *tab, char fill_char)
{
	while (*tab)
	{
		if (*tab == '#')
			*tab = fill_char;
		tab++;
	}
}

void		find_min(char **array, char letter, int *min_i, int *min_j)
{
	int			i;
	int			j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (array[i][j] == letter)
			{
				if (i < *min_i)
					*min_i = i;
				if (j < *min_j)
					*min_j = j;
			}
			j++;
		}
		i++;
	}
}
