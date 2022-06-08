/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:01:09 by jwilliam          #+#    #+#             */
/*   Updated: 2022/06/07 14:04:50 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
Used to receive the current time, used for designating time stamps in the 
program.
*/
int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

/*
Helper function for ft_atoi() to check for non-printed characters.
*/
static int	check_whitespace(char c)
{
	if (c == '\n' || c == '\t' || c == '\r' || c == '\v' || c == '\f'
		|| c == 32)
		return (1);
	else
		return (0);
}

/*
Checks the string to ensure that only valid characters are passed through the 
arguments received from the program.
*/
int	ft_isvalidnum(char *str)
{
	int				i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((check_whitespace(str[i]) != 1) && (str[i] != '-' && str[i] != '+')
			&& !(str[i] >= 48 && str[i] <= 57))
			return (0);
		i++;
	}
	return (1);
}

/*
Converts a character string into an integer. Returns the integer created from
the string input, otherwise returns 0.
*/
int	ft_atoi(const char *str)
{
	int				index;
	int				neg;
	long			res;

	index = 0;
	res = 0;
	neg = 1;
	if (!str)
		return (0);
	while (check_whitespace(str[index] == 1))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			neg = -1;
		index++;
	}
	while (str[index] != '\0' && (str[index] >= 48 && str[index] <= 57))
	{
		res = (res * 10) + str[index] - '0';
		index++;
	}
	if (res > MAX || res < MIN)
		err_bad_args();
	return ((int)res * neg);
}
