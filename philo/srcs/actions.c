/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:56:11 by jwilliam          #+#    #+#             */
/*   Updated: 2022/06/08 12:42:02 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
Philosopher taking forks action, will attempt to mutex lock two forks to 
enable them to start eating.
*/
static void	get_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	print_action(philo->main, philo, 1);
	pthread_mutex_lock(&philo->next_to->fork);
	print_action(philo->main, philo, 1);
}

/*
Philosopher eating action. If the philosopher is able to obtain two forks, 
they will eat the food, the amount of time spent eating as determined by 
the time_to_eat input set. After eating, they will increment the amount of 
times eaten and mutex unlock their forks so that other philosophers will be 
able to use them.
*/
static void	do_eat(t_philo *philo)
{
	philo->last_time_eaten = get_time();
	print_action(philo->main, philo, 2);
	usleep(philo->main->time_to_eat * 1000);
	philo->times_eaten++;
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next_to->fork);
}

/*
Philosopher sleeping action, prints the messages and passes the time as 
designated by the time_to_sleep input.
*/
static void	do_sleep(t_philo *philo)
{
	print_action(philo->main, philo, 3);
	usleep(philo->main->time_to_sleep * 1000);
}

/*
Philosopher thinking action, merely prints the message as it awaits for 
available forks.
*/
static void	do_think(t_philo *philo)
{
	print_action(philo->main, philo, 4);
}

/*
The main function entered when a new thread is created, this will regulate 
the actions the philosophers must take repeatedly until either one of them 
dies of starvation or all of them have eaten the required amount of meals.
The start is offset by the number of philosophers % 2 to prevent clashing 
of threads.
*/
void	*do_actions(void *philo)
{
	t_philo		*philosopher;
	t_main		*main_data;

	philosopher = (t_philo *)philo;
	main_data = philosopher->main;
	if (philosopher->number % 2 == 0)
		usleep(1000);
	while (main_data->death != 1 && main_data->all_eaten != 1
		&& philosopher->times_eaten != main_data->times_must_eat)
	{
		get_forks(philosopher);
		do_eat(philosopher);
		do_sleep(philosopher);
		do_think(philosopher);
	}
	if (philosopher->times_eaten >= main_data->times_must_eat)
	{
		main_data->all_eaten = 1;
	}
	return (NULL);
}
