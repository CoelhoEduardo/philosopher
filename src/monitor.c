/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:33:46 by ecoelho-          #+#    #+#             */
/*   Updated: 2024/12/13 15:17:05 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool philo_is_dead(t_philo *philo, size_t time_to_die) {
  pthread_mutex_lock(philo->meal_lock);
  if (get_current_time() - philo->last_meal >= time_to_die &&
      philo->eating == 0) {
    return (pthread_mutex_unlock(philo->meal_lock), 1);
  }
  pthread_mutex_unlock(philo->meal_lock);

  return (false);
}

bool is_dead(t_philo *philos) {
  int i;

  i = 0;
  while (i < philos[0].num_of_philos) {
    if (philo_is_dead(&philos[i], philos[i].time_to_die)) {
      get_status("died", &philos[i], philos[i].id);
      pthread_mutex_lock(philos[0].dead_lock);
      *philos->dead = 1;
      pthread_mutex_unlock(philos[0].dead_lock);
      return (true);
    }
    i++;
  }

  return (false);
}

bool all_ate(t_philo *philos) {
  int i;
  int finish_eating;

  i = 0;
  finish_eating = 0;
  if (philos[0].num_times_to_eat == -1)
    return (0);
  while (i < philos[0].num_of_philos) {
    pthread_mutex_lock(philos[i].meal_lock);
    if (philos[i].meals_eaten >= philos[i].num_times_to_eat)
      finish_eating++;
    pthread_mutex_unlock(philos[i].meal_lock);
    i++;
  }
  if (finish_eating == philos[0].num_of_philos) {
    pthread_mutex_lock(philos[0].dead_lock);
    *philos->dead = 1;
    pthread_mutex_unlock(philos[0].dead_lock);
    return (true);
  }
  return (false);
}

void *monitor(void *pointer) {
  t_philo *philos;

  philos = (t_philo *)pointer;
  while (true) {
    if (is_dead(philos) == true || all_ate(philos) == true)
      break;
  }
  return (pointer);
}
