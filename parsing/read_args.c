#include "parsing.h"

t_point *read_args(int ac, char **av)
{
	(void)ac;
	t_point *point;

	point = malloc (sizeof (t_point));
	if(!point)
		return (NULL);
	point -> x = 0;
	point -> y = 0;

	point -> x = ft_atoi(av[1]);
	point -> y = ft_atoi(av[2]);
	return (point);
}
