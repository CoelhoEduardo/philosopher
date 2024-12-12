/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:45:54 by ecoelho-          #+#    #+#             */
/*   Updated: 2024/12/11 19:41:29 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int thread(t_program *program)
{
    int i;
    
    i = 0;
    while (i < program->philos[0].num_of_philos){
        if (pthread_create(&program->philos[i].thread, NULL, routines, &program->philos[i]) != 0)
        {
            perror("Failed to create a thread");
        }
        i++;
    }
     i = 0;
     while (i < program->philos[0].num_of_philos)
     {
        if (pthread_join(program->philos[i].thread, NULL) != 0) {
            perror("Failed to join a thread");
        }
        i++;
     }

     return (0);
}
