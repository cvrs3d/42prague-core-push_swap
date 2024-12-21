/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:47:01 by yustinov          #+#    #+#             */
/*   Updated: 2024/12/21 12:37:10 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

/*
**Checks if the stack is already sorted
*/
int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/*
**Choosing a sorting method depending on N
*/
static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		do_sa(stack_a);
	else if (stack_size == 3)
		tiny_sort(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

/*
** Stack init
*/
static void	run(char **argv, int argc)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	stack_b = NULL;
	stack_a = fill_stack_values(argc, argv);
	stack_size = get_stack_size(stack_a);
	assign_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
}

/*
** Parses input, checks it, initialize a and b
*/
int	main(int argc, char **argv)
{
	int	flag;

	flag = 0;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		argv = ft_split(argv);
		argc = 0;
		while (argv[argc])
			argc++;
		flag = 1;
	}
	if (!is_correct_input(argv))
	{
		if (flag == 1)
			free_split(argv);
		exit_error(NULL, NULL);
	}
	run(argv, argc);
	if (flag == 1)
		free_split(argv);
	return (0);
}
