/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcincean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 13:52:04 by vcincean          #+#    #+#             */
/*   Updated: 2017/02/11 18:12:43 by vcincean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>

static void	clean_up_and_error(t_vector *v)
{
	vector_destroy(v);
	f_error();
}

void		read_file(int fd, t_vector *v)
{
	t_tetrimino	t;
	int			size_read;
	char		letter;
	int			last;

	letter = 'A';
	while ((size_read = read(fd, t.t, 21)) >= 20)
	{
		last = size_read;
		t.t[4][1] = 0x0;
		arrange_tetris(&t);
		if (validate_tetris(&t) == 0)
			clean_up_and_error(v);
		t.letter = letter++;
		vector_push_back(v, t);
	}
	if (size_read != 0 || last == 21 || letter == 'A')
		clean_up_and_error(v);
	t.letter = CHAR_NULL;
	vector_push_back(v, t);
}
