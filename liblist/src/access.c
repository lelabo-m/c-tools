/*
** access.c for  in /home/lelabo_m/rendu/liblist-c/liblist
**
** Made by Marc Le Labourier
** Login   <lelabo_m@epitech.net>
**
** Started on  Mon Mar 10 15:16:26 2014 Marc Le Labourier
** Last update Mon Mar 10 15:19:03 2014 Marc Le Labourier
*/

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
