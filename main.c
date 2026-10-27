#include "poly.h"


t_list *lst_part()
{
	t_list *lst; 
	int fd;
	
	fd = open("points.txt", O_RDONLY);
	if (fd < 0)
		return (NULL);
	lst = points_to_lst(fd);
	x2y2_to_lst(lst);
	close (fd);
	if (! check_list(lst))
	{
		free_list(lst);
		return(NULL);
	}
	return (lst);
}

t_point *point_part(int ac, char *av[])
{
	t_point *point;

	point = read_args(ac, av);
	if (!point)
		return (0);
	return (point);
}

int main(int ac, char *av[])
{
	t_list *lst; 
	t_point *point;


	if(ac != 3)
		return (0);
	lst = lst_part();
	if (!lst)
		return (0);
	point = point_part(ac, av);
	if (!point)
	{
		free_list (lst);
		return(0);
	}	
	print_list(lst);
	printf ("point P:  	x[%d] y[%d]\n", point -> x, point -> y);
	printf ("- - - - - - - - - - - - - - - - - - - - - - \n");
	polygon(lst, point);
	free_list(lst);
	free(point);
	return (0);
}

