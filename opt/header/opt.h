/*
** opt.h for  in /home/lelabo/rendu/PSU_2013_zappy/opt
**
** Made by lelabo_m
** Login   <lelabo@epitech.net>
**
** Started on  Tue May 13 10:55:27 2014 lelabo_m
** Last update Tue May 13 15:49:19 2014 lelabo_m
*/

#ifndef OPT_H_
# define OPT_H_

/* Dependencies */
#include "list.h"

typedef struct s_option	t_option;

struct s_option
{
  char		key;
  t_list	*values;
};

int		g_opterror;
char		*g_optemsg[6];

/* User Function Prototye */
t_list	*opt_parse(int ac, char **av, char *opt);
void	opt_verbose();
void	opt_display();
void	opt_delete();

/* Other Prototype needed to compile */
void	free_optlist(t_option *);
void	opt_initerror();

/* Error */
#define OPT_DEFAULT "Parsing done"
#define OPT_INVALID "Error : invalid option detected"
#define OPT_MULTIDEF "Error : Multiple definition of an option"
#define OPT_LISTERROR "Error : Something went wrong with the list module"
#define OPT_MALLOCFAILURE "Error : Can not allocate memory"
#define OPT_OPNOTFOUND "Error : Not all option set"

#endif /* !OPT_H_ */

