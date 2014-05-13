/*
** opt.c for  in /home/lelabo/rendu/PSU_2013_zappy/opt
**
** Made by lelabo_m
** Login   <lelabo@epitech.net>
**
** Started on  Tue May 13 11:00:21 2014 lelabo_m
** Last update Tue May 13 15:44:01 2014 lelabo_m
*/

#include <stdlib.h>
#include "opt.h"

void	free_optelem(void *elem)
{
  elem = elem;
}

void	free_optlist(t_option *elem)
{
  if (elem)
    {
      elem->values->destroy(elem->values, (void (*)(void *))&free_optelem);
      free(elem);
    }
}

void	opt_delete(t_list *opt)
{
  opt->destroy(opt, (void (*)(void *))free_optlist);
}
