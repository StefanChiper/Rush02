/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 23:00:41 by schiper           #+#    #+#             */
/*   Updated: 2024/07/21 13:55:53 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_includes.h"
/// @brief  loops through a list of characters and checks if first parameter
/// is the same with any of the other characters
/// @param c given char to compare with the list
/// @param charset list of characters that are meant to be separators of words
/// @return  1 in case c is in charset, 0 in case c is not in charset
int	is_sep(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset++)
			return (1);
	}
	return (0);
}

/// @brief  Counts how many words we have in a string that
/// are separated by any mentioned characters
/// @param str the full string
/// @param charset  lists of seperating  characters
/// @return number of words found
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

/// @brief  duplicates a string between two pointers
/// @param src  start point of the string
/// @param end  end point of the string
/// @return  a list of characters that can be freed
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

/// @brief Splits words found in STR separated by characters in charset
/// @param str  a string containing "word"/"words"
/// @param charset a list of characters that separate the words
/// @return a list of strings with separated words
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
