/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 11:35:38 by yustinov          #+#    #+#             */
/*   Updated: 2024/12/21 12:20:15 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Counting words
*/
static int	count_words(const char *str, char delimiter)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != delimiter && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*str == delimiter)
			in_word = 0;
		str++;
	}
	return (count);
}

/*
** Duplicating
 */
static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	word = malloc((finish - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static char	**allocate_result(const char *str)
{
	char	**result;
	int		words;

	words = count_words(str, ' ');
	result = malloc((words + 2) * sizeof(char *));
	if (!result)
		return (NULL);
	result[0] = ft_strdup("");
	return (result);
}

static void	populate_result(char **result, const char *str)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	start = -1;
	while (str[i])
	{
		if (str[i] != ' ' && start < 0)
			start = i;
		else if (str[i] == ' ' && start >= 0)
		{
			result[++j] = word_dup(str, start, i);
			start = -1;
		}
		i++;
	}
	if (start >= 0)
		result[++j] = word_dup(str, start, i);
	result[++j] = NULL;
}

/*
** Split, creating fake argv from 2 args
*/
char	**ft_split(char **argv)
{
	char	**result;
	char	*str;

	str = argv[1];
	result = allocate_result(str);
	if (!result)
		return (NULL);
	populate_result(result, str);
	return (result);
}
