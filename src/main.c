/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:26:59 by ecoelho-          #+#    #+#             */
/*   Updated: 2024/12/06 20:16:36 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int main(int argc, char **argv) {
  t_program program;
  t_philo *philo;
  pthread_mutex_t *forks;

  if (argc != 6 && argc != 5) {
    printf("The number of args is not valid");
    exit(1);
  }
  philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
  forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
  check_args(argc, argv);
  init_program(&program, philo);
  init_forks(forks, ft_atoi(argv[1]));
  init_philos(philo, &program, forks, argv);

  free(philo);
  free(forks);
  return (0);
}
