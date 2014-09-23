#include <stdlib.h>
#include "list.h"

int	InsertElemBefore(t_list *list, t_node *elem, t_node *new)
{
  if (!list || list->is_empty(list))
    return (1);
  if (!elem || !new)
    return (1);
  list->_size += 1;
  new->prev = elem->prev;
  if (new->prev)
    new->prev->next = new;
  new->next = elem;
  elem->prev = new;
  if (list->_head == elem)
    list->_head = new;
  return (0);
}

int	InsertElemAfter(t_list *list, t_node *elem, t_node *new)
{
  if (!list || list->is_empty(list))
    return (1);
  if (!elem || !new)
    return (1);
  list->_size += 1;
  new->next = elem->next;
  if (new->next)
    new->next->prev = new;
  new->prev = elem;
  elem->next = new;
  if (list->_tail == elem)
    list->_tail = new;
  return (0);
}

int	InsertElem(t_list *list, t_node *elem, t_node *new, int side)
{
  return ((side == S_NORMAL) ? (InsertElemAfter(list, elem, new))
	  : (InsertElemBefore(list, elem, new)));
}

int	InsertAtElem(t_list *list, t_node *new, unsigned int at)
{
  t_node	*iter;
  unsigned int	index;

  if (!list || list->is_empty(list))
    return (1);
  iter = list->begin(list);
  index = 0;
  while (iter && index < at)
    {
      iter = iter->next;
      ++index;
    }
  if (!iter)
    return (1);
  return (InsertElem(list, iter, new, S_REVERSE));
}
