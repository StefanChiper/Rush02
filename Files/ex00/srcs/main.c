/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 20:46:19 by schiper           #+#    #+#             */
/*   Updated: 2024/07/22 14:10:15 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_includes.h"

/// @brief
/// @param
/// @return
int	main(int argc, char **argv)
{
	t_dictionary	*dictionary;
	char			*dictionary_path;
	char			*nbr;
	int				flag;

	flag = 1;
	dictionary = create_table(INITIAL_SIZE);
	if (flag == 1 && !ft_check_args(argc, argv, &dictionary_path, &nbr))
	{
		flag = 0;
		write(1, "Error\n", 7);
	}
	if (flag == 1 && ft_parse(DEFAULT_DICT, dictionary))
	{
		flag = 0;
		write(1, "Dict Error\n", 1);
	}
	if (flag == 1)
		char_first_to_last(dictionary, nbr);
	// number_to_words(nbr, dictionary);
	free_table(dictionary);
	//free(nbr);
	return (0);
}
