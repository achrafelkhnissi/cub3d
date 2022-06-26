# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-khni <ael-khni@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/03 10:15:17 by ael-khni          #+#    #+#              #
#    Updated: 2022/06/04 14:08:09by ael-khni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D
	
CC			= cc
FLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

INCLUDES	= -I /usr/local/include
LIBMLX		= -L /usr/local/lib

OBJDIR = .objFiles

INIT		= $(addprefix init/, map_init)
PARSER		= $(addprefix parser/, parser check_map check_walls parser_utils \
					get_data check_cub)
UTILS		= $(addprefix utils/, gnl ft_strlen ft_strdup ft_strndup ft_split \
					ft_puterror ft_strcmp ft_strncmp ft_itoa ft_atoi)
# DDA			= $(addprefix DDA/, luncher)
FILES		= $(addprefix srcs/, cub3d $(PARSER) $(UTILS) $(DDA) $(INIT))
#OBJFILES		= $(addprefix .objFiles/, cub3d $(UTILS))

SRC			= $(FILES:=.c)
OBJ			= $(addprefix $(OBJDIR)/, $(FILES:=.o))
HEADER		= $(addprefix includes/, cub3d.h)
CUB3DHEADER = -I includes


#Colors:
GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m
CURSIVE		=	\e[33;3m

#Debug 
ifeq ($(DEBUG), 1)
   OPTS = -g
endif

.PHONY: all clean fclean re bonus norm

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@printf "$(CURSIVE)$(GRAY) 	- Compiling $(NAME)... $(RESET)\n"
	@$(CC) $(OBJ) $(INCLUDES) $(CUB3DHEADER) $(LIBMLX) $(OPTS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@printf "$(_SUCCESS) $(GREEN)- Executable ready.\n$(RESET)"

$(OBJDIR)/%.o: %.c $(HEADER)
	@mkdir -p $(dir $@)
	@ printf "$(CURSIVE)$(GRAY) 	- Making object file $@ from source file $< ... $(RESET)\n"
	@#printf "$(CURSIVE)$(GRAY) 	- Making object file $(notdir $@) from source file $(notdir $<) ... $(RESET)\n"
	@$(CC) -Wall -Wextra -Werror $(OPTS) $(CUB3DHEADER) $(OPTS) -c $< -o $@

norm:
	@printf "$(CURSIVE)$(GRAY)"
	@norminette
	@printf "$(RESET)"

clean:
	@ $(RM) $(OBJDIR) $(OBJ)
	@printf "$(CURSIVE)$(GRAY)	- Removing object files ... $(RESET)\n"
	@printf "$(YELLOW)    - Object files removed.$(RESET)\n"

fclean: clean
	@ $(RM) $(NAME)
	@printf "$(CURSIVE)$(GRAY)	- Removing $(NAME)... $(RESET)\n"
	@printf "$(YELLOW)    - Executable removed.$(RESET)\n"

re: fclean all