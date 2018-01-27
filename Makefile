# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 14:51:03 by hbouillo          #+#    #+#              #
#    Updated: 2018/01/27 01:24:38 by hbouillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include Makefile.inc

# COMPILATION VARIABLES
CC = clang

# TARGET 1
TARGET_1 = hbouillo.filler
DEP_1 = libft/libft.a
SRC_1 = filler/filler.c filler/parser.c filler/helper.c filler/main.c \
		filler/analyse.c filler/strategy_helper.c filler/dumb/dumb1_champ.c \
		filler/dumb/dumb2_champ.c filler/fork/fork_champ.c \
		filler/fork/fork_arms.c filler/fork/behaviours/back_behaviour.c \
		filler/fork/behaviours/right_behaviour.c \
		filler/fork/behaviours/left_behaviour.c \
		filler/choke/choke_champ.c filler/choke/choke_default.c \
		filler/woo/woo_champ.c filler/woo/woo_grade.c
OBJ_1 = $(addprefix obj/src/,$(SRC_1:.c=.o))
CFLAGS_1 = $(DEBUG_FLAGS) \
	-I./inc \
	-I./libft/inc
LFLAGS_1 = $(DEBUG_FLAGS) \
	-L./libft -lft

# TARGET 2
TARGET_2 = show-filler
DEP_2 = libft/libft.a
SRC_2 = show-filler/main.c show-filler/event/event.c show-filler/logic/logic.c \
	show-filler/logic/read.c
OBJ_2 = $(addprefix obj/src/,$(SRC_2:.c=.o))
CFLAGS_2 = $(DEBUG_FLAGS) \
	-I./inc \
	-I./libft/inc \
	-I/Users/hbouillo/.brew/include
LFLAGS_2 = $(DEBUG_FLAGS) \
	-L./libft -lft \
	-L/Users/hbouillo/.brew/lib -lSDL2

all: build.$(TARGET_1) build.$(TARGET_2)
	@echo > /dev/null

build.$(TARGET_1): prebuild.$(TARGET_1) $(TARGET_1) postbuild.$(TARGET_1)

prebuild.$(TARGET_1):
	@$(MAKE) -C libft
	$(eval CFLAGS = $(CFLAGS_1))
	$(eval LFLAGS = $(LFLAGS_1))
	$(call bgn_msg,$(TARGET_1))

postbuild.$(TARGET_1):
	$(call $(END_MSG),$(TARGET_1))

$(TARGET_1): $(OBJ_1) $(DEP_1)
	$(call link)

$(OBJ_1): ./obj/%.o: %.c
	$(call compile)

build.$(TARGET_2): prebuild.$(TARGET_2) $(TARGET_2) postbuild.$(TARGET_2)

prebuild.$(TARGET_2):
	@$(MAKE) -C libft
	$(eval CFLAGS = $(CFLAGS_2))
	$(eval LFLAGS = $(LFLAGS_2))
	$(call bgn_msg,$(TARGET_2))

postbuild.$(TARGET_2):
	$(call $(END_MSG),$(TARGET_2))

$(TARGET_2): $(OBJ_2) $(DEP_2)
	$(call link)

$(OBJ_2): ./obj/%.o: %.c
	$(call compile)

clean:
	@$(MAKE) -C libft clean
	$(call clean,$(TARGET_1),$(OBJ_1))
	$(call clean,$(TARGET_2),$(OBJ_2))

fclean:
	@$(MAKE) -C libft fclean
	$(call fclean,$(TARGET_1),$(OBJ_1))
	$(call fclean,$(TARGET_2),$(OBJ_2))

re: fclean all

.PHONY: all clean fclean \
	build.$(TARGET_1) prebuild.$(TARGET_1) postbuild.$(TARGET_1) \
	build.$(TARGET_2) prebuild.$(TARGET_2) postbuild.$(TARGET_2)
