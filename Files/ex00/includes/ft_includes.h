/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_includes.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 21:00:32 by schiper           #+#    #+#             */
/*   Updated: 2024/07/22 13:53:08 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(FT_INCLUDES_H)
# define FT_INCLUDES_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <unistd.h>
# define BUFFER_SIZE 1024
# define LOAD_FACTOR_UPPER 0.7
# define LOAD_FACTOR_LOWER 0.2
# define INITIAL_SIZE 180
# define DEFAULT_DICT "dicts/numbers.dict"
# define DICT_DIR "dicts/"

typedef struct Dictionary_entry
{
	char		*key;
	char		*value;
	char		is_occupied;
	char		is_deleted;
}				t_entry;
typedef struct HashMap
{
	t_entry		*buckets;
	char ** unique_keys;
	int			size;
}				t_dictionary;

unsigned int	hash(char *key, int size);
int				find_slot(t_dictionary *table, char *key, int *found);
void			set_entry(t_entry *entry, char *key, char *value);
double			calculate_load_factor(t_dictionary *table);
void			free_table(t_dictionary *table);
char			**ft_read_file(char *dictpath);
t_dictionary	*create_table(int size);
void			delete_entry(t_dictionary *table, char *key);
char			*search(t_dictionary *table, char *key);
int				insert(t_dictionary *table, char *key, char *value);
void			resize_table(t_dictionary *table, size_t new_size);
char			**ft_split(char *str, char *charset);
int				ft_strlen(char *str);
char			*trim(char *str);
void			ft_putstr(char *str);
char			*ft_strdup(char *src, char *end);
char			*f_strdup(char *src);
int				ft_parse(char *dictpath, t_dictionary *table);
char			**ft_split(char *str, char *charset);
int				ft_strcmp(char *s1, char *s2);
int				ft_alpha(char c);
int				ft_number(char c);
int				ft_upper(char c);
int				ft_lower(char c);
int				ft_whitespace(char c);
int				char_first_to_last(t_dictionary *table, char *num);
int				ft_check_args(int argc, char **argv, char **dictpath,
					char **nbr);
char			*ft_which_big_number(int i);
char			*ft_choose_three_digits(int i);
void			ft_print_number(t_dictionary *table, char *str);
void			handle_units(int *num, t_dictionary *table);
void			handle_tens(int *num, t_dictionary *table);
void			handle_hundreds(int *num, t_dictionary *table);
void			number_to_words(char *num_str, t_dictionary *table);
void			format_result(int group_count, t_dictionary *table);
void			group_to_words(int num, t_dictionary *table);
char			*ft_itoa(int num);
#endif // FT_INCLUDES_H
