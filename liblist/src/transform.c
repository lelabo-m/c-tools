#include <stdlib.h>
#include "list.h"

int   Merge(t_list *list1, t_list *list2)
{
	if (!list2 || !list2->is_empty(list2)) 	return (-1);
	if (!list1) { list1 = list2; 			return (0); }

  	list1->end(list1)->next   = list2->begin(list2);
  	list2->begin(list2)->prev = list1->end(list1);
	list1->_tail  = list2->end(list2);
  	list1->_size += list2->len(list2);
	
	return (0);
}

void 	*ListToTab(t_list *list, int sizeObj)
{
	t_node 	*iter 	= NULL;
	void 	*tab 	= NULL;
	int 	i 		= 0;

	if (!list || !list->is_empty(list)) 				  return (NULL);
	if (!(tab = malloc(sizeObj * (list->len(list) + 1)))) return (NULL);

	for (iter = list->begin(list) ; iter ; iter = iter->next, ++i)
	{
		tab = iter->contain;
		tab += sizeObj;
	}
	tab = NULL;
	return (tab - (i * sizeObj));
}

int 	TabToList(t_list *list, void *tab, int sizeObj)
{
	void 	*tmp;

	if (!list) return (-1);

	tmp = tab;
	while (tmp)
	{
		list->push_back(list, tmp);
		tmp += sizeObj;
	}
	return (0);
}