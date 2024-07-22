/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:34:56 by schiper           #+#    #+#             */
/*   Updated: 2024/07/21 13:34:09 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_includes.h"

/// @brief  Functions takes a string and returns a unique string
/// meant to be searched in a dictionary
/// @param key string in our case a number represented as a string
/// @param size
/// @return
unsigned int	hash(char *key, int size)
{
	unsigned long	hash;
	int				c;

	hash = 5381;
	c = *key++;
	while (c)
	{
		hash = ((hash << 5) + hash) + c;
		c = *key++;
	}
	return (hash % size);
}

/// @brief Function that allocates a dictionary creates and initializes
///  all elements to 0, value is NULL since it's expected to be a string
/// @param size size of the current dictionary
/// @return  newly created dictionary, it needs to be freed
t_dictionary	*create_table(int size)
{
	t_dictionary	*table;
	int				i;

	table = (t_dictionary *)malloc(sizeof(t_dictionary));
	table->buckets = (t_entry *)malloc(sizeof(t_entry) * size);
	table->size = size;
	i = 0;
	while (i < size)
	{
		table->buckets[i].is_occupied = 0;
		table->buckets[i].is_deleted = 0;
		table->buckets[i].value = NULL;
		table->buckets[i].key = NULL;
		i++;
	}
	return (table);
}

/// @brief  Deletes one element in the dictionary marking is_deleted to 1
/// @param table current dictionary
/// @param key  key of the element we wish to delete
void	delete_entry(t_dictionary *table, char *key)
{
	unsigned int	index;
	unsigned int	original_index;
	double			load_factor;

	index = hash(key, table->size);
	original_index = index;
	while (table->buckets[index].is_occupied
		|| table->buckets[index].is_deleted)
	{
		if (table->buckets[index].is_occupied
			&& table->buckets[index].key == key)
		{
			free(table->buckets[index].value);
			table->buckets[index].value = NULL;
			table->buckets[index].is_deleted = 1;
			load_factor = calculate_load_factor(table);
			if (load_factor < LOAD_FACTOR_LOWER && table->size > INITIAL_SIZE)
				resize_table(table, table->size / 2);
			return ;
		}
		index = (index + 1) % table->size;
		if (index == original_index)
			break ;
	}
}

/// @brief Function that searches any element of the dictionary very efficiently
/// Complexity time is O(1) aka it's instants, no LOOPING, done so because
/// we keep the dictionary at around 60-70% occupation rate so
/// in theory no keys should collide or repeat
/// in case they collide the search for correct value is extremly fast
/// @param table current dictionary we wish to search elements on
/// @param key  element we are trying to find in the dictionary
/// @return  the string value of the element we found
char	*search(t_dictionary *table, char *key)
{
	unsigned int	index;
	unsigned int	original_index;

	index = hash(key, table->size);
	original_index = index;
	while (table->buckets[index].is_occupied
		|| table->buckets[index].is_deleted)
	{
		if (table->buckets[index].is_occupied
			&& ft_strcmp(table->buckets[index].key, key) == 0)
		{
			return (table->buckets[index].value);
		}
		index = (index + 1) % table->size;
		if (index == original_index)
		{
			break ;
		}
	}
	return (NULL);
}

/// @brief  Function inserts a new element in the dictionary
/// @param table
/// @param key
/// @param value
/// @return
int	insert(t_dictionary *table, char *key, char *value)
{
	int		found;
	int		index;
	double	load_factor;

	load_factor = calculate_load_factor(table);
	if (load_factor > LOAD_FACTOR_UPPER)
		resize_table(table, table->size * 2);
	index = find_slot(table, key, &found);
	if (index == -1)
		return (-1);
	set_entry(&table->buckets[index], key, value);
	return (0);
}
