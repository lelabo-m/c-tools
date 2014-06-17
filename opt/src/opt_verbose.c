/*
** opt.c for  in /home/lelabo/rendu/PSU_2013_zappy/opt
**
** Made by lelabo_m
** Login   <lelabo@epitech.net>
**
** Started on  Tue May 13 11:00:21 2014 lelabo_m
** Last update Tue Jun 17 10:36:07 2014 Marc Le Labourier
*/

#include <stdio.h>
#include "opt.h"

void	opt_initerror()
{
  g_opterror = 0;
  g_optemsg[0] = OPT_DEFAULT;
  g_optemsg[1] = OPT_INVALID;
  g_optemsg[2] = OPT_MULTIDEF;
  g_optemsg[3] = OPT_LISTERROR;
  g_optemsg[4] = OPT_MALLOCFAILURE;
  g_optemsg[5] = OPT_OPNOTFOUND;
}

void	opt_verbose()
{
  printf("%s\n", g_optemsg[g_opterror]);
}

void	opt_elemdisplay(t_option *elem)
{
  printf("Option [%c] :\n", elem->key);
  while (elem->values->_current != elem->values->end(elem->values))
    {
      printf("- [%s]\n", (char *)(elem->values->_current->contain));
      elem->values->current_next(elem->values);
    }
}

void	opt_display(t_list *opt)
{
  opt->foreach(opt, (void (*)(void *))opt_elemdisplay, 0);
}
