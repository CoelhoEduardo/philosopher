/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:15:05 by ecoelho-          #+#    #+#             */
/*   Updated: 2024/12/11 19:15:50 by ecoelho-         ###   ########.fr       */
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
    printf("%zu %d %s\n", time, id, str);
  pthread_mutex_unlock(philo->write_lock);
}
