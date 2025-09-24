// int	counter_check(char **map)
// {
// 	int		height;
// 	int		width;
// 	int		counter_p;
// 	int		counter_c;
// 	int		counter_e;

// 	counter_p = 0;
// 	counter_c = 0;
// 	counter_e = 0;
// 	height = 0;
// 	while (map[height])
// 	{
// 		width = 0;
// 		while (map[height][width])
// 		{
// 			if (map[height][width] == 'P')
// 				counter_p++;
// 			else if (map[height][width] == 'C')
// 				counter_c++;
// 			else if (map[height][width] == 'E')
// 				counter_e++;
// 			width++;
// 		}
// 		height++;
// 	}
// 	if (!(counter_p == 1 && counter_c >= 1 && counter_e >= 1))
// 		return (perror("Invalid number of P/C/E"), 0);
// 	return (1);
// }

#include <unistd.h>

int main()
{
    char *str = "Phi Anh";
    int i = -1;
    while (str[i++])
        write(1, &str[i],1);
    return 0;
}