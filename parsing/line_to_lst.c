#include "parsing.h"


t_list	*points_to_lst(int fd)
{
	//int		i;
	char	*line;
	t_list *head;
	t_list	*lst;

	lst = NULL;
	line = NULL;
	//i = 0;
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
		//++i;
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

	numbers = malloc (sizeof (char *) * 3);
	if (!numbers)
		return (NULL);
	while (i < 2)
	{
		numbers[i] = malloc(sizeof (char) * 4);
		if ( !numbers[i])
		{
			free_numbers(numbers);
			return(NULL);
		}
		++i;
	}
	numbers[2] = NULL;
	i = 0;

	while (line[len] && line[len] != '\0' && i < 2)
	{
		while (line[len] && !ft_isalnum(line[len]))
			++len;
		if (ft_isalnum(line[len]))
		{
			while(line[len] && ft_isalnum(line[len]) && j < 3)
			{
				numbers[i][j] = line[len];
				++len;
				++j;
			}
			numbers[i][j] = '\0';
			j = 0;
			++i;
		}
		numbers[2] = NULL;
	}
	if (i != 2)
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
	free_numbers(numbers);
	return (0);
}

void x2y2_to_lst(t_list *lst)
{
	int x_start;
	int y_start;

	x_start = lst -> x1;
	y_start = lst -> y1;
	
	while (lst != NULL && lst -> next != NULL)
	{
		lst -> x2 = lst -> next -> x1;
		lst -> y2 = lst -> next -> y1;
		lst = lst -> next;
	}
	if (lst -> next == NULL)
	{
		lst -> x2 = x_start;
		lst -> y2 = y_start;
	}
	
}