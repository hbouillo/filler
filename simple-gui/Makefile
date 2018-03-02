# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 14:51:03 by hbouillo          #+#    #+#              #
#    Updated: 2018/03/02 04:14:41 by hbouillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include Makefile.inc

# COMPILATION VARIABLES
CC = clang
CFLAGS = $(DEBUG_FLAGS) \
	-I$(LIBS_PATH)/include \
	-I$(LIBS_PATH)/include/freetype2 \
	-Ilib/inc \
	-Iinc
LFLAGS = $(DEBUG_FLAGS) \
	-framework OpenGL -framework GLUT \
	-L$(LIBS_PATH)/lib \
	-Llib \
	-lSDL2 -lft -lfreetype

# TARGETS
TARGET_1 = lib/libsimplegui.dylib
SRC_1 = sg.c sg_destroy.c sg_draw.c sg_event.c sg_event_update.c \
	utils/rect_utils.c utils/rect_utils_2.c utils/pos_utils.c \
	utils/shader_utils.c utils/color_utils.c \
	utils/uniform_utils.c utils/resources.c \
	\
	font/font_manager.c font/font_renderer.c font/font_gstr.c \
	\
	component/component.c component/component_states.c \
	component/component_setters.c component/component_setters_2.c \
	component/component_getters.c \
	\
	component/button/button.c component/button/button_draw.c \
	component/button/button_event.c component/button/button_setters.c \
	component/button/button_setters_2.c \
	\
	component/label/label.c component/label/label_draw.c \
	component/label/label_event.c component/label/label_setters.c \
	\
	component/rectangle/rectangle.c component/rectangle/rectangle_draw.c \
	component/rectangle/rectangle_event.c component/rectangle/rectangle_setters.c
OBJ_1 = $(addprefix obj/src/,$(SRC_1:.c=.o))

all: build.$(TARGET_1)
	@echo > /dev/null

build.$(TARGET_1): prebuild.$(TARGET_1) $(TARGET_1) postbuild.$(TARGET_1)

prebuild.$(TARGET_1):
	@mkdir -p lib
	@mkdir -p lib/inc
	@$(MAKE) -C libft
	$(call dylib_install,./libft/lib/libft.dylib)
	$(call dylib_include_install,./libft/inc)
ifeq ("$(wildcard $(LIBS_PATH)/lib/libSDL2.dylib)","")
	$(call lib_configure_make_install,SDL2)
	@install_name_tool -id "$(LIBS_PATH)/lib/libSDL2.dylib" "$(LIBS_PATH)/lib/libSDL2.dylib"
endif
ifeq ("$(wildcard $(LIBS_PATH)/lib/libfreetype.dylib)","")
	$(call lib_configure_make_install,freetype-2.9)
	@install_name_tool -id "$(LIBS_PATH)/lib/libfreetype.dylib" "$(LIBS_PATH)/lib/libfreetype.dylib"
endif
	$(call bgn_msg,$(TARGET_1))

postbuild.$(TARGET_1):
	$(call $(END_MSG),$(TARGET_1))

$(TARGET_1): $(OBJ_1)
	$(call link_dylib)

$(OBJ_1): ./obj/%.o: %.c
	$(call compile)

clean:
	@$(MAKE) -C libft clean
	$(call clean,$(TARGET_1),$(OBJ_1))

fclean:
	@$(MAKE) -C libft fclean
	$(call lib_fclean,$(TARGET_1),$(OBJ_1))

libclean:
	@echo "$(STL_BOLD)$(RGB_BLUE)⧖  Cleaning $(RGB_CYAN)libs$(RGB_BLUE)... ⧖$(RGB_RESET)"
	@$(MAKE) -C libft libclean
	@rm -rf ./lib
	@rm -f $(LIBS_PATH)/lib/libSDL2.dylib $(LIBS_PATH)/lib/libfreetype.dylib
	@echo "$(STL_BOLD)$(RGB_BLUE)✓  Cleaned $(RGB_CYAN)libs$(RGB_BLUE) successfully. ✓$(RGB_RESET)"

re: fclean all

.PHONY: all clean fclean \
	build.$(TARGET_1) prebuild.$(TARGET_1) postbuild.$(TARGET_1) \
