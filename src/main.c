/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:26:59 by ecoelho-          #+#    #+#             */
/*   Updated: 2024/12/13 15:17:42 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void table(char **argv) {

  t_program program;
  t_philo *philos;
  pthread_mutex_t *forks;

  philos = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
  forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
  get_forks(forks, ft_atoi(argv[1]));
  entry_philos(philos, &program, forks, argv);
  thread(&program);
  free_and_destroy(program, philos, forks);
}

int main(int argc, char **argv) {

  if (argc != 6 && argc != 5) {
    printf("The number of args is not valid\n");
    exit(1);
  }

  check_args(argc, argv);
  table(argv);

  return (0);
}
