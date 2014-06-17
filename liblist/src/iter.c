/*
** iter.c for  in /home/lelabo_m/rendu/liblist-c/liblist
**
** Made by Marc Le Labourier
** Login   <lelabo_m@epitech.net>
**
** Started on  Mon Mar 10 15:00:42 2014 Marc Le Labourier
** Last update Tue Jun 17 10:31:43 2014 Marc Le Labourier
*/

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
