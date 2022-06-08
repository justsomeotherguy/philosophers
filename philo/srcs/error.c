/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:17:36 by jwilliam          #+#    #+#             */
/*   Updated: 2022/06/07 14:33:50 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
Prints out the expected inputs for the program arguments if they are invalid.
*/
void	err_bad_args(void)
{
	printf("Error : Bad Arguments\n");
	printf("Usage : ./philo [a] [b] [c] [d] [e]\n");
	printf("[a] - Number of philophers, must be between 1-200.\n");
	printf("[b] - Time to die in ms.\n");
	printf("[c] - Time to eat in ms.\n");
	printf("[d] - Time to sleep in ms.\n");
	printf("[e] - Optional. Times each philosopher must eat.\n");
	exit(1);
}

/*
Generic error to display when something has failed to initialize.
*/
void	err_init(void)
{
	printf("Error : Failed to initialize\n");
	exit(1);
}
