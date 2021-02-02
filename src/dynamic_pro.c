
#include "ft_bsq.h"

/**
 *
 * 最大の正方形の長さを計算する部分。
 *
 */

int     my_min(int x, int y)
{
    return (x > y ? y : x);
}

void    bunkatu(char **square, int **dp, int i, int j)
{
	if(i == 0 || j == 0 || square[i][j] == g_obstacle)
	{
		dp[i][j] = square[i][j] == g_empty ? 1 : 0;
	}
	else
	{
		dp[i][j] = my_min(dp[i - 1][j - 1], my_min(dp[i - 1][j], dp[i][j - 1])) + 1;
	}
}

int     calc(int **dp, char **square, int row_col_count)
{
	int		i;
	int		j;
	int		ans;

	i = 0;
	ans = 0;
	while (i < row_col_count)
	{
		j = 0;
		while (j < g_width)
		{
			bunkatu(square, dp, i, j);
			if (ans < dp[i][j])
			{
				g_i = i;
				g_j = j;
				ans = dp[i][j];
			}
			j++;
		}
		i++;
	}
	return (ans);
}
