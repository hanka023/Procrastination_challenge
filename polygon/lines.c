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
			count_y(lst, point, line);
	}
	else if(lst -> x1 > lst -> x2)
	{
		if (x > lst -> x2 && x <= lst -> x1)
			count_y(lst, point, line);
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
	t_list *tmp;
	

	x = point -> x;
	

	if (lst && lst -> x2 == x  && ((lst->next != NULL) && (lst->next->next != NULL)))
	{
		if((lst->next->x1 == x) && (lst->next->x2 == x))
		{
			tmp = lst -> next ->next;
			lst -> next = tmp;
		}
		if ((lst->x1 < x && lst->next->x2 < x) || (lst->x1 > x && lst->next->x2 > x))
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
		if ((lst -> y1 < lst -> y2) && (y > lst -> y1 && y < lst -> y2))
			line -> is_on_line = 1;
		else if ((lst -> y2 < lst -> y1) && (y > lst -> y2 && y < lst -> y1))
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
	// if((point -> x == lst ->x1) && (point-> y == lst-> y1))
	// {
	// 	firts_point(lst, point, line);
	// 	return(0);
	// }
	
	while (lst != NULL)
	{
		point_on_edge(lst, point, line);
		if (is_edge_point(lst, point))
		{	
			if (lst -> next)
				lst = lst -> next;
			if (lst -> next -> next)
				lst = lst -> next;
		}
		if (is_edge_line(lst, point))
		{
			if (lst -> next)
				lst = lst -> next;
			if (lst -> next -> next)
				lst = lst -> next;
		}
		is_line(lst, point, line);
		lst = lst -> next;
	}
	return (0);
}
