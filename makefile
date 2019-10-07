# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmajstru <gmajstru@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/04 09:40:39 by guillaume         #+#    #+#              #
#    Updated: 2018/10/17 20:48:24 by gmajstru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

# for debugging
DEBUG = no

#colors
NO_COLOR=\x1b[0m
OK_COLOR=\x1b[32;01m
ERROR_COLOR=\x1b[31;01m
WARN_COLOR=\x1b[33;01m

OK_STRING=$(OK_COLOR)[OK]$(NO_COLOR)
SUCCESS_STRING=$(OK_COLOR)[FRACTOL SUCCESSFULLY BUILDED]$(NO_COLOR)
ERROR_STRING=$(ERROR_COLOR)[ERRORS]$(NO_COLOR)
WARN_STRING=$(WARN_COLOR)[WARNINGS]$(NO_COLOR)

# src
SRCS  = main.c \
		errors.c \
		init.c \
		colors.c \
		utils.c \
		drawer.c \
		moves.c \
		zoom.c \
		overlay.c \
		event_manager.c \
		viewport.c \

 # directories
 SRCDIR = ./srcs/
 INCDIR = ./includes/
 OBJDIR = ./obj/

# obj files
OBJ  = $(addprefix $(OBJDIR),$(SRCS:.c=.o))

# compiler
CC  = gcc

ifeq ($(DEBUG),yes)
	CFLAGS = -Wall -Wextra -Werror -Wunused -g
else
	CFLAGS = -Wall -Wextra -Werror -Wunused
endif

# mlx library
MLX  = ./mlx
 MLX_LIB = $(addprefix $(MLX),mlx.a)
 MLX_INC = -I ./mlx
 MLX_LNK = -L ./mlx -l mlx -framework OpenGL -framework AppKit

# ft library
 FT  = ./libft/
 FT_LIB = $(addprefix $(FT),libft.a)
 FT_INC = -I ./libft
 FT_LNK = -L ./libft -l ft

all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<
	@echo "$(OK_STRING)"

$(FT_LIB):
	$(MAKE) -C $(FT)

$(MLX_LIB):
	$(MAKE) -C $(MLX)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)
	@echo "$(SUCCESS_STRING)"

clean:
	rm -rf $(OBJDIR)
	$(MAKE) -C $(FT) clean
	$(MAKE) -C $(MLX) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(FT) fclean

re: fclean all
