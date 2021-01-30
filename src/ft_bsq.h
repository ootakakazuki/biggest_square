/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuroish <kkuroish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 17:36:48 by kkuroish          #+#    #+#             */
/*   Updated: 2020/02/24 15:33:17 by kkuroish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

int		g_i;
int		g_j;
int		g_row;
char	g_empty;
char	g_obstacle;
char	g_full;
int		g_width;

typedef struct	s_tmpstr
{
	char		*g_buf0;
	char		*g_buf;
	int			**dp;
	char		**square;
}				t_tmpstr;


void    g_val_set(int num, char *g_buf0, int size);
int     ft_atoi(char *g_buf0, int size);
void	read_stdhoge(char *buf_res);
int		check_dup(void);
char	*get_row(char *g_buf, int i);
int		my_min(int x, int y);
int		check_row(char *g_buf);
void	file_process(char *file_name, char *g_buf_hoge);
int		check_buf_contents(char *g_buf);
int		count_row(char *g_buf);
char	**malloc_tab(char *g_buf, int row_col_count);
int		**malloc_dp(int row_col_count);
void	print_c(char **square);
void	print_i(int **dp, int row_col_count);
void	bunkatu(char **square, int **dp, int i, int j);
int		calc(int **dp, char **square, int row_col_count);
void	place_x(char **square, int ans);
void	free_square(char **square, int row_col_count);
void	free_dp(int **dp, int row_col_count);
void	bsq_process(int argc, char **file_arr);

#endif
