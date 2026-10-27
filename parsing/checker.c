#include "parsing.h"

int check_list(t_list *lst)
{
	int x_start;
	int y_start;
	int count;
	
	x_start = lst -> x1;
	y_start = lst -> y1;
	count = 0;

	while (lst && lst -> next != NULL)
	{
		if ((lst -> x2 != lst -> next -> x1) || (lst -> y2 != lst -> next -> y1))
		{
			printf ("Error - nespojity polygon !\n");
			return (0);
		}
		++count;
		lst = lst -> next;
	}
	if (lst && lst -> next == NULL)
	{
		if ((lst -> x2 != x_start) || (lst -> y2 != y_start))
		{
			printf ("Error - nespojity polygon !!\n");
			return (0);
		}
		++count;
	}
	return (count);
}

int check_comment(char *line)
{
	while ((*line == ' ') || (*line >= 9 && *line <= 13))
		++line;
	if((*line == '/') && *(line + 1) == '/')
		return (1);
	else
		return (0);
}

int check_line(char *line)
{
	int i = 0;
	int c = 0;

	if (check_comment(line))
		return (2);
	while (*line)
	{
		if(!ft_isdigit(*line))
			c = 0;
		else if (ft_isdigit(*line))
		{
			if (c == 0)
				++i;
			c = 1;
		}
		++line;
	}
	if (i == 2)
		return (1);
	else if (i == 0)
		return (2);
	else 
		return (0);
}

int check_txt(int fd)
{
	char *line;

	while ((line = get_next_line(fd)) != NULL)
	{
		check_line(line);
		if (!check_line(line))
			return (-1);
		else if (check_line(line) == 2)
			return(2);
		free(line);
	}
	close (fd);
	return(0);
}
