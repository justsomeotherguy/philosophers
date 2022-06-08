/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:46:51 by jwilliam          #+#    #+#             */
/*   Updated: 2022/06/07 14:49:36 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
Main function of philosophers. Starts the program by checking the arguments 
received from the program input to make sure they are valid to use when 
assigning them to the variables in the main struct. When they are checked, 
start converting and assigning them to the main struct and initialize the 
philosopher data using the assigned data. 
After the structs are set and mutex variables are created, create the 
philosopher threads in the create_philos() function which will direct the 
new threads to the main cycle of what the philosophers are set to do. 
When a condition is met with the philosophers, the mutexes created are 
destroyed and the program is exited after freeing the philosopher structs. 
*/
int	main(int argc, char **argv)
{
	t_main		main;
	int			index;

	if (argc < 5 || argc > 6)
		err_bad_args();
	init_main(&main, argv);
	main.start_time = get_time();
	if (create_philos(&main) != 1)
		err_init();
	life_check(&main);
	index = 0;
	while (index < main.num_of_philo)
	{
		pthread_join(main.philosophers[index].thread, NULL);
		index++;
	}	
	end_process(&main);
	return (0);
}
