/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dictionary.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:47:30 by schiper           #+#    #+#             */
/*   Updated: 2024/07/21 23:16:27 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_includes.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2++)
		if (*s1++ == '\0')
			return (0);
	return (*s1 - *(s2 - 1));
}

void	ft_print_number(t_dictionary *table, char *str)
{
	if (search(table, str) != NULL)
		write(1, search(table, str), ft_strlen(search(table, str)));
}

int	ft_parse(char *dictpath, t_dictionary *table)
{
	char	**word_split;
	int		i;
	char	*key;
	char	*value_str;

	i = -2;
	word_split = NULL;
	word_split = ft_read_file(dictpath);
	if (!word_split)
		return (-1);
	while (word_split[i + 2] != NULL)
	{
		i += 2;
		key = trim(word_split[i]);
		value_str = trim(word_split[i + 1]);
		insert(table, key, value_str);
		free(word_split[i]);
		free(word_split[i + 1]);
	}
	free(word_split);
	return (0);
}

char	*helper_1(int num)
{
	char	*str;

	str = NULL;
	if (num == 0)
	{
		str = (char *)malloc(2 * sizeof(char));
		if (str == NULL)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
	}
	return (str);
}

char	*ft_itoa(int num)
{
	char	*str;
	int		len;
	int		temp;

	len = 0;
	temp = num;
	str = helper_1(num);
	if (str != NULL)
		return (str);
	while (temp > 0)
	{
		len++;
		temp /= 10;
	}
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (num > 0)
	{
		str[--len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
