/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 12:26:24 by aceciora          #+#    #+#             */
/*   Updated: 2018/09/03 14:13:29 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!is_valid_file(argv[1]))
		{
			ft_putstr("error\n");
			return (0);
		}
	}
	else
		ft_putstr("usage: ./fillit source_file\n");
	return (0);
}
