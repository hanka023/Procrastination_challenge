#ifndef PARSING_H
# define PARSING_H


#include "../poly.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 25
#endif

typedef struct s_list
{
	int		x1;
	int 	x2;
	int		y1;
	int		y2;
	int 	x_min;
	int		x_max;
	float 	y_x;
	float 	y_0;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef struct s_point
{
	int		x;
	int 	y;
}	t_point;

/* * * * * * checker.c * * * * * */

int 	check_list(t_list *lst);
int 	check_line(char *line);
int 	check_txt(int fd);

/* * * * * * get_next_line.c * * * * * */

char	*get_next_line (int fd);

/* * * * * * line_to_lst.c * * * * * */

t_list	*points_to_lst(int fd);
int		line_to_numbers(char *line, t_list *lst);
char 	**number_split(char *line);
void	free_numbers(char **str);
void	x2y2_to_lst(t_list *lst);

/* * * * * * linked_list.c * * * * * */

t_list	*new_list(char *str);
void	add_back(t_list **head, t_list *new);
void	print_list(t_list *begin_list);
void	free_list(t_list *lst);

/* * * * * * * read_args.c * * * * * * */

int			copy_to_x(char *av, t_point *point);
int			copy_to_y(char *av, t_point *point);
int			read_av(char *av, t_point *point, int *i);
t_point		*read_args (int ac, char *argv[]);
void		print_args(int ac, char **av);

/* * * * * * * utils.c * * * * * * */

int		ft_atoi(char *str);
char	*ft_strdup(const char *str);
int		ft_isdigit(int i);
int		ft_isalnum(int i);

/* * * * * * * * * * * * * * * * * */

#endif