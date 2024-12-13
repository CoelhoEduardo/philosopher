/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:54:09 by ecoelho-          #+#    #+#             */
/*   Updated: 2024/12/13 15:55:29 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void get_args(t_philo *philos, char **arg, t_program *program) {
  philos->num_of_philos = ft_atoi(arg[1]);
  philos->time_to_die = ft_atoi(arg[2]);
  philos->time_to_eat = ft_atoi(arg[3]);
  philos->time_to_sleep = ft_atoi(arg[4]);
  philos->num_times_to_eat = -1;
  philos->write_lock = &program->write_lock;
  philos->meal_lock = &program->meal_lock;
  philos->dead_lock = &program->dead_lock;
  philos->dead = &program->dead_flag;
  if (arg[5])
    philos->num_times_to_eat = ft_atoi(arg[5]);
}

static void init_mutex(t_program *program) {
  pthread_mutex_init(&program->write_lock, NULL);
  pthread_mutex_init(&program->meal_lock, NULL);
  pthread_mutex_init(&program->dead_lock, NULL);
}

void entry_philos(t_philo *philos, t_program *program, pthread_mutex_t *forks,
                  char **argv) {
  int i;
  program->dead_flag = 0;
  program->philos = philos;

  i = 0;
  while (i < ft_atoi(argv[1])) {
    philos[i].id = i + 1;
    philos[i].eating = 0;
    philos[i].meals_eaten = 0;
    get_args(&philos[i], argv, program);
    init_mutex(program);
    philos[i].start_time = get_current_time();
    philos[i].last_meal = get_current_time();

    philos[i].left_fork = &forks[i];
    if (i == 0)
      philos[i].right_fork = &forks[philos[i].num_of_philos - 1];
    else
      philos[i].right_fork = &forks[i - 1];
    i++;
  }
}

void get_forks(pthread_mutex_t *forks, int philo_num) {
  int i;

  i = 0;
  while (i < philo_num) {
    pthread_mutex_init(&forks[i], NULL);
    i++;
  }
}
