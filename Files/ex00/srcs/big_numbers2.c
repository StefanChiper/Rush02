/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_numbers2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 22:45:30 by schiper           #+#    #+#             */
/*   Updated: 2024/07/21 23:51:52 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_includes.h"

void	group_to_words(int num, t_dictionary *table)
{
	if (num == 0)
		return ;
	handle_hundreds(&num, table);
	handle_tens(&num, table);
	handle_units(&num, table);
}

void	format_result(int group_count, t_dictionary *table)
{
	char	*suffix;

	if (group_count > 1)
	{
		suffix = NULL;
		if (group_count == 2)
			suffix = search(table, "1000");
		else if (group_count == 3)
			suffix = search(table, "1000000");
		else if (group_count == 4)
			suffix = search(table, "1000000000");
		else if (group_count == 5)
			suffix = search(table, "1000000000000");
		else if (group_count == 6)
			suffix = search(table, "1000000000000000");
		if (suffix != NULL)
			write(1, suffix, ft_strlen(suffix));
	}
}

void	number_to_words(char *num_str, t_dictionary *table)
{
	int	len;
	int	group_count;
	int	pos;
	int	num;

	len = ft_strlen(num_str);
	group_count = (len + 2) / 3;
	pos = len;
	while (group_count > 0)
	{
		if (pos < 0)
			pos = 0;
		if (pos == 1)
			num = num_str[pos] - '0';
		if (pos == 2)
			num = (num_str[pos - 2] - '0') * 10 + (num_str[pos - 1] - '0');
		if (pos >= 3)
			num = (num_str[pos - 3] - '0') * 100 + (num_str[pos - 2] - '0') * 10
				+ (num_str[pos - 1] - '0');
		pos -= 3;
		group_to_words(num, table);
		format_result(group_count, table);
		group_count--;
	}
}
