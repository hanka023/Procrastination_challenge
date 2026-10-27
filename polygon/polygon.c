#include "polygon.h"

 
void set_x(t_list *lst)
{
	while (lst != NULL)
	{
		if (lst -> x1 < lst -> x2)
		{
			lst -> x_min = lst -> x1;
			lst -> x_max = lst-> x2;
		}
		else if (lst -> x1 > lst -> x2)
		{
			lst -> x_min = lst -> x2;
			lst -> x_max = lst-> x1;
		}
		else if (lst -> x1 == lst -> x2)
			lst -> x_min = lst -> x_max = lst -> x1;
		lst = lst -> next;
	}
}

void  print_x(t_list *lst)
{
	while (lst != NULL)
	{
		printf ("lst -> x_min[%d]	lst -> x_max[%d]\n", lst -> x_min, lst -> x_max);
		lst = lst -> next;
	}
}

void set_y(t_list *lst)
{
	while (lst != NULL)
	{
		// printf ("lst y2[%d], lst y1 [%d], lst x2 [%d], lst x1[%d]\n", lst -> y2, lst ->y1, lst -> x2, lst -> x1);
		// printf (" x2 - x1 [%d]\n", lst ->x2 - lst ->x1);
		if ((lst -> x2 - lst -> x1) == 0)
			lst -> y_x = 0;
		else
			lst -> y_x = (float)(lst -> y2 - lst -> y1) / (lst -> x2 - lst -> x1);
		lst -> y_0 = (lst -> y1) - (lst -> x1 * lst -> y_x);
		lst = lst -> next;
	}
}

void  print_y(t_list *lst)
{
	while (lst != NULL)
	{
		printf ("lst -> y_x (sklon)[%.2f]	lst -> y_0[%.2f]\n", lst -> y_x, lst -> y_0);
		lst = lst -> next;
	}
}


int count_y_for_my_x(t_list *lst, t_point *point)
{
	int x;
	int y;
	int y_p; // y na primce
	
	x = point -> x;
	y = point -> y;
	y_p = (lst -> y_x * x) + (lst -> y_0);
	if (y_p > y)
		return (1);
	else if (y_p == y)
		return (0);
	else if (y_p < y)
		return (-1); 
	return (0);
}


t_line *set_line()
{
	t_line *line;

	line = malloc (sizeof (t_line));
	if (!line)
		return (NULL);
	line -> top = 0;
	line -> bot = 0;
	line -> is_on_line = 0;

	return (line);
}

void count_position(t_line *line)
{
	int top;
	int bot;
	int lines;

	top = line -> top;
	bot = line -> bot;

	if (bot <= top)
		lines = bot;
	else 
		lines = top;
	if (lines %2 == 0)
		printf ("bod je mimo polygon\n");
	else 
		printf ("bod je uvnitr polygonu\n");
	
}


int polygon(t_list *lst, t_point *point)
{
	(void)polygon;
	(void)point;
	t_line *line;
	line = set_line ();
	set_x(lst);
	set_y(lst);
	is_x_in_line(lst, point, line);
	//printf ("is x in line ok\n");
	printf ("top_lines[%d] bot_lines[%d] is_on_line[%d]\n", line->top, line->bot, line->is_on_line);
	if (line -> is_on_line == 1)
	{
		printf ("bod je na line\n");
		free (line);
		return (0);
	}
	count_position(line);
	free (line);
	return (0);
}