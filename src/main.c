/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:26:59 by ecoelho-          #+#    #+#             */
/*   Updated: 2024/11/28 19:46:49 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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

  if (atoi(argv[1]) > 200 || atoi(argv[1]) <= 0) {
    printf("Number of philos: MIN = 1 and MAX = 200\n");
    exit(1);
  }
  if (atoi(argv[2]) <= 0 || atoi(argv[3]) <= 0 || atoi(argv[4]) <= 0) {
    printf("Check you arg, maybe you insert a not valid arg\n");
    exit(1);
  }
  if (argv[5] && atoi(argv[5]) < 0) {
    printf("Check you arg, maybe you insert a not valid arg\n");
    exit(1);
  }

  return (0);
}

int main(int argc, char **argv) {
  if (argc != 6 && argc != 5) {
    printf("The number of args is not valid");
    exit(1);
  }
  check_args(argc, argv);

  return (0);
}