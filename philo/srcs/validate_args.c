/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:53:39 by jwilliam          #+#    #+#             */
/*   Updated: 2022/06/07 13:26:15 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
Checks the arguments received from the program and checks whether they are
valid numbers and within the acceptable parameters for the program.
Returns 1 if all numbers are good otherwise return 0.
*/
int	validate_args(char **argv)
{
	if (ft_isvalidnum(argv[1]) == 1)
		if ((ft_atoi(argv[1]) < 1) && (ft_atoi(argv[1]) > 200))
			return (0);
	if (ft_isvalidnum(argv[2]) == 1)
		if (ft_atoi(argv[2]) < 50)
			return (0);
	if (ft_isvalidnum(argv[3]) == 1)
		if (ft_atoi(argv[3]) < 50)
			return (0);
	if (ft_isvalidnum(argv[4]) == 1)
		if (ft_atoi(argv[4]) < 50)
			return (0);
	if (argv[5])
		if (ft_isvalidnum(argv[5]) == 1)
			if (ft_atoi(argv[5]) < 1)
				return (0);
	return (1);
}
