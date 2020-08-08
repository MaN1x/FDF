/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 18:04:53 by maxim             #+#    #+#             */
/*   Updated: 2020/08/01 18:34:30 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"

int			get_map_height(char *path)
{
	int		fd;
	int		height;
	char	buf;

	height = 1;
	fd = open(path, O_RDONLY);
	while (read(fd, &buf, 1) > 0)
		if (buf == '\n')
			height++;
	close(fd);
	if (buf == '\n')
		height--;
	return (height);
}

static void	inc_i_and_flag(char buf, int *i, int *digit_flag)
{
	if (buf == '\n')
	{
		(*i)++;
		*digit_flag = 0;
	}
	else if (ft_isspace(buf))
		*digit_flag = 0;
}

int			*get_map_widths(char *path, int map_height)
{
	int		i;
	int		fd;
	int		digit_flag;
	int		*widths;
	char	buf;

	i = 0;
	digit_flag = 0;
	widths = (int*)malloc(sizeof(int) * map_height);
	ft_bzero(widths, sizeof(int) * map_height);
	fd = open(path, O_RDONLY);
	while (read(fd, &buf, 1))
	{
		inc_i_and_flag(buf, &i, &digit_flag);
		if (ft_isdigit(buf) && digit_flag == 0)
		{
			widths[i]++;
			digit_flag = 1;
		}
	}
	close(fd);
	return (widths);
}

int			get_amount_elements(int height, const int *widths)
{
	int amount;

	amount = 0;
	while (height--)
		amount += widths[height];
	return (amount);
}
