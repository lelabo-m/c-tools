#include <stdlib.h>
#include "list.h"

t_node		*Find2Last(t_list *list, int (*func)(void *, void *), void *cmp)
{
  t_node        *iter;
  t_node        *save;
  int		ret;

  ret = 1;
  if (!list || list->is_empty(list))
    return (NULL);
  iter = list->begin(list);
  save = NULL;
  while (iter)
    {
      ret = (*func)(iter->contain, cmp);
      if (!ret)
        return (save);
      save = iter;
      iter = iter->next;
    }
  if (ret)
    return (save);
  return (NULL);
}

void		SortList(t_list *list, int (*cmp)(const void *, const void *))
{
  void  **tab;

  tab = list->list_to_tab(list);
  qsort(tab, list->len(list), sizeof(void *), cmp);
  list->remove(list, NULL, NULL);
  list->tab_to_list(list, tab);
  free(tab);
}

void		RemoveElemIf(t_list *list, int (*func)(void *, void *),
			    void (*free_func)(void *), void *elem)
{
  t_node	*iter;
  t_node	*save;

  if (!list || list->is_empty(list))
    return ;
  iter = list->begin(list);
  while (iter)
    {
      save = iter;
      iter = iter->next;
      if ((*func)(save->contain, elem))
	DestroyNode(ExtractElem(list, save), free_func);
    }
}

void    SwapContains(t_node *first, t_node *second)
{
  void  *tmp;

  if (!first || !second)
    return ;
  tmp = first->contain;
  first->contain = second->contain;
  second->contain = tmp;
}