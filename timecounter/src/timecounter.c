/*
** timecounter.c for  in /home/lelabo_m/rendu/PSU_2013_zappy/lib
**
** Made by Marc Le Labourier
** Login   <lelabo_m@epitech.net>
**
** Started on  Thu Jun 26 16:48:58 2014 Marc Le Labourier
** Last update Thu Jun 26 16:58:33 2014 Marc Le Labourier
*/

#include "timecounter.h"

void	time_reset(t_timecounter *timer)
{
  timer->elapsed_utime = 0;
  timer->elapsed_mtime = 0;
  timer->elapsed_seconds = 0;
  timer->elapsed_useconds = 0;
  clock_gettime(CLOCK_REALTIME, &timer->tempo);
}

void	time_update(t_timecounter *timer)
{
  struct timespec	newtempo;

  clock_gettime(CLOCK_REALTIME, &newtempo);
  timer->elapsed_seconds = newtempo.tv_sec - timer->tempo.tv_sec;
  timer->elapsed_useconds = (newtempo.tv_nsec - timer->tempo.tv_nsec) / 1000;
  timer->elapsed_utime = (timer->elapsed_seconds)
    * 1000000 + timer->elapsed_useconds;
  timer->elapsed_mtime = ((timer->elapsed_seconds)
			  * 1000 + timer->elapsed_useconds / 1000.0) + 0.5;
  timer->tempo.tv_sec = newtempo.tv_sec;
  timer->tempo.tv_nsec = newtempo.tv_nsec;
}

void	time_dump(t_timecounter* timer)
{
  printf("Elapsed time : %ld seconds + %ld microseconds\n",
	 timer->elapsed_seconds,
	 timer->elapsed_useconds);
  printf(" - %ld milliseconds\n", timer->elapsed_mtime);
  printf(" - %ld microseconds\n", timer->elapsed_utime);
}

void	time_init(t_timecounter *timer)
{
  timer->elapsed_utime = 0;
  timer->elapsed_mtime = 0;
  timer->elapsed_seconds = 0;
  timer->elapsed_useconds = 0;
  timer->update = &time_update;
  timer->reset = &time_reset;
  timer->dump = &time_dump;
  clock_gettime(CLOCK_REALTIME, &timer->tempo);
}
