/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:08:55 by ecoelho-          #+#    #+#             */
/*   Updated: 2024/12/13 14:59:49 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void think(t_philo *philo) {
  get_status("is thinking", philo, philo->id);
}

static void nap(t_philo *philo) {
  get_status("is sleeping", philo, philo->id);
  ft_usleep(philo->time_to_sleep);
}

static void eat(t_philo *philo) {
  pthread_mutex_lock(philo->right_fork);
  get_status("has taken a fork", philo, philo->id);
  if (philo->num_of_philos == 1) {
    ft_usleep(philo->time_to_die);
    pthread_mutex_unlock(philo->right_fork);
    return;
  }
  pthread_mutex_lock(philo->left_fork);
  get_status("has taken a fork", philo, philo->id);
  philo->eating = 1;
  get_status("is eating", philo, philo->id);
  pthread_mutex_lock(philo->meal_lock);
  philo->last_meal = get_current_time();
  philo->meals_eaten++;
  pthread_mutex_unlock(philo->meal_lock);
  ft_usleep(philo->time_to_eat);
  philo->eating = 0;
  pthread_mutex_unlock(philo->left_fork);
  pthread_mutex_unlock(philo->right_fork);
}

void *routines(void *pointer) {
  t_philo *philo;

  philo = (t_philo *)pointer;
  if (philo->id % 2 == 0)
    ft_usleep(1);
  while (!dead_loop(philo)) {
    eat(philo);
    nap(philo);
    think(philo);
  }
  return (pointer);
}
