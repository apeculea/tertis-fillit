/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeculea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 11:51:21 by apeculea          #+#    #+#             */
/*   Updated: 2017/02/11 17:40:29 by vcincean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	neighbours(char tetr[5][5], int i, int j)
{
	int	count;

	count = 0;
	if (j > 0 && tetr[i][j - 1] == '#')
		count++;
	if (j < 3 && tetr[i][j + 1] == '#')
		count++;
	if (i > 0 && tetr[i - 1][j] == '#')
		count++;
	if (i < 3 && tetr[i + 1][j] == '#')
		count++;
	if (1 <= count && count <= 3)
		return (count);
	return (0);
}

static int	verif(char tetr[5][5])
{
	int	i;
	int	j;
	int	nr;
	int	adj_count;

	nr = 0;
	adj_count = 0;
	i = -1;
	while (++i < 4)
	{
		if (tetr[i][4] != '\n')
			return (0);
		j = -1;
		while (++j < 4)
		{
			if (!(tetr[i][j] == '#' || tetr[i][j] == '.'))
				return (0);
			if (tetr[i][j] == '#' && neighbours(tetr, i, j) != 0)
			{
				nr += 1;
				adj_count += neighbours(tetr, i, j);
			}
		}
	}
	return (nr == 4 && (adj_count == 6 || adj_count == 8));
}

int			validate_tetris(t_tetrimino *t)
{
	return (verif(t->t));
}
