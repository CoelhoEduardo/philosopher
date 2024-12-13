/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:15:05 by ecoelho-          #+#    #+#             */
/*   Updated: 2024/12/13 13:54:23 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int dead_loop(t_philo *philo) {
  pthread_mutex_lock(philo->dead_lock);
  if (*philo->dead == 1)
    return (pthread_mutex_unlock(philo->dead_lock), 1);
  pthread_mutex_unlock(philo->dead_lock);
  return (0);
}

void get_status(char *str, t_philo *philo, int id) {
  size_t time;

  pthread_mutex_lock(philo->write_lock);
  time = get_current_time() - philo->start_time;
  if (!dead_loop(philo))
    printf("%zu %d %s \n", time, id, str);
  pthread_mutex_unlock(philo->write_lock);
}

void  free_and_destroy(t_program  program, t_philo *philos, pthread_mutex_t *forks)
{
  int i;

  i = 0;
  pthread_mutex_destroy(&program.write_lock);
  pthread_mutex_destroy(&program.dead_lock);
  pthread_mutex_destroy(&program.meal_lock);

  while (i < program.philos[0].num_of_philos) {
    pthread_mutex_destroy(&forks[i]);
    i++;
  }

  free(philos);
  free(forks);
}
