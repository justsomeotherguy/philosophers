/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:47:38 by jwilliam          #+#    #+#             */
/*   Updated: 2022/06/07 13:24:49 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

# define MAX	2147483647
# define MIN	-2147483648

typedef struct s_philo
{
	int					number;
	int					last_time_eaten;
	int					times_eaten;
	pthread_mutex_t		fork;
	struct s_philo		*next_to;
	struct s_main		*main;
	pthread_t			thread;
}	t_philo;

typedef struct s_main
{
	int					num_of_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					times_must_eat;
	int					all_eaten;
	int					death;
	int					start_time;	
	t_philo				*philosophers;
	pthread_mutex_t		status;
}	t_main;

/*
actions.c
*/
void		*do_actions(void *philo);

/*
error.c
*/
void		err_bad_args(void);
void		err_init(void);

/*
init.c
*/
int			init_philo(t_main *main);
void		init_main(t_main *main, char **argv);

/*
print_action.c
*/
void		print_action(t_main *main, t_philo *philo, int action);

/*
process.c
*/
void		end_process(t_main *main);
int			create_philos(t_main *main);
void		life_check(t_main *main);

/*
utils.c
*/
int			ft_atoi(const char *str);
int			get_time(void);
int			ft_isvalidnum(char *str);

/*
validate_args.c
*/
int			validate_args(char **argv);

#endif