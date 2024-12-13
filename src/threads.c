/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:45:54 by ecoelho-          #+#    #+#             */
/*   Updated: 2024/12/13 15:21:16 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int thread(t_program *program) {
  pthread_t watcher;
  int i;

  i = 0;
  if (pthread_create(&watcher, NULL, monitor, program->philos) != 0)
    printf("Error to create a thread");
  while (i < program->philos[0].num_of_philos) {
    if (pthread_create(&program->philos[i].thread, NULL, routines,
                       &program->philos[i]) != 0) {
      printf("Error to create a thread");
    }
    i++;
  }

  i = 0;
  if (pthread_join(watcher, NULL) != 0)
    printf("Failed to join a monitor thread");
  while (i < program->philos[0].num_of_philos) {
    if (pthread_join(program->philos[i].thread, NULL) != 0) {
      printf("Failed to join a thread");
    }
    i++;
  }

  return (0);
}
