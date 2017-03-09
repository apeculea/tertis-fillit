/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcincean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 11:55:11 by vcincean          #+#    #+#             */
/*   Updated: 2017/02/13 13:37:18 by vcincean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	f_error(void)
{
	ft_putstr_fd("error\n", 1);
	exit(1);
}

void	f_usage(char *argv0)
{
	ft_putstr_fd("usage: ", 1);
	ft_putstr_fd(argv0, 1);
	ft_putstr_fd(" input_file\n", 1);
	exit(1);
}

int		main(int argc, char **argv)
{
	int			fd;
	t_vector	*v;
	t_solution	*sol;

	if (argc != 2)
		f_usage(argv[0]);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		f_error();
	v = vector_init(27);
	read_file(fd, v);
	close(fd);
	sol = solve(v);
	print_solution(sol);
	vector_destroy(v);
	solution_destroy(sol);
	return (0);
}
