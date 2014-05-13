/*
** algo.c for  in /home/lelabo_m/rendu/liblist-c/liblist
**
** Made by Marc Le Labourier
** Login   <lelabo_m@epitech.net>
**
** Started on  Tue Mar 11 13:45:32 2014 Marc Le Labourier
** Last update Tue Mar 11 17:11:52 2014 Marc Le Labourier
*/

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

void		SortList(t_list *list, int (*func)(void *, void *))
{
  t_list	*tmp;
  t_node	*elem;
  t_node	*ptr;

  if (!list || list->is_empty(list))
    return ;
  tmp = CreateList();
  while (list->is_empty(list) == 0)
    {
      elem = list->pop_front(list);
      ptr = Find2Last(tmp, func, elem->contain);
      if (ptr)
	tmp->insert_elem(tmp, ptr, elem);
      else
	{
	  tmp->push_front(tmp, elem->contain);
	  free(elem);
	}
    }
  list->_head = tmp->_head;
  list->_current = tmp->_head;
  list->_tail = tmp->_tail;
  list->_size = tmp->_size;
  free(tmp);
}
