/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 20:31:27 by schiper           #+#    #+#             */
/*   Updated: 2024/07/21 23:49:33 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_includes.h"

// get info if the number is 1, 10 or 100
char	*ft_choose_three_digits(int i)
{
	int	j;

	j = 1;
	while (j >= 1 && j <= 39)
	{
		if (i == j)
			return ("1");
		j = j + 3;
	}
	j = 2;
	while (j >= 2 && j <= 39)
	{
		if (i == j)
			return ("10");
		j = j + 3;
	}
	j = 3;
	while (j >= 3 && j <= 39)
	{
		if (i == j)
			return ("100");
		j = j + 3;
	}
	return ("");
}

// get info if the number is thousend, million, billion, etc
char	*ft_which_big_number(int i)
{
	if (i == 1 || i == 2 || i == 3)
		return ("");
	if (i == 4 || i == 5 || i == 6)
		return ("1000");
	if (i == 7 || i == 8 || i == 9)
		return ("1000000");
	if (i == 10 || i == 11 || i == 12)
		return ("1000000000");
	if (i == 13 || i == 14 || i == 15)
		return ("1000000000000");
	if (i == 16 || i == 17 || i == 18)
		return ("1000000000000000");
	if (i == 19 || i == 20 || i == 21)
		return ("1000000000000000000");
	if (i == 22 || i == 23 || i == 24)
		return ("1000000000000000000000");
	if (i == 25 || i == 26 || i == 27)
		return ("1000000000000000000000000");
	if (i == 28 || i == 29 || i == 30)
		return ("1000000000000000000000000000");
	if (i == 31 || i == 32 || i == 33)
		return ("1000000000000000000000000000000");
	if (i == 34 || i == 35 || i == 36)
		return ("1000000000000000000000000000000000");
	return ("1000000000000000000000000000000000000");
}

void	handle_hundreds(int *num, t_dictionary *table)
{
	char	*hundreds;

	if (*num >= 100)
	{
		hundreds = search(table, ft_itoa(*num / 100));
		if (hundreds != NULL)
			ft_print_number(table, ft_itoa(*num / 100));
		if (hundreds == NULL)
			return ;
		hundreds = search(table, "100");
		ft_print_number(table, "100");
		if (*num > 0)
			write(1, " and ", 5);
		*num %= 100;
	}
}

void	handle_tens(int *num, t_dictionary *table)
{
	char	*tens;

	if (*num >= 20)
	{
		tens = search(table, ft_itoa((*num / 10) * 10));
		if (tens == NULL)
			return ;
		ft_print_number(table, ft_itoa((*num / 10) * 10));
		if (*num % 10 != 0)
			write(1, "-", 1);
		*num %= 10;
	}
}

void	handle_units(int *num, t_dictionary *table)
{
	char	*units;

	if (*num > 0)
	{
		units = search(table, ft_itoa(*num));
		if (units == NULL)
			return ;
		ft_print_number(table, ft_itoa(*num));
	}
}
