#include "parsing.h"

t_list	*points_to_lst(int fd)
{
	int		i;
	char	*line;
	t_list *head;
	t_list	*lst;

	lst = NULL;
	line = NULL;
	i = 0;
	head = NULL;

	while ((line = get_next_line(fd)) != NULL)
	{
		if (check_line(line) == -1)
		{
			free(line);
			return(NULL);
		}
		else if (check_line(line) == 2)
		{
			free(line);
			continue;
		}
		lst = new_list(line);
		if (!lst)
		{
			free(line);
			return(NULL);
		}
		add_back(&head, lst);
		++i;
		free(line);
	}
	close (fd);
	return(head);
}


void free_numbers(char **str)
{
	int i = 0;

	while (str[i] != NULL)
	{
		free(str[i]);
		++i;
	}
	free(str);
}

char **number_split(char *line)
{
	int i = 0;
	int j = 0;
	int len = 0;
	char **numbers;

	numbers = malloc (sizeof (char *) * 5);
	if (!numbers)
		return (NULL);
	while (i < 4)
	{
		numbers[i] = malloc(sizeof (char) * 5);
		if ( !numbers[i])
		{
			free_numbers(numbers);
			return(NULL);
		}
		++i;
	}
	numbers[4] = NULL;
	i = 0;

	while (line[len] && line[len] != '\0' && i < 4)
	{
		while (line[len] && !ft_isalnum(line[len]))
			++len;
		if (ft_isalnum(line[len]))
		{
			while(line[len] && ft_isalnum(line[len]) && j < 5)
			{
				numbers[i][j] = line[len];
				++len;
				++j;
			}
			numbers[i][j] = '\0';
			j = 0;
			++i;
		}
		numbers[4] = NULL;
	}
	if (i != 4)
	{
		printf("nespravny pocet arg v tabulce\n");
		return (NULL);
	}
	return (numbers);
}

int line_to_numbers(char *line, t_list *lst)
{
	char **numbers;
	
	numbers = number_split(line);
	if (!numbers)
		return(0);

	lst -> x1 = ft_atoi(numbers[0]);
	lst -> y1 = ft_atoi(numbers[1]);
	lst -> x2 = ft_atoi(numbers[2]);
	lst -> y2 = ft_atoi(numbers[3]);
	free_numbers(numbers);
	return (0);
}