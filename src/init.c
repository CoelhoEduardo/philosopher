/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:54:09 by ecoelho-          #+#    #+#             */
/*   Updated: 2024/12/09 10:55:57 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_input(t_philo *philo, char **arg)
{
	philo->num_of_philos = ft_atoi(arg[1]);
	philo->time_to_die = ft_atoi(arg[2]);
	philo->time_to_eat = ft_atoi(arg[3]);
	philo->time_to_sleep = ft_atoi(arg[4]);
	if (arg[5])
		philo->num_times_to_eat = ft_atoi(arg[5]);
		
	else
		philo->num_times_to_eat = -1;
}

void	init_philos(t_philo *philos, t_program *program, pthread_mutex_t *forks,
		char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philos[i].id = i + 1;
		philos[i].eating = 0;
		philos[i].meals_eaten = 0;
		init_input(&philos[i], argv);
		philos[i].start_time = get_current_time();
		philos[i].last_meal = get_current_time();
		philos[i].write_lock = &program->write_lock;
		philos[i].meal_lock = &program->meal_lock;
		philos[i].dead_lock = &program->dead_lock;
		philos[i].dead = &program->dead_flag;
		philos[i].left_fork = &forks[i];
		if (i == 0)
			philos[i].right_fork = &forks[philos[i].num_of_philos - 1];
		else
			philos[i].right_fork = &forks[i - 1];
		i++;
	}
}

void	init_forks(pthread_mutex_t *forks, int philo_num)
{
	int	i;

	i = 0;
	while (i < philo_num)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	init_program(t_program *program, t_philo *philos)
{
	program->dead_flag = 0;
	program->philos = philos;
	pthread_mutex_init(&program->write_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
	pthread_mutex_init(&program->dead_lock, NULL);
}

void	table(char **argv)
{
	t_program program;
	t_philo	*philos;
	pthread_mutex_t *forks;

	philos = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
	init_program(&program, philos);
	init_forks(forks, ft_atoi(argv[1]));
	init_philos(philos, &program, forks, argv);

	free(philos);
	free(forks);
}
