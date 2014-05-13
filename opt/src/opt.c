/*
** opt.c for  in /home/lelabo/rendu/PSU_2013_zappy/opt
**
** Made by lelabo_m
** Login   <lelabo@epitech.net>
**
** Started on  Tue May 13 11:00:21 2014 lelabo_m
** Last update Tue May 13 15:46:12 2014 lelabo_m
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "opt.h"

int	opt_checkdescribe(char *opt)
{
  int	i;
  int	n;

  i = -1;
  while (opt[++i])
    {
      if (!((opt[i] >= 'a' && opt[i] <= 'z')
	    || (opt[i] >= 'A' && opt[i] <= 'Z')
	    || (opt[i] >= '0' && opt[i] <= '9')))
	{
	  g_opterror = 1;
	  return (1);
	}
      n = i;
      while (opt[++n])
	{
	  if (opt[i] == opt[n])
	    {
	      g_opterror = 2;
	      return (1);
	    }
	}
    }
  return (0);
}

int	opt_isopt(char *var, char *optlist)
{
  int	i;

  i = 0;
  if (!var)
    return (0);
  if (var[0] == '-' && strlen(var) == 2)
    {
      while (optlist[i])
	{
	  if (var[1] == optlist[i])
	    return (1);
	  ++i;
	}
    }
  return (0);
}

t_option	*opt_allocelem(char *var)
{
  t_option	*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    {
      g_opterror = 4;
      return (NULL);
    }
  elem->key = var[1];
  if ((elem->values = CreateList()) == NULL)
    {
      g_opterror = 3;
      return (NULL);
    }
  return (elem);
}

t_list	*opt_parsing(t_list *opt, int ac, char **av, char *optlist)
{
  t_option	*elem;
  int		i;

  i = 1;
  elem = NULL;
  while (i < ac)
    {
      if (opt_isopt(av[i], optlist))
	{
	  (elem && elem->values->len(elem->values))
	    ? (opt->push_back(opt, elem)) : (free_optlist(elem));
	  if ((elem = opt_allocelem(av[i])) == NULL)
	    return (NULL);
	}
      else if (elem)
	elem->values->push_back(elem->values, av[i]);
      ++i;
    }
  (elem && elem->values->len(elem->values))
    ? (opt->push_back(opt, elem)) : (free_optlist(elem));
  return (opt);
}

t_list	*opt_parse(int ac, char **av, char *optlist)
{
  t_list	*opt;

  opt_initerror();
  if (opt_checkdescribe(optlist) == 1)
    return (NULL);
  if ((opt = CreateList()) == NULL)
    {
      g_opterror = 3;
      return (NULL);
    }
  opt = opt_parsing(opt, ac, av, optlist);
  if (opt->len(opt) != strlen(optlist))
    {
      g_opterror = 5;
      opt->destroy(opt, (void (*)(void *))free_optlist);
      return (NULL);
    }
  return (opt);
}
