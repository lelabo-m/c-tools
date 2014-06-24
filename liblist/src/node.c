/*
** node.c for  in /home/lelabo_m/rendu/liblist-c/liblist/src
**
** Made by Marc Le Labourier
** Login   <lelabo_m@epitech.net>
**
** Started on  Mon Mar 10 13:51:45 2014 Marc Le Labourier
** Last update Tue Jun 24 13:35:57 2014 Marc Le Labourier
*/

#include <stdlib.h>
#include "list.h"

t_node		*CreateNode(void *elem)
{
  t_node        *new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  new->contain = elem;
  new->prev = NULL;
  new->next = NULL;
  return (new);
}

void	SwapNode(t_node *elem1, t_node *elem2)
{
  t_node	*save;

  if (!elem1 || !elem2)
    return ;
  if (elem1->next)
    elem1->next->prev = elem2;
  if (elem2->next)
    elem2->next->prev = elem1;
  if (elem1->prev)
    elem1->prev->next = elem2;
  if (elem2->prev)
    elem2->prev->next = elem1;
  save = elem1->next;
  elem1->next = elem2->next;
  elem2->next = save;
  save = elem1->prev;
  elem1->prev = elem2->prev;
  elem2->prev = save;
}

void	DestroyNode(t_node *elem, void (*free_elem)(void *))
{
  if (!elem)
    return ;
  if (free_elem)
    (*free_elem)(elem->contain);
  if (elem->next)
    elem->next->prev = elem->prev;
  if (elem->prev)
    elem->prev->next = elem->next;
  elem->next = NULL;
  elem->prev = NULL;
  free(elem);
}

void	DestroyNodeList(t_node *elem, void (*free_elem)(void *))
{
  if (elem)
    {
      if (elem->next)
	DestroyNodeList(elem->next, free_elem);
      DestroyNode(elem, free_elem);
    }
}
