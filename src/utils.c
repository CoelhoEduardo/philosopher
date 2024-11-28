/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:01:44 by ecoelho-          #+#    #+#             */
/*   Updated: 2024/11/28 20:02:58 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int ft_atoi(const char *nptr) {
  int sign;
  int base;
  int i;

  sign = 1;
  base = 0;
  i = 0;
  while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ') {
    i++;
  }
  if (nptr[i] == '-' || nptr[i] == '+') {
    sign = 1 - 2 * (nptr[i++] == '-');
  }
  while (nptr[i] >= '0' && nptr[i] <= '9') {
    base = base * 10 + (nptr[i] - '0');
    i++;
  }
  return (sign * base);
}
