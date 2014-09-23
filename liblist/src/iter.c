#include <stdlib.h>
#include "list.h"

t_node	*BeginList(t_list *list)
{
  if (!list)
    return (NULL);
  return (list->_head);
}

t_node	*EndList(t_list *list)
{
  if (!list)
    return (NULL);
  return (list->_tail->next);
}

t_node	*CurrentList(t_list *list)
{
  if (!list)
    return (NULL);
  return (list->_current);
}

void	IncCurrentList(t_list *list)
{
  if (!list || list->is_empty(list))
    return ;
  if (list->_current)
    {
      list->_current = list->_current->next;
      list->_index += 1;
    }
}

void	DecCurrentList(t_list *list)
{
  if (!list || list->is_empty(list))
    return ;
  if (list->_current)
    {
      list->_current = list->_current->prev;
      list->_index -= 1;
    }
}
