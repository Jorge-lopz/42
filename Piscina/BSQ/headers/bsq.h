/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:17:15 by jorlopez          #+#    #+#             */
/*   Updated: 2024/08/28 18:17:16 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

extern char	**g_map;
extern int	**g_res_map;
extern char	g_normal;
extern char	g_obstacle;
extern char	g_result;

void	print_bsq(int max_square, int max_ij[2], int rows, int cols);

void	start_solve(char *text, int rows, int cols);

void	frees(char *text, int rows);

void	solve_bsq(int rows, int cols);

char	*get_text(char *path);

char	*console_input(int *rows, int *cols);

char	*get_map(char *path, int *rows, int *cols);

int		generate_map(int rows, int cols, int start, char *text);

int		check_equal_rows(int i, char **text, int rows);

int		allocate_map_memory(int rows, int cols);

int		get_legend(char *text, int rows);

int		get_res_map(int rows, int cols);

int		get_rows(int start, char *text);

int		get_min_around(int i, int j);

int		check_valid_char(char chr);

int		check_dup_leyend(void);

int		get_len(char *str);

int		min(int x, int y);
