#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

static char *ft_str_join(char *line, char c);

int get_next_line(char **line)
{
    char *buffer;
    int flag;

    buffer = (char *)malloc(2);
    if (!buffer || !line || !(*line = (char *)malloc(1)))
        return (-1);
    *line[0] = 0;
    while ((flag = read(0, buffer, 1)) > 0)
    {
        if (buffer[0] == '\n')
            break;
        *line = ft_str_join(*line, buffer[0]);
    }
    free(buffer);
    return (flag);
}
static char *ft_str_join(char *line, char c)
{
    int i = 0;
    char *str;

    while (line[i])
        i++;
    if (!(str = (char *)malloc(i + 2)))
        return (0);
    i = 0;
    while (line[i])
    {
        str[i] = line[i];
        i++;
    }
    str[i] = c;
    str[i + 1] = 0;
    free(line);
    return (str);
}

int		main(void)
{
	int fd;
	char *line;

	fd = open("txt.txt", O_RDONLY);
	while (get_next_line(&line))
		printf("%s\n", line);
	free(line);
	close(fd);
}
