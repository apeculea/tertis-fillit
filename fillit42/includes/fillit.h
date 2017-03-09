/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcincean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 11:54:23 by vcincean          #+#    #+#             */
/*   Updated: 2017/02/11 17:42:03 by vcincean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define CHAR_NULL '\0'
# define CHAR_DOT '.'
# define CHAR_HASH '#'

/*
**	t_tetrimino
**	-----------
**	t: a 5 x 5 matrix filled with either '.' or '#' and defining
**		a valid tetrimino; note: t[.][4] = 0, t[4][.] = 0 (...)
**	letter: an uppercase letter assigned to this tetrimino
*/

typedef struct	s_tetrimino
{
	char	t[5][5];
	char	letter;
}				t_tetrimino;

/*
**	t_vector
**	--------
**	a fixed-capacity array for storing tetriminos
**	size: the actual number of elements in the array
**	capacity: the maximum number of elements the array can store
*/

typedef struct	s_vector
{
	t_tetrimino	*array;
	int			size;
	int			capacity;
}				t_vector;

t_vector		*vector_init(int n);
void			vector_destroy(t_vector *v);
int				vector_push_back(t_vector *v, t_tetrimino t);

/*
**	t_solution
**	----------
**	a data structure that easily represents a solution to fillit
**	matrix: a N x (N + 1) matrix, initially filled with '.'s
**		except for matrix[i][n] = '\0', for any i
**		so, matrix[i], for any i, is a C character string
*/

typedef struct	s_solution
{
	char	**matrix;
	int		n;
}				t_solution;

t_solution		*solution_init(int n);
void			solution_destroy(t_solution *sol);

/*
**	Defined in validator.c
*/

int				validate_tetris(t_tetrimino *t);

/*
**	Defined in arrange.c
*/

void			arrange_tetris(t_tetrimino *t);

/*
**	Defined in reader.c
*/

void			read_file(int fd, t_vector *v);

/*
**	Defined in solver.c
*/

t_solution		*solve(t_vector *v);

/*
**	Defined in solver_utils.c
*/

int				get_height(t_tetrimino t);
int				get_width(t_tetrimino t);
int				has_conflicts(t_solution *sol, t_tetrimino t, int x, int y);
void			put_tetrimino(t_solution *sol, t_tetrimino t, int x, int y);
void			del_tetrimino(t_solution *sol, t_tetrimino t, int x, int y);

/*
**	Defined in printer.c
*/

void			print_solution(t_solution *sol);

/*
**	Defined in string_functions.h
*/

void			*ft_memset(void *s, int c, unsigned int n);
void			ft_putstr_fd(char *s, int fd);
int				ft_strlen(char *s);
char			*ft_strchr(const char *s, int c);

/*
**	Defined in main.c
*/

void			f_error(void);
void			f_usage(char *argv0);

#endif
