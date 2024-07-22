/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_hashtable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:08:17 by schiper           #+#    #+#             */
/*   Updated: 2024/07/21 13:38:51 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_includes.h"

void	rehash_buckets(t_dictionary *old_table, t_dictionary *new_table)
{
	char	*key;
	char	*value;
	int		found;
	int		index;
	int		i;

	i = 0;
	while (i < old_table->size)
	{
		if (old_table->buckets[i].is_occupied
			&& !old_table->buckets[i].is_deleted)
		{
			value = old_table->buckets[i].value;
			key = old_table->buckets[i].key;
			index = find_slot(new_table, key, &found);
			if (index != -1)
				set_entry(&new_table->buckets[index], key, value);
		}
		i++;
	}
}

void	resize_table(t_dictionary *table, size_t new_size)
{
	t_dictionary	*new_table;

	new_table = create_table(new_size);
	rehash_buckets(table, new_table);
	free(table->buckets);
	table->buckets = new_table->buckets;
	table->size = new_size;
	free(new_table);
}

char	*f_strdup(char *src)
{
	char	*copy;
	int		index;
	int		lenght;

	lenght = ft_strlen(src);
	index = 0;
	copy = malloc(lenght * (sizeof(char) + 1));
	if (!copy)
		return (NULL);
	while (src[index] != '\0')
	{
		copy[index] = src[index];
		index++;
	}
	copy[index] = '\0';
	return (copy);
}
