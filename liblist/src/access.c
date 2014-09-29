#include <stdlib.h>
#include "list.h"

void	*GetFront(t_list *list)
{
  if (!list || list->is_empty(list))
    return (NULL);
  if (list->_head)
    return (list->_head->contain);
  return (NULL);
}

void	*GetBack(t_list *list)
{
  if (!list || list->is_empty(list))
    return (NULL);
  if (list->_tail)
    return (list->_tail->contain);
  return (NULL);
}

void	*GetCurrent(t_list *list)
{
  if (!list || list->is_empty(list))
    return (NULL);
  if (list->_current)
    return (list->_current->contain);
  return (NULL);
}

void  *GetAt(t_list *list, int at)
{
  t_node  *iter;
  int     i;

  if (!list || list->is_empty(list))
    return (NULL);

  iter = list->begin(list);
  i = 0;
  while (iter && i < at)
  {
    iter = iter->next;
    ++i;
  }
  return ((iter) ? (iter->contain) : (NULL));
}