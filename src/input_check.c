/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:10:51 by yustinov          #+#    #+#             */
/*   Updated: 2024/12/20 12:24:08 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Returns true if arg is a number
*/
static int	arg_is_number(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]) && av[i + 1] != '\0')
		i++;
	while (av[i] && is_digit(av[i]))
		i++;
	if (av[i] != '\0' && !is_digit(av[i]))
		return (0);
	return (1);
}

/*
** Checks for duplicates
*/
static int	have_duplicates(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (j != i && nbstr_cmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*
** Returns 1 if arg is 0
*/
static int	arg_is_zero(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]))
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

/*
** Checks if all args are numbers
*/
int	is_correct_input(char *av)
{
	int	i;
	int	nb_zeroes;

	nb_zeroes = 0;
	i = 1;
	while (av[i])
	{
		if (!arg_is_number(av[i]))
			return (0);
		nb_zeroes += arg_is_zero(av[i]);
		i++;
	}
	if (nb_zeroes > 1)
		return (0);
	if (have_duplicates(av))
		return (0);
	return (1);
}
