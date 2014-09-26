#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int   Merge(t_list *list1, t_list *list2)
{
	if (!list2 || list2->is_empty(list2)) 	return (-1);
	if (!list1) { list1 = list2; 			return (0); }

  	list1->_tail->next   		= list2->begin(list2);
  	list2->begin(list2)->prev 	= list1->_tail;
	list1->_tail  = list2->_tail;
  	list1->_size += list2->len(list2);
	return (0);
}

void 	**ListToTab(t_list *list)
{
	t_node 	*iter 	= NULL;
	void 	**tab 	= NULL;
	int 	i 		= 0;

	if (!list || list->is_empty(list)) 						return (NULL);
	if (!(tab = malloc(sizeof(void *) * (list->len(list) + 1)))) 	return (NULL);

	for (iter = list->begin(list) ; iter ; iter = iter->next, i++)
		tab[i] = iter->contain;
	tab[i] = NULL;
	return (tab);
}

int 	TabToList(t_list *list, void **tab)
{
	int 	i = 0;

	if (!list) return (-1);
	for (i = 0 ; tab && tab[i] ; i++) list->push_back(list, tab[i]);
	return (0);
}