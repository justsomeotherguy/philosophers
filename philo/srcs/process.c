/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:01:11 by jwilliam          #+#    #+#             */
/*   Updated: 2022/06/08 12:43:54 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
Destroy all current mutex assignments to prevent usage of mutex items. 
Free the structs and then exit the program.
*/
void	end_process(t_main *main)
{
	int			index;

	index = 0;
	while (index < main->num_of_philo)
	{
		pthread_mutex_destroy(&main->philosophers[index].fork);
		index++;
	}
	pthread_mutex_destroy(&main->status);
	free(main->philosophers);
	exit(0);
}

/*
Checks the status of all of the philosophers currently running, if any of 
them die from starvation it is necessary to immediately stop the process. 
Otherwise if all of them are able to eat the amount of times designated from 
program arguments, then also stop.
*/
void	life_check(t_main *main)
{
	int			index;

	while (main->death != 1)
	{
		index = 0;
		while (index < main->num_of_philo)
		{
			if (get_time() - main->philosophers[index].last_time_eaten
				>= main->time_to_die)
			{
				main->death = 1;
				print_action(main, main->philosophers, 98);
				end_process(main);
			}
			else if (main->all_eaten == 1)
			{
				print_action(main, main->philosophers, 99);
				end_process(main);
			}	
			index++;
		}
	}
}

/*
Creates the philosopher processes and directs them to the main action cycle 
for them to be able to perform their action cycle.
*/
int	create_philos(t_main *main)
{
	int			index;

	index = 0;
	while (index < main->num_of_philo)
	{
		pthread_create(&main->philosophers[index].thread, NULL,
			&do_actions, &main->philosophers[index]);
		main->philosophers[index].last_time_eaten = main->start_time;
		index++;
	}
	return (1);
}
