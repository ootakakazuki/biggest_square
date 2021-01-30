/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuroish <kkuroish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 19:00:13 by kkuroish          #+#    #+#             */
/*   Updated: 2020/02/25 04:30:58 by kkuroish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	print_c(char **square)
{
	int		i;
	int		j;

	i = 0;
	while (square[i])
	{
		j = 0;
		while (square[i][j])
		{
			write(1, &square[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}


void	print_i(int **dp, int row_col_count)
{
	int		i;
	int		j;

	i = 0;
	while (i < row_col_count)
	{
		j = 0;
		while (j < g_width)
		{
			printf("%2d", dp[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
