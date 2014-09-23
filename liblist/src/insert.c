#include <stdlib.h>
#include "list.h"

void	*InsertContain(t_node *elem, void *contain)
{
  void	*old;

  if (!elem)
    return (NULL);
  old = elem->contain;
  elem->contain = contain;
  return (old);
}

int	InsertElem(t_list *list, t_node *elem, t_node *new)
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
  return (InsertElem(list, iter, new));
}

void	*InsertAtContain(t_list *list, void *contain, unsigned int at)
{
  t_node	*iter;
  unsigned int	index;

  if (!list || list->is_empty(list))
    return (NULL);
  iter = list->begin(list);
  index = 0;
  while (iter && index < at)
    {
      iter = iter->next;
      ++index;
    }
  if (!iter)
    return (NULL);
  return (InsertContain(iter, contain));
}
