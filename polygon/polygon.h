
#ifndef POLYGON_H
# define POLYGON_H

#include "../poly.h"

typedef struct s_list	t_list;
typedef struct s_point	t_point;

typedef struct s_line
{
	int		top;
	int 	bot;
	int		is_on_line;
}	t_line;


/* * * * * * * polygon.c * * * * * * */

void set_x(t_list *lst);
void  print_x(t_list *lst);
void set_y(t_list *lst);
void  print_y(t_list *lst);
t_line *set_line();
void count_position(t_line *line);
int polygon(t_list *polygon, t_point *point);

/* * * * * * * lines.c * * * * * * */

int count_y(t_list *lst, t_point *point, t_line *line);
int count_y_for_my_x(t_list *lst, t_point *point);
int is_x_in_line(t_list *lst, t_point *point, t_line *line);

/* * * * * * * * * * * * * * * * * */

#endif