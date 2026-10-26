#include "parsing.h"

void print_args(int ac, char **av)
{
	(void)ac;

	while (*av && *av != NULL)
	{	
		while(**av && **av != '\0')
		{	
			while(**av != '\0' && !ft_isdigit(**av))
				++*av;
			if(**av != '\0' && ft_isdigit(**av))
				++*av;
		}
		++av;
	}
}

int copy_to_x(char *av, t_point *point)
{
	int len = 0;
	char x[5];

	while(*av != '\0' && ft_isdigit(*av))
	{
		if (len > 3)
		{
			printf ("moc dlouhe c\n");
			return (0);
		}
		x[len] = *av;
		++av;
		++len;
	}
	x[len] = '\0';
	point -> x = ft_atoi(x);
	return (len);
}

int copy_to_y(char *av, t_point *point)
{
	int len = 0;
	char y[5];

	while(*av != '\0' && ft_isdigit(*av))
	{
		if (len > 3)
		{
			printf ("moc dlouhe c\n");
			return (0);
		}
		y[len] = *av;
		++av;
		++len;
	}
	y[len] = '\0';
	point -> y = ft_atoi(y);
	return (len);
}



int read_av(char *av, t_point *point, int *i)
{
	int len = 0;

	while(*av && *av != '\0')
	{
		len = 0;
		if(!ft_isdigit(*av))
			++av;
		else if(ft_isdigit(*av))
		{
			if (*i == 0)
			{
				len = copy_to_x(av, point);
				if (!len)
					return (-1);
				av = av + len;
				++*i;	
			}
			else if (*i == 1)
			{
				len = copy_to_y(av, point);
				if (!len)
					return (-1);
				av = av + len;
				++*i;	
			}
			else if (*i >= 2)
			{
				++*i;
				return (0);
			}	
		}
	}
	return (0);
}

void print_av(char *av)
{
	printf ("print_av\n");
	int len = 1;

	while (*av != '\0')
	{
		printf ("[%c]", *av);
		av = av +len;
	}
	printf ("\n");	
}

t_point *read_args(int ac, char **av)
{
	(void)ac;
	int i;
	t_point *point;
	int read = 0;

	i = 0;
	point = malloc (sizeof (t_point));
	if(!point)
		return (NULL);
	point -> x = 0;
	point -> y = 0;
	++av;
	int m = 0;

	while (*av && *av != NULL)
	{
		read = read_av(*av, point, &i);
		if (read == -1)
			return (NULL);
		if (i > 2)
			break; 
		++av;
		++m;
	}
	if (i < 2)
	{
		printf ("prilis malo arg\n");
		free(point);
		return(NULL);
	}
	else if (i > 2)
	{
		printf ("moc arg\n");
		free(point);
		return(NULL);
	}
	return (point);
}
