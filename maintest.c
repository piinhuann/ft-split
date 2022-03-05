#include <stdio.h>
char **ft_split(char *str);

int main(void)
{
    int i = 0;
    char **dest;
    dest = ft_split("1 2 3 4 5 6   7 88888   9    ");
    while (i < 11)
    {
        printf("%s\n", dest[i]);
        i++;
    }
}
