#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/29 13:16:03 by mcanal            #+#    #+#              #
#    Updated: 2015/10/05 16:40:52 by mcanal           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = philo
SRC = main.c init.c draw.c state.c threads.c error.c move_eating_sticks.c move_thinking_sticks.c
O_DIR = obj
C_DIR = src
VPATH =	src

SRCC = $(addprefix $(C_DIR)/,$(SRC))
OBJS =	$(SRC:%.c=$(O_DIR)/%.o)
DEPS =  $(OBJS:%.o=%.d)

LIB = libft/libft.a
I_DIR = -I./libft/inc/ -I./inc/ -I/usr/include/SDL/
CFLAGS = -Wall -Wextra -Werror -O2
RM = rm -rf
MKDIR = mkdir -p

ifeq ($(shell uname), Linux)
CC = clang-3.5
I_DIR = -I./libft/inc/ -I./inc/ -I/usr/include/SDL/
SDL = -lSDL
THREAD = -pthread
else
CC = clang
I_DIR = -I./libft/inc/ -I./inc/ `sdl-config --cflags`
SDL = `sdl-config --libs`
THREAD = #-pthread 
endif

WHITE = \033[37;01m
RED = \033[31;01m
GREEN =  \033[32;01m
BLUE =  \033[34;01m
BASIC = \033[0m

.PHONY: all debug debug_lib sanitize sanitize_lib me_cry lib clean fclean zclean re brute

all: lib $(NAME) $(S_NAME)

debug: CFLAGS = -g -ggdb -O2
debug: debug_lib $(NAME) $(S_NAME)
debug_lib:
	@$(MAKE) -C libft debug

sanitize: CFLAGS = -g -ggdb -O2 -fsanitize=address,undefined -ferror-limit=5
sanitize: sanitize_lib $(NAME) $(S_NAME)
sanitize_lib:
	@$(MAKE) -C libft sanitize

me_cry: CFLAGS += -Wpedantic -Wshadow -Wcast-qual -Wconversion -Wcast-align \
				  -Wstrict-prototypes -Wmissing-prototypes -Wunreachable-code \
				  -Winit-self -Wmissing-declarations -Wnonnull -Wuninitialized \
				  -Wfloat-equal -Wbad-function-cast -Wundef -Waggregate-return \
				  -Wstrict-overflow=5
me_cry: lib $(NAME) $(S_NAME)

lib:
	@$(MAKE) -C libft

-include $(DEPS)

$(NAME): $(OBJS) $(LIB)
	@$(CC) $(CFLAGS) $(THREAD) $(SDL) $(I_DIR) $(OBJS) $(LIB) -o $@
	@echo "$(BLUE)$(OBJS) $(WHITE)->$(RED) $@ $(BASIC)"
	@echo "$(WHITE)flags:$(BASIC) $(CFLAGS)"
	@echo "$(WHITE)compi:$(BASIC) $(CC)"

$(O_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) $(I_DIR) -MMD -c $< -o $@
	@echo "$(WHITE)$<\t->$(BLUE) $@ $(BASIC)"

$(OBJS): | $(O_DIR)

$(O_DIR):
	@$(MKDIR) $(O_DIR)

clean:
	@$(RM) $(O_DIR)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(S_NAME)

zclean: fclean
	@make -C libft fclean

re: fclean all

brute: zclean all
