# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 14:51:03 by hbouillo          #+#    #+#              #
#    Updated: 2018/03/02 20:53:48 by hbouillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include Makefile.inc

# COMPILATION VARIABLES
CC = clang

# TARGET 1
TARGET_1 = hbouillo.filler
SRC_1 = filler/filler.c filler/parser.c filler/parser_piece.c \
		filler/helper.c filler/main.c \
		filler/analyse.c filler/strategy_helper.c \
		filler/choke/choke_champ.c filler/choke/choke_default.c \
		filler/woo/woo_champ.c filler/woo/woo_grade.c
OBJ_1 = $(addprefix obj/src/,$(SRC_1:.c=.o))
CFLAGS_1 = $(DEBUG_FLAGS) \
	-I$(LIBS_PATH)/include \
	-I$(LIBS_PATH)/include/freetype2 \
	-Iinc \
	-Ilib/inc
LFLAGS_1 = $(DEBUG_FLAGS) \
	-L$(LIBS_PATH)/lib \
	-Llib \
	-lft

# TARGET 2
TARGET_2 = show-filler
SRC_2 = show-filler/main.c show-filler/event/event.c show-filler/logic/logic.c \
	show-filler/logic/read.c show-filler/event/frame_event.c \
	show-filler/event/players_event.c show-filler/event/result_event.c \
	show-filler/event/scene_event.c \
	show-filler/event/key_event.c show-filler/error.c \
	show-filler/logic/parse.c show-filler/gui/gui.c \
	show-filler/gui/color_sets.c \
	\
	show-filler/gui/scene/main_scene.c \
	show-filler/gui/scene/end_scene.c \
	show-filler/gui/scene/end_components.c \
	show-filler/gui/scene/main_components.c \
	show-filler/gui/scene/buttons/pause_button.c \
	show-filler/gui/scene/buttons/next_button.c \
	show-filler/gui/scene/buttons/prev_button.c \
	show-filler/gui/scene/buttons/end_button.c \
	show-filler/gui/scene/buttons/begin_button.c \
	\
	show-filler/components/display/display.c \
	show-filler/components/display/display_draw.c \
	show-filler/components/display/display_event.c \
	show-filler/components/display/display_setters.c
OBJ_2 = $(addprefix obj/src/,$(SRC_2:.c=.o))
CFLAGS_2 = $(DEBUG_FLAGS) \
	-I$(LIBS_PATH)/include \
	-I$(LIBS_PATH)/include/freetype2 \
	-Iinc \
	-Ilib/inc
LFLAGS_2 = $(DEBUG_FLAGS) \
	-framework OpenGL -framework GLUT \
	-L$(LIBS_PATH)/lib \
	-L./lib \
	-lsimplegui -lft -lSDL2 -lfreetype

all: prebuild.$(TARGET_1) $(TARGET_1) postbuild.$(TARGET_1) \
	prebuild.$(TARGET_2) $(TARGET_2) postbuild.$(TARGET_2)
	@echo > /dev/null

$(TARGET_1): $(OBJ_1)
	$(call link, $(LFLAGS_1))

prebuild.$(TARGET_1):
	@mkdir -p lib
	@mkdir -p lib/inc
	@$(MAKE) -C simple-gui
	$(call dylib_install,./simple-gui/lib/libft.dylib)
	$(call dylib_install,./simple-gui/lib/libsimplegui.dylib)
	$(call dylib_include_install,./simple-gui/lib/inc)
	$(call dylib_include_install,./simple-gui/inc)
	$(call bgn_msg,$(TARGET_1))

postbuild.$(TARGET_1):
	$(call $(END_MSG),$(TARGET_1))

$(OBJ_1): ./obj/%.o: %.c
	$(call compile, $(CFLAGS_1))

$(TARGET_2): $(OBJ_2)
	$(call link, $(LFLAGS_2))

prebuild.$(TARGET_2):
	@mkdir -p lib
	@mkdir -p lib/inc
	@$(MAKE) -C simple-gui
	$(call dylib_install,./simple-gui/lib/libft.dylib)
	$(call dylib_install,./simple-gui/lib/libsimplegui.dylib)
	$(call dylib_include_install,./simple-gui/lib/inc)
	$(call dylib_include_install,./simple-gui/inc)
	$(call bgn_msg,$(TARGET_2))

postbuild.$(TARGET_2):
	$(call $(END_MSG),$(TARGET_2))

$(OBJ_2): ./obj/%.o: %.c
	$(call compile, $(CFLAGS_2))

clean:
	@$(MAKE) -C simple-gui clean
	$(call clean,$(TARGET_1),$(OBJ_1))
	$(call clean,$(TARGET_2),$(OBJ_2))

fclean:
	@$(MAKE) -C simple-gui fclean
	$(call fclean,$(TARGET_1),$(OBJ_1))
	$(call fclean,$(TARGET_2),$(OBJ_2))

libclean:
	@$(MAKE) -C simple-gui libclean
	@rm -rf ./lib

re: fclean all

.PHONY: all clean fclean \
	prebuild.$(TARGET_1) postbuild.$(TARGET_1) \
	prebuild.$(TARGET_2) postbuild.$(TARGET_2)
