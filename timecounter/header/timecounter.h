/*
** timecounter.h for header in /home/pailli_a/school/Tek2/rendu/PSU_2013_zappy/lib/timecounter/header
**
** Made by Marc Le Labourier
** Login   <lelabo_m@epitech.net>
**
** Started on  Thu Jun 19 11:20:57 2014 Marc Le Labourier
** Last update Thu Jun 26 16:51:59 2014 Marc Le Labourier
*/

#ifndef TIMECOUNTER_H_
# define TIMECOUNTER_H_

#include <time.h>
#include <stdio.h>

typedef struct s_timecounter t_timecounter;

struct s_timecounter
{
  struct timespec	tempo;
  long			elapsed_utime; /* elapsed time in microseconds */
  long			elapsed_mtime; /* elapsed time in milliseconds */
  long			elapsed_seconds; /* diff between seconds counter */
  long			elapsed_useconds; /* diff between microseconds counter */
  void			(*update)(t_timecounter*);
  void			(*reset)(t_timecounter*);
  void			(*dump)(t_timecounter*);
};

/* PROTO */
void	time_init(t_timecounter*);

#endif /* !TIMECOUNTER_H_ */
