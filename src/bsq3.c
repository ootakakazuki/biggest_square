
#include "ft_bsq.h"


int     ft_atoi(char *g_buf0, int size)
{
    int     i;
    int     num ;

    i = 0;
    num = 0;
    while (i < size)
    {
        if(!('0' <= g_buf0[i] && g_buf0[i] <= '9'))
        {
            write(1, "map wrror\n", 10);
            return (0);
        }
        num = num * 10 + g_buf0[i] - '0';
        i++;
    }
    return (num);
}

char    *get_row(char *g_buf, int i)
{
    char    *row;
    int     j;
    j = 0;
    row = (char *)malloc(sizeof(char) * g_width + 100);
    if (row == NULL)
        return (NULL);
    while (g_buf[i] && g_buf[i] != '\n')
    {
        row[j] = g_buf[i];
        i++;
        j++;
    }
    row[j] = '\0';
    return (row);
}

void    get_g_width(char *g_buf_hoge)
{
    int     i;
    i = 0;
    g_width = 0;
    while (g_buf_hoge[i] != '\n')
    {
        g_width++;
        i++;
    }
}

void    g_val_set(int num, char *g_buf0, int size)
{
    g_row = num;
    g_empty = g_buf0[size++];
    g_obstacle = g_buf0[size++];
    g_full = g_buf0[size];
}

int     process2(int fd, char *g_buf0, int size)
{
    if (fd < 0)
    {
        exit(1);
    }
    size = read(fd, g_buf0, 4);
    if (size < 4)
    {
        write(2, "map error\n", 10);
        exit(1);
    }
    return (size);
}

int     process3(char *g_buf0, int fd, int size)
{
    int     i;
    char    c;

    i = 3;
    while (g_buf0[i] != '\n')
    {
        read(fd, &c, 1);
        g_buf0[++i] = c;
        size++;
    }
    return (size);
}

void    process4(char *g_buf_hoge, int fd)
{
    int     i;
    char    c;

    i = 0;
    while ((read(fd, &c, 1)))
    {
        g_buf_hoge[i] = c;
        i++;
    }
}


void    file_process(char *file_name, char *g_buf_hoge)
{
    char    g_buf0[200];
    int     size;
    int     fd;

    size = 0;
    fd = open(file_name, O_RDONLY);
    size = process2(fd, g_buf0, size);
    size = process3(g_buf0, fd, size);
    process4(g_buf_hoge, fd);
    size -= 4;
    int     num;
    num = ft_atoi(g_buf0, size);
    g_val_set(num, g_buf0, size);
    if(close(fd))
        exit(1);
}

void    place_x(char **square, int ans)
{
    int     i;
    int     j;
    i = g_i - ans + 1;
    while (i <= g_i)
    {
        j = g_j - ans + 1;
        while (j <= g_j)
        {
            square[i][j] = g_full;
            j++;
        }
        i++;
    }
}

void    str_process(t_tmpstr *str, int i, int row_col_count)
{
    str[i - 1].square = malloc_tab(str[i - 1].g_buf, row_col_count);
    str[i - 1].dp = malloc_dp(row_col_count);
    place_x(str[i - 1].square, calc(str[i - 1].dp, str[i - 1].square, row_col_count));
    print_i(str[i - 1].dp, row_col_count);
    print_c(str[i - 1].square);
    free_square(str[i - 1].square, row_col_count);
    free_dp(str[i - 1].dp, row_col_count);
    str[i - 1].g_buf = NULL;
    free(str[i - 1].g_buf);
}

void    bsq_process(int argc, char **file_arr)
{
    int         i;
    int         row_col_count;
    t_tmpstr    *str;

    if (!(str = (t_tmpstr *)malloc(sizeof(t_tmpstr) * argc)))
        return ;
    i = 1;

    while (i < argc)
    {
        str[i - 1].g_buf = (char *)malloc(sizeof(char) * 10000000);
        file_process(file_arr[i], (str[i - 1].g_buf));
        get_g_width(str[i - 1].g_buf);
        row_col_count = g_row;
        if (!check_buf_contents(str[i - 1].g_buf) || !check_row(str[i - 1].g_buf) || \
        !check_dup())
        {
            write(2, "maperror\n", 9);
            i++;
            continue ;
        }
        str_process(str, i, row_col_count);
        i++;
    }
}

int     main(int argc, char **argv)
{
    t_tmpstr    *str;
    int     i;
    int     row_col_count;

    if (argc < 2)
    {
        i = 1;
        if (!(str = (t_tmpstr *)malloc(sizeof(t_tmpstr) * argc)))
            return (0);
        str[i - 1].g_buf = (char *)malloc(sizeof(char) * 10000000);
        read_stdhoge(str[i - 1].g_buf);
        get_g_width(str[i - 1].g_buf);
        row_col_count = g_row;
        if (!check_buf_contents(str[i - 1].g_buf) || !check_row(str[i - 1].g_buf) || \
        !check_dup())
        {
            write(2, "maperror\n", 9);
            return (0);
        }
        str_process(str, i, row_col_count);
        return (0);
    }
    bsq_process(argc, argv);
}
