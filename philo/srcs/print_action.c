/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:40:33 by jwilliam          #+#    #+#             */
/*   Updated: 2022/06/08 12:43:22 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
Main function used to output the status of the philosopher entering the 
function. Uses a mutex lock to prevent other philosopher/events printing 
simultaneously.
*/
void	print_action(t_main *main, t_philo *philo, int action)
{
	int		curr_time;

	curr_time = (get_time() - main->start_time);
	pthread_mutex_lock(&main->status);
	if (main->death != 1 && main->all_eaten != 1)
	{
		if (action == 1)
			printf("%ims Philosopher %i has taken a fork\n",
				curr_time, philo->number);
		if (action == 2)
			printf("%ims Philosopher %i is eating\n",
				curr_time, philo->number);
		if (action == 3)
			printf("%ims Philosopher %i is sleeping\n",
				curr_time, philo->number);
		if (action == 4)
			printf("%ims Philosopher %i is thinking\n",
				curr_time, philo->number);
	}
	if (action == 99)
		printf("%ims All have eaten.\n", curr_time);
	else if (action == 98)
		printf("%ims Philosopher %i has died\n", curr_time, philo->number);
	pthread_mutex_unlock(&main->status);
	return ;
}
