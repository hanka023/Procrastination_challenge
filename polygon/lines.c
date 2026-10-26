#include "polygon.h"

int count_y(t_list *lst, t_point *point, t_line *line)
{
	int y = 0;

	y = count_y_for_my_x(lst, point);
	if (y == 1)
		++line -> top;
	else if (y == -1)
		++line -> bot;
	else if (y == 0)
		line -> is_on_line = 1;
	return (0);
}

int is_line(t_list *lst, t_point *point, t_line *line)
{
	int x;

	x = point -> x;
	if (lst -> x1 <= lst -> x2)
	{
		if (x >= lst -> x1 && x < lst -> x2)
		{
			printf ("line x1[%d]  x2[%d]\n",lst -> x1, lst -> x2);
			count_y(lst, point, line);
		}
	}
	else if(lst -> x1 > lst -> x2)
	{
		if (x > lst -> x2 && x <= lst -> x1)
		{
			printf ("line x1[%d]  x2[%d]\n",lst -> x1, lst -> x2);
			count_y(lst, point, line);	
		}
	}
	return(0);
}

int is_edge_point(t_list *lst, t_point *point)
{
	int x;

	x = point -> x;

	if (lst -> x2 == x )
	{
		if ((lst->x1 < x && lst->next -> x2 < x) || (lst->x1 > x && lst->next->x2 > x))
		return (1);
	}
	return (0);
}

int is_edge_line(t_list *lst, t_point *point)
{
	int x;


	x = point -> x;
	if (lst -> x2 == x)
	{
		while (lst -> x2 == lst -> next -> x1)
			lst -> next = lst -> next -> next;
		if ((lst->x1 < x && lst->next -> x2 < x) || (lst->x1 > x && lst->next->x2 > x))
		return (1);
	}
	return (0);
}

int is_point_on_edge(t_list *lst, t_point *point, t_line *line)
{
	int x;
	int y;

	x = point -> x;
	y = point -> y;

	if( (lst -> x1 == x  && lst -> y1 == y) || ((lst -> x2 == x) && (lst -> y2 == y)))
		line -> is_on_line = 1;
	else if ((lst -> x1 == x) && (lst -> x2 == x))
	{
		if ((lst -> y1 < lst -> y2) && (y > lst -> y1 && y > lst -> y2))
			line -> is_on_line = 1;
		else if ((lst -> y2 < lst -> y1) && (y > lst -> y2 && y > lst -> y1))
			line -> is_on_line = 1;
	}
	return (0);
}

int point_on_edge (t_list *lst, t_point *point, t_line *line)
{
	while (lst != NULL)
	{
		is_point_on_edge(lst, point, line);
		lst = lst -> next;
	}
	return (0);
}
int is_x_in_line(t_list *lst, t_point *point, t_line *line)
{
	int x;

	x = point -> x;
	set_lst_prev (lst);
	while (lst != NULL)
	{
		point_on_edge(lst, point, line);
		if (is_edge_point(lst, point))
		{
			lst = lst -> next;
			lst = lst -> next;
		}
		else if (lst -> x2 == x)
		{
			while (lst -> x2 == lst -> next -> x2)
				lst -> next = lst -> next -> next;
			if ((lst->x1 < x && lst->next -> x2 < x) || (lst->x1 > x && lst->next->x2 > x))
			{
				lst = lst -> next;
				lst = lst -> next;
			}
		}
		else 
			is_line(lst, point, line);
		lst = lst -> next;
	}
	return (0);
}
