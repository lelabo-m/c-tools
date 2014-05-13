/*
** insert.c for  in /home/lelabo_m/rendu/liblist-c/liblist
**
** Made by Marc Le Labourier
** Login   <lelabo_m@epitech.net>
**
** Started on  Mon Mar 10 15:36:01 2014 Marc Le Labourier
** Last update Tue Mar 11 15:31:21 2014 Marc Le Labourier
*/

#include <stdlib.h>
#include "list.h"

t_node	*ExtractElem(t_list *list, t_node *elem)
{
  if (!list || list->is_empty(list))
    return (NULL);
  if (!elem)
    return (NULL);
  list->_size -= 1;
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
