/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 23:31:59 by schiper           #+#    #+#             */
/*   Updated: 2024/07/21 17:34:39 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_includes.h"

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
		write(1, str++, 1);
}

char	*trim(char *str)
{
	char	*start;
	char	*end;

	while (ft_whitespace((unsigned char)*str))
		str++;
	if (*str == 0)
		return (str);
	start = str;
	end = str + ft_strlen(str) - 1;
	while (end > start && ft_whitespace((unsigned char)*end))
		end--;
	*(end + 1) = '\0';
	return (start);
}
