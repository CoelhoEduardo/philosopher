/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:26:59 by ecoelho-          #+#    #+#             */
/*   Updated: 2024/12/12 01:21:08 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int main(int argc, char **argv) {

  t_program program;
  t_philo *philos;
  pthread_mutex_t *forks;
  int i;

  i = 0;
  if (argc != 6 && argc != 5) {
    printf("The number of args is not valid\n");
    exit(1);
  }

  philos = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
  forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));

  check_args(argc, argv);
  init_program(&program, philos);
  init_forks(forks, ft_atoi(argv[1]));
  init_philos(philos, &program, forks, argv);
  thread(&program);
  pthread_mutex_destroy(&program.write_lock);
  pthread_mutex_destroy(&program.dead_lock);
  pthread_mutex_destroy(&program.meal_lock);

  while (i < program.philos[0].num_of_philos) {
    pthread_mutex_destroy(&forks[i]);
    i++;
  }

  free(philos);
  free(forks);
  return (0);
}
