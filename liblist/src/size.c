/*
** size.c for  in /home/lelabo_m/rendu/liblist-c/liblist
**
** Made by Marc Le Labourier
** Login   <lelabo_m@epitech.net>
**
** Started on  Mon Mar 10 14:05:37 2014 Marc Le Labourier
** Last update Mon Mar 10 15:04:18 2014 Marc Le Labourier
*/

#include "list.h"

unsigned int	SizeList(t_list *list)
{
  if (list)
    return list->_size;
  return (0);
}

unsigned int	IsEmptyList(t_list *list)
{
  if (!list)
    return (1);
  if (list->_size)
    return (0);
  return (1);
}

unsigned int	IndexList(t_list *list)
{
  if (list)
    return list->_index;
  return (0);
}
