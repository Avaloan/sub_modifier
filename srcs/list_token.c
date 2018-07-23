#include "../includes/parser.h"

list *create_node(const char *src)
{
	list *new;
	char *token;
	char *token2;
	
	if(!(new = malloc(sizeof(list))))
		return (NULL);
	new->whole = strdup(src);
	token = strtok(new->whole, " ");
	strtok(NULL, " ");
	token2 = strtok(NULL, " ");
	new->timestamp_start = strdup(token);
	new->timestamp_end = strdup(token2);
	new->next = NULL;
	return (new);
}

void save_token(const char *src, list **lst)
{
	list *tmp = *lst;
	if (src[0] != '0')
		return ;
	if (*lst == NULL)
	{
		*lst = create_node(src);
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = create_node(src);
}


void print(list *elem, double empty)
{
	nb_lines++;
	(void)empty;
	fprintf(fp, "%.2d:%.2d:%06.3f --> ", elem->stamp[0].heures, elem->stamp[0].minutes, elem->stamp[0].secondes);
	fprintf(fp, "%.2d:%.2d:%06.3f\n", elem->stamp[1].heures, elem->stamp[1].minutes, elem->stamp[1].secondes);

}

void iterate_list(list *lst, void (*funcptr)(list *, double), double user_input)
{
	while (lst)
	{
		funcptr(lst, user_input);
		lst = lst->next;
	}
}