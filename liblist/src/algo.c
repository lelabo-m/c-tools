#include <stdlib.h>
#include "list.h"

void		ForEachElem(t_list *list, void (*func)(void *), int order)
{
  t_node	*iter;

  if (!list || list->is_empty(list))
    return ;
  if (order == S_NORMAL)
    {
      iter = list->begin(list);
      while (this->_current)
	{
	  (*func)(iter->contain);
	  iter = iter->next;
	}
    }
  else
    {
      iter = list->end(list);
      while (iter)
	{
	  (*func)(iter->contain);
	  iter = iter->prev;
	}
    }
}

int		CountElem(t_list *list, int (*func)(void *, void *), void *cmp)
{
  t_node	*iter;
  int		result;

  result = 0;
  if (!list || list->is_empty(list))
    return (0);
  iter = list->begin(list);
  while (iter)
    {
      result += (*func)(iter->contain, cmp);
      iter = iter->next;
    }
  return (result);
}

t_node		*FindElem(t_list *list, int (*func)(void *, void *),
			   void *cmp)
{
  t_node	*iter;

  if (!list || list->is_empty(list))
    return (NULL);
  iter = list->begin(list);
  while (iter)
    {
      if ((*func)(iter->contain, cmp))
	return (iter);
      iter = iter->next;
    }
  return (NULL);
}

void		RemoveElem(t_list *list, int (*func)(void *),
			   void (*free_func)(void *))
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
      if ((*func)(save->contain))
	DestroyNode(ExtractElem(list, save), free_func);
    }
}
