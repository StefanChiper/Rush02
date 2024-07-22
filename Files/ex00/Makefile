# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schiper <schiper@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/21 14:02:11 by schiper           #+#    #+#              #
#    Updated: 2024/07/21 22:57:25 by schiper          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR = ./srcs/
HEADER_DIR = ./includes/
DICT_DIR = ./dicts/

SRC = ft_split.c hash_table.c main.c parse_dictionary.c read_file.c utils_hashtable.c utils.c resize_hashtable.c ft_read_dict_2.c compare_char.c validate_input.c big_numbers.c big_numbers2.c
SRCS = $(addprefix $(SRCS_DIR), $(SRC))
SRCS_OBJ = $(SRCS:.c=.o)

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

OUTPUT = rush-02

all: $(OUTPUT)

$(OUTPUT): $(SRCS_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -I $(HEADER_DIR) -c $< -o $@

clean:
	rm -f $(SRCS_OBJ)

fclean: clean
	rm -f $(OUTPUT)

re: fclean all

.PHONY: all clean fclean re
