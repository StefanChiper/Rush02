/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_includes.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 21:00:32 by schiper           #+#    #+#             */
/*   Updated: 2024/07/19 23:01:49 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(FT_INCLUDES_H)
# define FT_INCLUDES_H

# include <fcntl.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <unistd.h>
# define BUFFER_SIZE 2048

typedef struct Dictionary_entry
{
	unsigned int	*key;
	char			*value;
	char			is_occupied;
	char			is_deleted;
}					t_entry;
typedef struct HashMap
{
	t_entry			*buckets;
	int				size;
}					t_dictionaryi;

char				**ft_split(char *str, char *charset);

#endif // FT_INCLUDES_H