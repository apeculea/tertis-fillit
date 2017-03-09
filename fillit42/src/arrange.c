/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeculea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 11:50:24 by apeculea          #+#    #+#             */
/*   Updated: 2017/02/11 17:45:12 by vcincean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	up(char tetr[5][5])
{
	int		j;

	j = -1;
	while (++j < 4)
	{
		tetr[0][j] = tetr[1][j];
		tetr[1][j] = tetr[2][j];
		tetr[2][j] = tetr[3][j];
		tetr[3][j] = '.';
	}
}

static void	left(char tetr[5][5])
{
	int		i;

	i = -1;
	while (++i < 4)
	{
		tetr[i][0] = tetr[i][1];
		tetr[i][1] = tetr[i][2];
		tetr[i][2] = tetr[i][3];
		tetr[i][3] = '.';
	}
}

static void	up_left(char tetr[5][5])
{
	while (tetr[0][0] == '.' && tetr[1][0] == '.' && tetr[2][0] == '.' &&
		tetr[3][0] == '.')
		left(tetr);
	while (tetr[0][0] == '.' && tetr[0][1] == '.' && tetr[0][2] == '.' &&
		tetr[0][3] == '.')
		up(tetr);
}

void		arrange_tetris(t_tetrimino *t)
{
	if (ft_strchr((const char *)t->t, '#') != 0)
		up_left(t->t);
}
