/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 12:26:51 by aceciora          #+#    #+#             */
/*   Updated: 2018/09/03 14:10:51 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int		existing_file(char *file)
{
	int		fd;
	char	buf[BUF_SIZE];

	fd = open(file, O_RDONLY);
	if (read(fd, buf, BUF_SIZE) == -1)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

static	int		get_nb_tetri(char *file)
{
	int		nb_tetri;
	int		fd;
	int		ret;
	char	buf[BUF_SIZE];
	int		rows;

	rows = 0;
	fd = open(file, O_RDONLY);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		if (buf[0] == '\n')
			rows++;
	}
	close(fd);
	nb_tetri = (rows / 5) + 1;
	return (nb_tetri);
}

static	int		get_nb_rows(char *str)
{
	int		nb_rows;

	nb_rows = 0;
	while (*str)
	{
		if (*str == '\n')
			nb_rows++;
		str++;
	}
	return (nb_rows);
}

static	int		get_infos(char *file, char *str)
{
	int		nb_tetri;
	int		nb_rows;
	int		i;
	char	*tmp;
	t_tetri	*lst_tetri;

	lst_tetri = NULL;
	nb_tetri = get_nb_tetri(file);
	i = 0;
	while (i < nb_tetri)
	{
		i == (0) ? (tmp = ft_strsub(str, 0, 20)) :
		(tmp = ft_strsub(str, i * 20 + i, 20));
		tmp[20] = '\0';
		nb_rows = get_nb_rows(tmp);
		if (!get_nb_diese(tmp) || !is_correct_char(tmp) ||
				!is_valid_size(tmp, nb_rows) || count_touch(tmp) < 6)
			return (0);
		if (!fill_lst(tmp, i, &lst_tetri))
			return (0);
		i++;
	}
	if (!solve(lst_tetri, nb_tetri))
		return (0);
	return (1);
}

int				is_valid_file(char *file)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE];
	int		size;
	char	*str;

	if (!existing_file(file))
		return (0);
	size = 0;
	fd = open(file, O_RDONLY);
	while ((ret = read(fd, buf, BUF_SIZE)))
		size++;
	close(fd);
	if (!(str = (char*)malloc(sizeof(*str) * size + 1)))
		return (0);
	fd = open(file, O_RDONLY);
	ret = read(fd, str, size);
	str[ret] = '\0';
	close(fd);
	if (!get_infos(file, str))
		return (0);
	free(str);
	return (1);
}
