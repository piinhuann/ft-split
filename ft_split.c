#include <stdlib.h>

char	*split(char *arr, char *str, int start, int count)
{
	int	i;

	i = 0;
	arr = malloc(sizeof(char *) * count + 1);
	while (i < count)
	{
		arr[i] = str[start];
		i++;
		start++;
	}
	arr[i] = 0;
	return (arr);
}

char	**ft_split(char *str)
{
	char **splitarr;
	int	count;
	int	start;
	int	i;
	int	words;

	i = 0;
	words = 0;
	count = 0;
	while (str[i] != 0)
	{
		if (((str[i + 1] >= 9 && str[i + 1] <= 13) || str[i + 1] == ' ')
			&& !((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		{
			words++;
			count = 0;
		}
		else if (str[i + 1] == 0 && !((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		{
			words++;
			count = 0;
		}
		i++;
	}
	splitarr = malloc(sizeof(char **) * words + 1);
	i = 0;
	words = 0;
	start = 0;
	while (str[i] != 0)
    {
		if (((str[i + 1] >= 9 && str[i + 1] <= 13) || str[i + 1] == ' ')
			&& !((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
        {
			count++;
			splitarr[words] = split(splitarr[words], str, start, count);
			count = 0;
			words++;
        }
		else if (str[i + 1] == 0 && !((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		{
			count++;
			splitarr[words] = split(splitarr[words], str, start, count);
			count = 0;
			words++;
		}
		else if (!((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
			count++;
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			start = i + 1;
		i++;
    }
	splitarr[words] = 0;
	return (splitarr);
}
