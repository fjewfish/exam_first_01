#include <unistd.h>

//int		check_behind(char **argv, int i, int j, char symbol)
//{
//	//while (i > 0)
//	//{
//		while (j >= 0)
//		{
//			if (argv[i][j] == symbol)
//				return (0);
//			j--;
//		}
//		i--;
//		j = 0;
//		while (argv[i][j] )
//		{
//			if (argv[i][j] == symbol)
//				return (0);
//			j++;
//		}

//	//}
//	return (1);
//}

//int		main(int argc, char **argv)
//{
//	int i;
//	int j;

//	if (argc == 3)
//	{
//		i = 1;
//		while (i < 3)
//		{
//			j = 0;
//			while (argv[i][j])
//			{
//				if (check_behind(argv, i, j, argv[i][j]) == 1)
//					write (1, &argv[i][j], 1);
//				j++;
//			}
//			i++;
//		}
//	}
//	write (1, "\n", 1);
//	return (0);
//}

int		main(int argc, char **argv)
{
	int i;
	int j;
	int used[255];
	int index;

	if (argc == 3)
	{
		i = 0;
		while (i < 255)
		{
			used[i] = 0;
			i++;
		}
		i = 1;
		while (i < 3)
		{
			j = 0;
			while (argv[i][j])
			{
				index = (int)argv[i][j];
				if (used[index] == 0)
				{
					write (1, &argv[i][j], 1);
					used[index] = 1;
				}
				j++;
			}
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
