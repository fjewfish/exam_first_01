#include <unistd.h>

int		ft_check(char ch, char *line, int index)
{
	index--;
	while (index >= 0)
	{
		if (line[index] == ch)
			return(0);
		index--;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int	j, i;

	if (argc == 3)
	{
		j = 0;
		i = 0;
		while (argv[1][j])
		{
			i = 0;
			while (argv[2][i])
			{
				if ((argv[2][i] == argv[1][j]) && (ft_check(argv[1][j], argv[1], j) == 1))
				{
					write(1, &argv[1][j], 1);
					break;
				}
				i++;
			}
			j++;
		}
	}
	write(1, "\n", 1);
	return (0);
}


//int
//	main(int argc, char **argv)
//{
//	int	used[255];
//	int	i, j;

//	if (argc == 3)
//	{
//		i = 0;
//		while (i < 255)
//			used[i++] = 0;
//		i = 2;
//		while (i > 0)
//		{
//			j = 0;
//			while (argv[i][j])
//			{
//				if (i == 2 && !used[(unsigned char)argv[i][j]])
//					used[(unsigned char)argv[i][j]] = 1;
//				else if (i == 1 && used[(unsigned char)argv[i][j]] == 1)
//				{
//					write(1, &argv[i][j], 1);
//					used[(unsigned char)argv[i][j]] = 2;
//				}
//				j++;
//			}
//			i--;
//		}
//	}
//	write(1, "\n", 1);
//	return (0);
//}
