#include "ft_bsq.h"

char	**malloc_tab(char *g_buf, int row_col_count)
{
	char	**square;
	int		i;
	int		j;
	char	*word;
	square = (char **)malloc(sizeof(char *) * row_col_count + 100);
	if (square == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (g_buf[i])
	{
		word = get_row(g_buf, i);
		while (g_buf[i] && g_buf[i] != '\n')
		{
			i++;
		}
		i++;
		square[j] = word;
		j++;
	}
	square[j] = NULL;
	return (square);
}

int		**malloc_dp(int row_col_count)
{
	int		**dp;
	int		*tmp;
	int		k;

	k = 0;
	dp = (int **)malloc(sizeof(int *) * row_col_count);
	if (dp == NULL)
	{
		return (NULL);
	}
	while (k < row_col_count)
	{
		tmp = (int *)malloc(sizeof(int) * g_width);
		dp[k] = tmp;
		k++;
	}
	return (dp);
}
