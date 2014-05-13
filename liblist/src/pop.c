/*
** pop.c for  in /home/lelabo_m/rendu/liblist-c/liblist
**
** Made by Marc Le Labourier
** Login   <lelabo_m@epitech.net>
**
** Started on  Mon Mar 10 14:48:19 2014 Marc Le Labourier
** Last update Tue Mar 11 16:56:17 2014 Marc Le Labourier
*/

#include <stdlib.h>
#include "list.h"

t_node	*PopFront(t_list *list)
{
  t_node	*elem;

  if (!list || list->is_empty(list))
   return (NULL);
 list->_size -= 1;
 elem = list->_head;
 list->_head = list->_head->next;
 if (list->_current == elem)
   list->_current = list->_head;
 if (!list->is_empty(list))
   list->_head->prev = NULL;
 else
   {
     list->_tail = NULL;
     list->_current = NULL;
     elem->next = NULL;
     elem->prev = NULL;
   }
 return (elem);
}

t_node	*PopBack(t_list *list)
{
  t_node	*elem;

  if (!list || list->is_empty(list))
   return (NULL);
 list->_size -= 1;
 elem = list->_tail;
 list->_tail = list->_tail->prev;
 if (list->_current == elem)
   list->_current = list->_head;
 if (!list->is_empty(list))
   list->_tail->next = NULL;
 else
   {
     list->_tail = NULL;
     list->_current = NULL;
      elem->next = NULL;
      elem->prev = NULL;
   }
 return (elem);
}
