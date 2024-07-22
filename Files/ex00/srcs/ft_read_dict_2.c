/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_dict_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:56:54 by asemykin          #+#    #+#             */
/*   Updated: 2024/07/21 22:48:05 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_includes.h"

int	ft_set_keys_1(t_dictionary *table, char *infos[5])
{
	char	a[3];

	a[0] = *infos[0];
	a[1] = '\0';
	if (search(table, a) == NULL)
		return (0);
	if (*infos[3] == '1')
	{
		ft_print_number(table, infos[1]);
		if (ft_strcmp(infos[1], "") != 0)
			write(1, " ", 1);
		return (1);
	}
	else
	{
		ft_print_number(table, a);
		write(1, " ", 1);
		if (ft_strcmp(infos[1], "") != 0)
		{
			ft_print_number(table, infos[1]);
			if (ft_strcmp(infos[1], "") != 0)
				write(1, " ", 1);
		}
		return (1);
	}
}

int	ft_set_keys_10(t_dictionary *table, char *infos[5])
{
	char	a[3];

	a[0] = *infos[0];
	a[1] = '\0';
	if (search(table, a) == NULL)
		return (0);
	if (*infos[0] == '1')
	{
		a[0] = *infos[0];
		a[1] = *infos[4];
		a[2] = '\0';
		ft_print_number(table, a);
		write(1, " ", 1);
		return (1);
	}
	else
	{
		a[0] = *infos[0];
		a[1] = '0';
		a[2] = '\0';
		ft_print_number(table, a);
		write(1, " ", 1);
		return (1);
	}
}

int	ft_set_keys_100(t_dictionary *table, char *infos[5])
{
	char	a[3];

	a[0] = *infos[0];
	a[1] = '\0';
	if (search(table, a) == NULL || search(table, a) == NULL)
		return (0);
	ft_print_number(table, a);
	write(1, " ", 1);
	write(1, search(table, "100"), ft_strlen(search(table, "100")));
	write(1, " ", 1);
	return (1);
}

int	ft_set_keys(t_dictionary *table, char *infos[5])
{
	char	a[3];

	a[0] = *infos[0];
	a[1] = '\0';
	if (ft_strcmp(infos[2], "100") == 0)
	{
		if (ft_set_keys_100(table, infos) == 1)
			return (1);
	}
	else if (ft_strcmp(infos[2], "10") == 0)
	{
		if (ft_set_keys_10(table, infos) == 1)
			return (1);
	}
	else if (ft_strcmp(infos[2], "1") == 0)
	{
		if (ft_set_keys_1(table, infos) == 1)
			return (1);
	}
	return (0);
}

int	char_first_to_last(t_dictionary *table, char *num)
{
	int		num_length1;
	int		num_length2;
	char	*info_array[5];

	num_length1 = 0;
	num_length2 = 0;
	while (num[num_length1] != '\0')
		num_length1++;
	while (num[num_length2] != '\0')
	{
		info_array[0] = &num[num_length2];
		info_array[1] = ft_which_big_number(num_length1);
		info_array[2] = ft_choose_three_digits(num_length1);
		info_array[3] = &num[num_length2 - 1];
		info_array[4] = &num[num_length2 + 1];
		if (ft_strlen(num) > 1 && ft_strcmp(info_array[4], "0") == 0)
			break ;
		if (ft_set_keys(table, info_array) == 0)
			return (0);
		num_length1--;
		num_length2++;
	}
	return (1);
}

// info_array[0] = current number after split
// info_array[1] = which big number (thosend, million etc.)
// info_array[2] = is it 1, 10 or 100
// info_array[3] = - current number
// info_array[4] = + current number
