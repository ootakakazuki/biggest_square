
#include "ft_bsq.h"

void	free_square(char **square, int row_col_count)
{
	int		i;

	i = 0;
	while (i < row_col_count)
	{
		if (square[i] != NULL)
		{
			square[i] = NULL;
			free(square[i]);
			i++;
		}
	}
	square = NULL;
	free(square);
}

void	free_dp(int **dp, int row_col_count)
{
	int		i;

	i = 0;
	while (i < row_col_count)
	{
		if (dp[i] != NULL)
		{
			dp[i] = NULL;
			free(dp[i]);
			i++;
		}
	}
	dp[i] = NULL;
	free(dp);
}
