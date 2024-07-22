/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hashtable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:22:14 by schiper           #+#    #+#             */
/*   Updated: 2024/07/21 13:45:52 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_includes.h"

int	find_slot(t_dictionary *table, char *key, int *found)
{
	unsigned int	index;
	unsigned int	original_index;

	index = hash(key, table->size);
	original_index = index;
	*found = 0;
	while (table->buckets[index].is_occupied
		|| table->buckets[index].is_deleted)
	{
		if (table->buckets[index].is_occupied
			&& ft_strcmp(table->buckets[index].key, key) == 0)
		{
			*found = 1;
			return (index);
		}
		if (!table->buckets[index].is_occupied
			|| table->buckets[index].is_deleted)
			return (index);
		index = (index + 1) % table->size;
		if (index == original_index)
			return (-1);
	}
	return (index);
}

void	set_entry(t_entry *entry, char *key, char *value)
{
	if (entry->value != NULL)
		free(entry->value);
	entry->key = f_strdup(key);
	entry->value = f_strdup(value);
	entry->is_occupied = 1;
	entry->is_deleted = 0;
}

double	calculate_load_factor(t_dictionary *table)
{
	int	occupied;
	int	i;

	i = 0;
	occupied = 0;
	while (i < table->size)
	{
		if (table->buckets[i].is_occupied && !table->buckets[i].is_deleted)
			occupied++;
		i++;
	}
	return ((double)occupied / table->size);
}

void	free_table(t_dictionary *table)
{
	int	i;

	i = 0;
	while (i < table->size)
	{
		if (table->buckets[i].is_occupied)
		{
			free(table->buckets[i].value);
			free(table->buckets[i].key);
		}
		i++;
	}
	free(table->buckets);
	free(table);
}
