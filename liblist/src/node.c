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

/* Warning : swap only the contain */
void	SwapNode(t_node *elem1, t_node *elem2)
{
  void	*save;

  if (!elem1 || !elem2)
    return ;
  save = elem1->contain;
  elem1->contain = elem2->contain;
  elem2->contain = save;
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
