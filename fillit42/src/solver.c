/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcincean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 11:56:13 by vcincean          #+#    #+#             */
/*   Updated: 2017/01/31 13:09:20 by vcincean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static int	do_solve(t_solution *sol, t_tetrimino *v)
{
	int	height;
	int	width;
	int	x;
	int	y;

	if (v[0].letter == CHAR_NULL)
		return (1);
	height = get_height(v[0]);
	width = get_width(v[0]);
	x = -1;
	while (++x < sol->n - height + 1)
	{
		y = -1;
		while (++y < sol->n - width + 1)
		{
			if (!has_conflicts(sol, v[0], x, y))
			{
				put_tetrimino(sol, v[0], x, y);
				if (do_solve(sol, &v[1]) == 1)
					return (1);
				del_tetrimino(sol, v[0], x, y);
			}
		}
	}
	return (0);
}

static int	floor_sqrt(int n)
{
	int	left;
	int	mid;
	int	right;
	int	sqrt;

	if (n == 0 || n == 1)
		return (n);
	left = 1;
	right = n;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (mid * mid == n)
			return (mid);
		if (mid * mid < n)
		{
			left = mid + 1;
			sqrt = mid;
		}
		else
			right = mid - 1;
	}
	return (sqrt);
}

t_solution	*solve(t_vector *v)
{
	t_solution	*sol;
	int			size;

	size = floor_sqrt(v->size);
	sol = NULL;
	while (42 == 42)
	{
		sol = solution_init(size);
		if (sol == NULL || do_solve(sol, v->array) == 1)
			break ;
		solution_destroy(sol);
		size++;
	}
	return (sol);
}
