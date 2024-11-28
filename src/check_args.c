/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:57:59 by ecoelho-          #+#    #+#             */
/*   Updated: 2024/11/28 20:04:14 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int ft_is_digit(int c) {
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}

int has_arg_digit(const char *arg) {
  int i;

  i = 0;
  while (arg[i] != '\0') {
    if (!ft_is_digit(arg[i])) {
      printf("The arg is not valid, please check");
      exit(1);
    }
    i++;
  }

  return (0);
}

int check_args(int argc, char **argv) {
  int i;
  i = 1;
  while (i < argc) {
    has_arg_digit(argv[i++]);
  }

  if (ft_atoi(argv[1]) > 200 || ft_atoi(argv[1]) <= 0) {
    printf("Number of philos: MIN = 1 and MAX = 200\n");
    exit(1);
  }
  if (ft_atoi(argv[2]) <= 0 || ft_atoi(argv[3]) <= 0 || ft_atoi(argv[4]) <= 0) {
    printf("Check you arg, maybe you insert a not valid arg\n");
    exit(1);
  }
  if (argv[5] && ft_atoi(argv[5]) < 0) {
    printf("Check you arg, maybe you insert a not valid arg\n");
    exit(1);
  }

  return (0);
}
