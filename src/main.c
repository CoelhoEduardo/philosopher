/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:26:59 by ecoelho-          #+#    #+#             */
/*   Updated: 2024/11/28 20:00:49 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int main(int argc, char **argv) {
  if (argc != 6 && argc != 5) {
    printf("The number of args is not valid");
    exit(1);
  }
  check_args(argc, argv);

  return (0);
}