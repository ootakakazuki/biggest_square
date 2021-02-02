
#include "ft_bsq.h"

/**
 * bufの中身を確認し、改行とempty とobstacle以外に
 * 余計なものが入っていたらfalseを返す
*/

int		check_buf_contents(char *g_buf)
{
	int		i;

	i = 0;
	while (g_buf[i])
	{
		if (g_buf[i] != '\n' && g_buf[i] != g_empty && g_buf[i] != g_obstacle)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

// empty obstacle full で重複がないか確認

int		check_dup(void)
{
	return (g_empty != g_obstacle && g_obstacle != g_full && g_full != g_empty);
}

// 与えられた行数と実際の行数が一致しているか、一つ一つ精査していく関数

int		check_row(char *g_buf)
{
	int		i;
	int		tmp_row_count;

	i = 0;
	tmp_row_count = 0;
	while (g_buf[i])
	{
		while (g_buf[i] != '\n')
		{
			i++;
			tmp_row_count++;
		}
		if (tmp_row_count != g_width)
			return (0);
		i++;
		tmp_row_count = 0;
	}
	return (1);
}
