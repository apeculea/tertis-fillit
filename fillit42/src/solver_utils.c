/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcincean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 11:56:28 by vcincean          #+#    #+#             */
/*   Updated: 2017/01/31 11:58:51 by vcincean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_height(t_tetrimino t)
{
	int	height;
	int	i;
	int	j;

	height = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (t.t[i][j] == CHAR_HASH)
			{
				height = i + 1;
				break ;
			}
			j++;
		}
		i++;
	}
	return (height);
}

int		get_width(t_tetrimino t)
{
	int	width;
	int	i;
	int	j;

	width = 0;
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (t.t[i][j] == CHAR_HASH)
			{
				width = j + 1;
				break ;
			}
			i++;
		}
		j++;
	}
	return (width);
}

int		has_conflicts(t_solution *sol, t_tetrimino t, int x, int y)
{
	int	height;
	int	width;
	int	i;
	int	j;

	height = get_height(t);
	width = get_width(t);
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (t.t[i][j] == CHAR_HASH && sol->matrix[x + i][y + j] != CHAR_DOT)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	put_tetrimino(t_solution *sol, t_tetrimino t, int x, int y)
{
	int	height;
	int	width;
	int	i;
	int	j;

	height = get_height(t);
	width = get_width(t);
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (t.t[i][j] == CHAR_HASH)
				sol->matrix[x + i][y + j] = t.letter;
			j++;
		}
		i++;
	}
}

void	del_tetrimino(t_solution *sol, t_tetrimino t, int x, int y)
{
	int	height;
	int	width;
	int	i;
	int	j;

	height = get_height(t);
	width = get_width(t);
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (t.t[i][j] == CHAR_HASH)
				sol->matrix[x + i][y + j] = CHAR_DOT;
			j++;
		}
		i++;
	}
}
