/*
** timecounter.c for  in /home/lelabo_m/GITHUB/c-tools/timecounter
**
** Made by Marc Le Labourier
** Login   <lelabo_m@epitech.net>
**
** Started on  Thu Jun 19 11:40:34 2014 Marc Le Labourier
** Last update Thu Jun 19 11:48:16 2014 Marc Le Labourier
*/

#include "timecounter.h"

void	time_reset(t_timecounter *timer)
{
  timer->elapsed_utime = 0;
  timer->elapsed_mtime = 0;
  timer->elapsed_seconds = 0;
  timer->elapsed_useconds = 0;
  gettimeofday(&timer->tempo, NULL);
}

void	time_update(t_timecounter *timer)
{
  struct timeval	newtempo;

  gettimeofday(&newtempo, NULL);
  timer->elapsed_seconds = newtempo.tv_sec - timer->tempo.tv_sec;
  timer->elapsed_useconds = newtempo.tv_usec - timer->tempo.tv_usec;
  timer->elapsed_utime = (timer->elapsed_seconds)
    * 1000000 + timer->elapsed_useconds;
  timer->elapsed_mtime = ((timer->elapsed_seconds)
			  * 1000 + timer->elapsed_useconds/1000.0) + 0.5;
  timer->tempo.tv_sec = newtempo.tv_sec;
  timer->tempo.tv_usec = newtempo.tv_usec;
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
  gettimeofday(&timer->tempo, NULL);
}
