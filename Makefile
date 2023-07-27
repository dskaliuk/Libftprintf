# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 14:44:09 by dskaliuk          #+#    #+#              #
#    Updated: 2023/07/28 01:23:02 by dskaliuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

L = ./Libft/
O = ./obj/
D = ./dep/

SRC		=	ft_printf.c			\
			ft_read_format.c	\
			ft_read_flag.c		\
			ft_read_width.c		\
			ft_read_prec.c		\
			ft_read_size.c		\
			ft_read_specifier.c	\
			ft_put_str.c		\
			ft_write_arg.c		\
			ft_ltoa.c

SRC_BONUS=	ft_wr_bonus.c		\
			ft_size_bonus.c		\
			ft_flag_bonus.c		\
			ft_prec_bonus.c 	\
			ft_width_bonus.c

SRC_MANDATORIO=	ft_wr.c

OBJ			= $(SRC:%.c=$O%.o)
OBJ_BONUS	= $(SRC_BONUS:%.c=$O%.o)
OBJ_MANDATORIO	= $(SRC_MANDATORIO:%.c=$O%.o)
NAME		= libftprintf.a
LIBFT		= $(L)libft.a
INCL		= ft_printf.h
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I -I$L 
AR 			= ar
ARFLAGS 	= -rcs

all: $(NAME)

$O:
	@echo "Creating a target directory $@ ..."
	@mkdir $@
	@echo "Completed!"

$(OBJ): | $O
$(OBJ_BONUS): | $O

$O%.o: %.c
	@echo "Generating a target file $@ ..."
	@$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME): $(OBJ) $(OBJ_MANDATORIO)
	@make -C $L
	@cp $(LIBFT) $(NAME)
	@echo "Adding files to the archive $@ ..."
	@$(AR) $(ARFLAGS) $(NAME) $(OBJ) $(OBJ_MANDATORIO)
	@echo "Completed!"

clean:
	@make clean -C $L
	@echo "Deleting object files and directory ..."
	@rm -rf $O
	@echo "Completed!"

fclean: clean
	@make fclean -C $L
	@echo "Deleting archive file $(NAME) ..."
	@rm -f $(NAME)
	@echo "Completed!"

re: fclean all

bonus: $(OBJ) $(OBJ_BONUS)
	@make -C $L
	@cp $(LIBFT) $(NAME)
	@echo "Adding bonus files to the archive $(NAME) ..."
	@$(AR) $(ARFLAGS) $(NAME) $(OBJ) $(OBJ_BONUS)
	@echo "Compleated!"

$(OBJ_BONUS): $(INCL)

.PHONY: all clean fclean re bonus bonus_flags