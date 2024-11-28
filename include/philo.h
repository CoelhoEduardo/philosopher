/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:58:53 by ecoelho-          #+#    #+#             */
/*   Updated: 2024/11/28 20:32:27 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef PHILO_H
#define PHILO_H

typedef struct s_philo {
  pthread_t thread;
  int id;
  int eating;
  int meals_eaten;
  size_t last_meal;
  size_t time_to_die;
  size_t time_to_eat;
  size_t time_to_sleep;
  size_t start_time;
  int num_of_philos;
  int num_times_to_eat;
  int *dead;
  pthread_mutex_t *right_fork;
  pthread_mutex_t *left_fork;
  pthread_mutex_t *write_lock;
  pthread_mutex_t *dead_lock;
  pthread_mutex_t *meal_lock;
} t_philo;

typedef struct s_program {
  int dead_flag;
  pthread_mutex_t dead_lock;
  pthread_mutex_t meal_lock;
  pthread_mutex_t write_lock;
  t_philo *philos;
} t_program;

int check_args(int argc, char **argv);
int ft_atoi(const char *nptr);

#endif
