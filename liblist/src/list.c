/*
** list.c for  in /home/lelabo_m/rendu/liblist-c/liblist/src
**
** Made by Marc Le Labourier
** Login   <lelabo_m@epitech.net>
**
** Started on  Mon Mar 10 13:35:48 2014 Marc Le Labourier
** Last update Tue Mar 11 16:04:49 2014 Marc Le Labourier
*/

#include <stdlib.h>
#include "list.h"

/* Init function's pointer */
void		InitMethod2(t_list *new)
{
  new->foreach = &ForEachElem;
  new->count = &CountElem;
  new->find = &FindElem;
  new->find2 = &Find2Elem;
  new->remove = &RemoveElem;
  new->extract = &ExtractElem;
  new->extract_at = &ExtractAtElem;
  new->sort = &SortList;
}

/* Init function's pointer */
void		InitMethod1(t_list *new)
{
  new->destroy = &DestroyList;
  new->len = &SizeList;
  new->index = &IndexList;
  new->is_empty = &IsEmptyList;
  new->push_front = &PushFront;
  new->push_back = &PushBack;
  new->pop_front = &PopFront;
  new->pop_back = &PopBack;
  new->begin = &BeginList;
  new->end = &EndList;
  new->current = &CurrentList;
  new->current_next = &IncCurrentList;
  new->current_prev = &DecCurrentList;
  new->front = &GetFront;
  new->back = &GetBack;
  new->get_current = &GetCurrent;
  new->insert_value = &InsertContain;
  new->insert_atvalue = &InsertAtContain;
  new->insert_elem = &InsertElem;
  new->insert_atelem = &InsertAtElem;
}

/* Init list status */
t_list		*CreateList()
{
  t_list	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  new->_size = 0;
  new->_index = 0;
  new->_current = NULL;
  new->_head = NULL;
  new->_tail = NULL;
  InitMethod1(new);
  InitMethod2(new);
  return (new);
}

/* Free list */
void		DestroyList(t_list *list, void (*free_func)(void *))
{
  if (!list)
    return ;
  DestroyNodeList(list->_head, free_func);
  list->_head = NULL;
  free(list);
}
