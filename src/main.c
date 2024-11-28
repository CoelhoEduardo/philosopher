/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:26:59 by ecoelho-          #+#    #+#             */
/*   Updated: 2024/11/28 19:35:04 by ecoelho-         ###   ########.fr       */
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
  while(arg[i] != '\0')
  {
    if (!ft_is_digit(arg[i])) {
      printf("The arg is not valid, please check");
      exit(1);
    }
    i++;
  }

  return (0);
}

int main(int argc, char **argv) {
  if (argc != 6 && argc != 5) {
    printf("The number of args is not valid");
    exit(1);
  }

  int i;
  i = 1;
  while (i < argc) {
    has_arg_digit(argv[i++]);
  }

  return (0);
}