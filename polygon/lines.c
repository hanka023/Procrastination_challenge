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

int is_x_in_line(t_list *lst, t_point *point, t_line *line)
{
	int x;

	x = point -> x;
	set_lst_prev (lst);
	while (lst != NULL)
	{
		// if (lst -> prev != NULL && lst -> x1 == lst -> prev -> x2)
		// {

		// }
		// 	lst = lst -> next;  ///doladit !!!
		if (lst -> x1 <= lst -> x2)
		{
			if (x >= lst -> x1 && x <= lst -> x2)
			{
				printf ("line x1[%d]  x2[%d]\n",lst -> x1, lst -> x2);
				count_y(lst, point, line);
			}
		}
		else if(lst -> x1 > lst -> x2)
		{
			if (x >= lst -> x2 && x <= lst -> x1)
			{
				printf ("line x1[%d]  x2[%d]\n",lst -> x1, lst -> x2);
				count_y(lst, point, line);	
			}
		}
		lst = lst -> next;
	}
	return (0);
}
