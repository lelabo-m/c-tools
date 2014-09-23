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
