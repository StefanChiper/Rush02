/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 20:45:50 by schiper           #+#    #+#             */
/*   Updated: 2024/07/19 23:00:56 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_includes.h"

int	ft_get_file_size(char *dictpath)
{
	char	*buffer;
	int		file;
	int		count;
	ssize_t	bytes_read;

	file = open(dictpath, O_RDONLY);
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
	{
		perror("Failed to allocate buffer");
		return (-1);
	}
	if (file == -1)
		return (-1);
	count = 0;
	bytes_read = read(file, buffer, buffer);
	while (bytes_read > 0)
	{
		count += bytes_read;
		bytes_read = read(file, buffer, buffer);
	}
	close(file);
	free(buffer);
	return (count);
}

char	**ft_read_file(char *dictpath)
{
	char	*buffer;
	char	**word_split;
	int		size_of;
	int		file;
	ssize_t	bytes_read;

	size_of = ft_get_file_size(dictpath);
	file = open(dictpath, O_RDONLY);
	buffer = malloc(sizeof(char) * (size_of + 1));
	if (!buffer || size_of < 0 || file < 0)
	{
		free(buffer);
		close(file);
		return (NULL);
	}
	bytes_read = read(file, buffer, size_of);
	while (bytes_read > 0)
	{
		buffer[size_of] = '\0';
		word_split = ft_split(buffer, "\n");
		bytes_read = read(file, buffer, size_of);
	}
	free(buffer);
	cloe(file);
	return (word_split);
}
