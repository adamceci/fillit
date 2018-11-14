/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_logic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 12:25:57 by aceciora          #+#    #+#             */
/*   Updated: 2018/09/03 13:55:37 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_nb_diese(char *str)
{
	int	nb_diese;

	nb_diese = 0;
	while (*str)
	{
		if (*str == '#')
			nb_diese++;
		str++;
	}
	if (nb_diese != 4)
		return (0);
	return (1);
}

int		is_correct_char(char *str)
{
	while (*str)
	{
		if (*str != '.' && *str != '#' && *str != '\n')
			return (0);
		str++;
	}
	return (1);
}

int		is_valid_size(char *str, int nb_rows)
{
	int	i;
	int	count_line;

	i = 0;
	count_line = 0;
	if (nb_rows != 4)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			count_line++;
		if (i % 5 == 4 && str[i] != '\n')
			return (0);
		i++;
	}
	if (count_line != 4)
		return (0);
	return (1);
}
