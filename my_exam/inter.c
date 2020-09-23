#include <unistd.h>

int     main(int argc, char **argv)
{
    int i = 0;
    int j = 0;
    char ascii[255] = {0};

    if (argc == 3)
    {
        while (argv[1][i])
        {
            j = 0;
            while (argv[2][j])
            {
                if (argv[1][i] == argv[2][j])
                {
                    if (ascii[(int)argv[1][i]] == 0)
                    {
                        write(1, &argv[2][j], 1);
                        ascii[(int)argv[1][i]] = 1;
                    }
                }
                j++;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return(0);
}
