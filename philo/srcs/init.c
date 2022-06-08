/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:18:30 by jwilliam          #+#    #+#             */
/*   Updated: 2022/06/07 14:25:52 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
Initialize the philosophers struct inside the main data struct. Designates 
mutex fork and the neighbouring philosopher besides them for taking the 
secondary fork. Afterwards, assigns a pointer to the main data struct inside 
the philosopher struct.
*/
int	init_philo(t_main *main)
{
	int					index;

	main->philosophers = (t_philo *)malloc(sizeof(t_philo)
			* main->num_of_philo);
	if (!main->philosophers)
		return (0);
	index = 0;
	while (index < main->num_of_philo)
	{
		main->philosophers[index].number = index + 1;
		main->philosophers[index].times_eaten = 0;
		pthread_mutex_init(&main->philosophers[index].fork, NULL);
		if ((index + 1) == main->num_of_philo)
			main->philosophers[index].next_to = &main->philosophers[0];
		else
			main->philosophers[index].next_to = &main->philosophers[index + 1];
		main->philosophers[index].main = main;
		index++;
	}
	return (1);
}

/*
Initializes the main data struct, parses all of the info set from the 
arguments received from the program and assigns them to the variables in the 
main data struct. 
*/
void	init_main(t_main *main, char **argv)
{
	if (validate_args(argv) != 1)
		err_bad_args();
	memset(main, 0, sizeof(t_main));
	main->num_of_philo = ft_atoi(argv[1]);
	printf("Number of Philosophers - %i\n", main->num_of_philo);
	main->time_to_die = ft_atoi(argv[2]);
	printf("Time to die - %i\n", main->time_to_die);
	main->time_to_eat = ft_atoi(argv[3]);
	printf("Time to eat - %i\n", main->time_to_eat);
	main->time_to_sleep = ft_atoi(argv[4]);
	printf("Time to sleep - %i\n", main->time_to_sleep);
	if (argv[5])
	{
		main->times_must_eat = ft_atoi(argv[5]);
		printf("Times must eat - %i\n", main->times_must_eat);
	}
	else
		main->times_must_eat = MIN;
	write(1, "\n", 1);
	main->all_eaten = 0;
	main->death = 0;
	if (init_philo(main) != 1)
		err_init();
	pthread_mutex_init(&main->status, NULL);
	return ;
}
