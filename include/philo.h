/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:58:53 by ecoelho-          #+#    #+#             */
/*   Updated: 2024/12/13 15:19:24 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdbool.h>

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
size_t get_current_time(void);
int ft_usleep(size_t milliseconds);

void get_forks(pthread_mutex_t *forks, int philo_num);
void entry_philos(t_philo *philos, t_program *program, pthread_mutex_t *forks,
                 char **argv);

void *routines(void *pointer);
int thread(t_program *program);
void *monitor(void *pointer);

void  free_and_destroy(t_program  program, t_philo *philos, pthread_mutex_t *forks);

int dead_loop(t_philo *philo);
void get_status(char *str, t_philo *philo, int id);

#endif
