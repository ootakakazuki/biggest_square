#include <unistd.h>
#include <stdio.h>
#include "ft_bsq.h"


// 引数がない場合の標準出力処理。
// 制作途中。全体でコンパイルしたいときはこのファイルを
// 除いてコンパイルすること。

int		num_check(char *buf, int i)
{
	int		j;

	j = 0;
	while (j < i)
	{
		if (!('0' <= buf[j] && buf[j] <= '9'))
		{
			return (0);
		}
		j++;
	}
	return (1);
}



int		first_row_count(char *buf)
{
	int 	i;
	
	i = 0;
	while (buf[i])
	{
		i++;
	}
	return (i);
}

int		first_row_check(int i)
{
	if (i < 5)
	{
		write(2, "map error\n", 10);
		return (0);
	}
	return (1);
}

void	ft_copy(int num, char *buf_res)
{
	int		i;
	int		j;
	int		k;
	char	buf2[1024];

	i = 0;
	k = 0;
	while (i < num)
	{
		j = 0;
		read(0, buf2, 100);
		while (buf2[j])
		{
			buf_res[k++] = buf2[j++];
		}
		i++;
	}
	k--;
	buf_res[k] = '\0';
}

void	read_stdhoge()//char *buf_res)
{
	char	buf[1024];
	int		size;
	int		i;
	//int		num;  // 行数

	size = 0;
	while (read(0, buf, 10) && buf[0] == '\n')
	{
	}
	i = first_row_count(buf);
	if (first_row_check(i))
		return ;
	i -= 4;
	write(1, "aaaa", 4);
	return ;
/*
	if (!num_check(buf, i))
	{
		write(2, "map error\n", 10);
		return ;
	}
	num = ft_atoi(buf, i);
	ft_copy(num, buf_res);
    g_val_set(num, buf, i);
	i = 0;
	while (buf_res[i])
	{
		printf("buf_res=%c\n", buf_res[i++]);
	}
	*/
}

