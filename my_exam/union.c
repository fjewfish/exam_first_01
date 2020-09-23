#include <unistd.h>

int     main(int argc, char **argv)
{
    int i = 1;
    int j = 0;
    char ascii[255] = {0};
    if (argc == 3)
    {
        while (i <= 2)
        {
            j = 0;
            while(argv[i][j])
            {
                if (ascii[(int)argv[i][j]] == 0)
                {
                    write(1, &argv[i][j], 1);
                    ascii[(int)argv[i][j]] = 1;
                }
                j++;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
