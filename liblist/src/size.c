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
