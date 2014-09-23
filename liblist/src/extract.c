#include <stdlib.h>
#include "list.h"

t_node	*ExtractElem(t_list *list, t_node *elem)
{
  if (!list || list->is_empty(list))
    return (NULL);
  if (!elem)
    return (NULL);
  list->_size -= 1;
  if (elem == list->_head)
    (elem->next) ? (list->_head = elem->next) : (list->_head = NULL);
  if (elem == list->_tail)
    (elem->prev) ? (list->_tail = elem->prev) : (list->_tail = NULL);
  if (elem == list->_current)
    (elem->next) ? (list->_current = elem->next) : (elem->prev)
      ? (list->_current = elem->prev) : (list->_current = list->_head);
  if (elem->next)
    elem->next->prev = elem->prev;
  if (elem->prev)
    elem->prev->next = elem->next;
  elem->next = NULL;
  elem->prev = NULL;
  return (elem);
}

t_node	*ExtractAtElem(t_list *list, unsigned int index)
{
  t_node	*iter;
  unsigned int	i;

  if (!list || list->is_empty(list))
    return (NULL);
  iter = list->begin(list);
  i = 0;
  while (iter && i < index)
    {
      iter = iter->next;
      ++i;
    }
  if (iter)
    return (ExtractElem(list, iter));
  return (NULL);
}
