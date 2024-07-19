/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 23:00:41 by schiper           #+#    #+#             */
/*   Updated: 2024/07/19 23:00:49 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset++)
			return (1);
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		while (*str != '\0' && is_sep(*str, charset))
			str++;
		if (*str && !is_sep(*str, charset))
		{
			count++;
			while (*str && !is_sep(*str, charset))
				str++;
		}
	}
	return (count);
}

char	*ft_strdup(char *src, char *end)
{
	char	*copy;
	int		index;
	int		lenght;

	lenght = end - src;
	index = 0;
	copy = malloc(lenght * (sizeof(char) + 1));
	if (!copy)
		return (NULL);
	while (src[index] != '\0' && src[index] != *end)
	{
		copy[index] = src[index];
		index++;
	}
	copy[index] = '\0';
	return (copy);
}

char	**ft_split(char *str, char *charset)
{
	int		words;
	int		index;
	char	**list_of_string;
	char	*start;

	words = count_words(str, charset);
	list_of_string = (char **)malloc((words + 1) * sizeof(char *));
	if (!list_of_string)
		return (NULL);
	index = 0;
	while (*str)
	{
		while (*str && is_sep(*str, charset))
			str++;
		if (*str && !is_sep(*str, charset))
		{
			start = str;
			while (*str && !is_sep(*str, charset))
				str++;
			start = ft_strdup(start, str);
			list_of_string[index++] = start;
		}
	}
	return (list_of_string);
}
