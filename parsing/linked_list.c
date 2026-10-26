#include "parsing.h"


t_list	*new_list(char *line)
{
	t_list	*lst;

	lst = malloc (sizeof (t_list));
	if (!lst)
		return (NULL);
	line_to_numbers(line, lst);
	
	lst -> next = NULL;
	return (lst);
}

void	add_back(t_list **head, t_list *lst)
{
	t_list	*tmp;

	if (!head || !lst)
		return ;
	if (*head == NULL)
	{
		*head = lst;
		return ;
	}
	tmp = *head;
	while (tmp -> next != NULL)
		tmp = tmp -> next;
	tmp -> next = lst;
}


void	print_list(t_list *lst)
{
	int i = 0;
	printf ("polygon:\n");
	while (lst != NULL)
	{
		
		printf ("[%d]	", i);
		printf("	x1[%d] y1[%d]	x2[%d] y2[%d] \n", lst -> x1,   lst -> y1,  lst -> x2,  lst -> y2);	
		lst = lst -> next;
		++i;
	}
	printf ("\n");
	return ;
}

void	free_list(t_list *lst)
{
	t_list	*free_list;

	while (lst != NULL)
	{
		free_list = (lst)-> next;
	
		free (lst);
		lst = free_list;
	}
	return ;
}

int set_lst_prev(t_list *lst)
{
	lst -> prev = NULL;
	lst = lst -> next;
	while (lst != NULL && lst -> next != NULL)
	{
		(lst -> next -> prev) = lst;
		lst = lst -> next;
	}
	return (0);
}