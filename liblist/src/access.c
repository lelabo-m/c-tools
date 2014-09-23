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
