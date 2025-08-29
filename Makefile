# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/02 14:55:41 by fvargas           #+#    #+#              #
#    Updated: 2025/07/16 19:12:59 by dmlasko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include config.mk
include colors.mk

UBUNTU_VERSION := $(shell . /etc/os-release && echo $$VERSION_ID)

ifeq ($(UBUNTU_VERSION), "22.04")
	OS_FLAGS += -DLINUX_22=1
    OS_VERSION_TAG := ubuntu22
else ifeq ($(UBUNTU_VERSION), "24.04")
	OS_FLAGS += -DLINUX_22=0
    OS_VERSION_TAG := ubuntu24
else
    OS_VERSION_TAG := unknown
endif

# PROJECT NAME
NAME = cub3D
NAME_BONUS = cub3D_bonus

# COMPILER
CC = gcc

# DIRECTORIES
INC_DIR = ./inc
SRC_DIR = ./src
OBJ_DIR = ./obj
OBJ_DIR_BONUS = ./obj_bonus


# LIBRARIES
LIBDIRS = ./lib
LIBFT_DIR = $(LIBDIRS)/libft
LIBFT = $(LIBFT_DIR)/libft.a

SDL2_INC := lib/SDL2/build/include/SDL2
SDL2_MIXER_INC := lib/SDL2_mixer/build/include

MINILIBX = $(MINILIBX_DIR)libmlx.a
MINILIBX_DIR = $(LIBDIRS)/minilibx/

# COMPILATION FLAGS
# CFLAGS = -Wall -Wextra -Werror
CFLAGS += -g
CFLAGS += -I$(INC_DIR)
CFLAGS += -I$(MINILIBX_DIR)
CFLAGS += -std=c99
CFLAGS += -Wno-error=type-limits
CFLAGS += -D_POSIX_C_SOURCE=200112L

# CFLAGS += -I$(SDL2_INC) -I$(SDL2_MIXER_INC) -D_REENTRANT
# LINKER FLAGS
LDFLAGS += -L$(LIBFT_DIR) -lft
LDFLAGS += -L$(MINILIBX_DIR) -lmlx
LDFLAGS += -lX11 -lXext -lm
# LDFLAGS += -Llib/SDL2/build/lib -Llib/SDL2_mixer/build/lib -lSDL2 -lSDL2_mixer


# EXTRA FLAGS
BONUSFLAGS = -DBONUS=1

# ------------------------------------------------------------------------------

# SOURCE FILES
SRC := $(shell find $(SRC_DIR) -name "*.c")
# SRC =	./src/controls/map_position_is_walkable.c \
# 		./src/controls/move_forward_backward.c \
# 		./src/controls/move_sideways.c \
# 		./src/controls/process_keyboard_keypresses.c \
# 		./src/controls/reset_mouse_position.c \
# 		./src/controls/rotate_player.c \
# 		./src/controls/rotate_vector.c \
# 		./src/controls/set_keyboard_hooks.c \
# 		./src/controls/set_mouse_hooks.c \
# 		./src/debug/show_debug_info_aux.c \
# 		./src/debug/show_debug_info.c \
# 		./src/drawing/draw_background.c \
# 		./src/drawing/draw_circle.c \
# 		./src/drawing/draw_grid.c \
# 		./src/drawing/draw_lines.c \
# 		./src/drawing/draw_rectangle.c \
# 		./src/drawing/draw_square.c \
# 		./src/drawing/draw_vector.c \
# 		./src/drawing/img_pix_put.c \
# 		./src/drawing/put_img_to_img.c \
# 		./src/free/free.c \
# 		./src/free/free_dt.c \
# 		./src/free/free_graphic.c \
# 		./src/free/free_img.c \
# 		./src/free/free_texture.c \
# 		./src/free/free_texture_sprite.c \
# 		./src/free/free_wall_tile_texture.c \
# 		./src/free/protected_malloc.c \
# 		./src/main.c \
# 		./src/minimap/draw_minimap_base_img.c \
# 		./src/minimap/draw_minimap_elements.c \
# 		./src/minimap/draw_minimap_player.c \
# 		./src/minimap/draw_minimap_rays.c \
# 		./src/minimap/set_coor_values.c \
# 		./src/minimap/update_minimap.c \
# 		./src/parsing/check_all_wall_tile.c \
# 		./src/parsing/check_color.c \
# 		./src/parsing/check_only_number.c \
# 		./src/parsing/check_type_file.c \
# 		./src/parsing/check_valid_color.c \
# 		./src/parsing/check_valid_color_or_texture.c \
# 		./src/parsing/check_valid_identifier_texture.c \
# 		./src/parsing/check_valid_map.c \
# 		./src/parsing/check_valid_player.c \
# 		./src/parsing/check_valid_wall_tile_file.c \
# 		./src/parsing/count_elements.c \
# 		./src/parsing/create_map_data.c \
# 		./src/parsing/find_door_at.c \
# 		./src/parsing/free_get_next_line.c \
# 		./src/parsing/ft_open.c \
# 		./src/parsing/get_init_position.c \
# 		./src/parsing/get_value_file.c \
# 		./src/parsing/get_value_map_data.c \
# 		./src/parsing/is_empty_line.c \
# 		./src/parsing/parsing.c \
# 		./src/parsing/print_map.c \
# 		./src/parsing/remove_new_line.c \
# 		./src/parsing/set_color.c \
# 		./src/parsing/set_color_or_texture.c \
# 		./src/parsing/set_texture.c \
# 		./src/parsing/size_map_data.c \
# 		./src/parsing/split_special.c \
# 		./src/raycasting/calculate_all_rays.c \
# 		./src/raycasting/calculate_ray_distance.c \
# 		./src/raycasting/check_hit_wall.c \
# 		./src/raycasting/finish_ray_casting.c \
# 		./src/raycasting/fix_fish_eye_effect.c \
# 		./src/raycasting/get_dist_wall.c \
# 		./src/raycasting/get_wall_percentage.c \
# 		./src/raycasting/handle_door_hit.c \
# 		./src/raycasting/init_raycasting.c \
# 		./src/raycasting/init_rays.c \
# 		./src/raycasting/print_single_ray_info.c \
# 		./src/raycasting/ray_hits_door.c \
# 		./src/raycasting/run_dda_loop.c \
# 		./src/raycasting/set_delt_dist.c \
# 		./src/raycasting/set_side_dist.c \
# 		./src/raycasting/set_step.c \
# 		./src/raycasting/step_and_set_side.c \
# 		./src/raycasting/type_wall.c \
# 		./src/raycasting/update_ray_hit_point.c \
# 		./src/raycasting/update_single_ray.c \
# 		./src/render/calc_texture_coor.c \
# 		./src/render/create_color_rgb.c \
# 		./src/render/draw_ceiling_floor.c \
# 		./src/render/draw_sky.c \
# 		./src/render/get_color_render3d.c \
# 		./src/render/render_3d_each_ray.c \
# 		./src/render/render_3d_scene.c \
# 		./src/render/render_frame.c \
# 		./src/render/render_ui.c \
# 		./src/render/render_ui_message.c \
# 		./src/render/show_welcome_img.c \
# 		./src/render/sprites/calc_tex_coor.c \
# 		./src/render/sprites/check_sprite_closer_wall.c \
# 		./src/render/sprites/find_all_types_sprites.c \
# 		./src/render/sprites/get_pos_render_sprites.c \
# 		./src/render/sprites/render_all_sprites.c \
# 		./src/render/sprites/render_sprite.c \
# 		./src/render/sprites/find_sprite_texture.c \
# 		./src/render/sprites/sort_sprite_by_distance.c \
# 		./src/render/sprites/sort_sprites.c \
# 		./src/render/sprites/sprit_put_color.c \
# 		./src/render/wall_shading/apply_distance_shadow.c \
# 		./src/setup/init_audio.c \
# 		./src/setup/init_default_map.c \
# 		./src/setup/init_default_player.c \
# 		./src/setup/init_doors.c \
# 		./src/setup/init_dt.c \
# 		./src/setup/init_grafic.c \
# 		./src/setup/init_keys.c \
# 		./src/setup/init_texture_sprites.c \
# 		./src/setup/init_value_map.c \
# 		./src/setup/load_messages.c \
# 		./src/setup/load_sky_image.c \
# 		./src/setup/load_sprites.c \
# 		./src/setup/load_sprite_texture.c \
# 		./src/setup/load_textures.c \
# 		./src/setup/precalculate_trig_tables.c \
# 		./src/setup/setup_img.c \
# 		./src/setup/setup_mlx_and_win.c \
# 		./src/setup/setup_view.c \
# 		./src/utils/clamp.c \
# 		./src/utils/deg_to_rad.c \
# 		./src/utils/error_messages2.c \
# 		./src/utils/error_messages.c \
# 		./src/utils/get_current_time_in_ms.c \
# 		./src/utils/min_max.c \
# 		./src/utils/print_separator.c \
# 		./src/utils/sign.c \
# 		./src/utils/size_array.c \
# 		./src/utils/swap.c \
# 		./src/utils/toggle_setting.c \
# 		./src/utils/update_max_value.c \
# 		./src/utils/x_y.c

# OBJECT FILES
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
OBJ_BONUS = $(patsubst $(SRC_DIR)/%, $(OBJ_DIR_BONUS)/%, $(SRC:.c=.o))

# MAKE RULES
# ------------------------------------------------------------------------------

# DEFAULT GOAL
.DEFAULT_GOAL := all

# ------------------------------------------------------------------------------

test: fclean bonus
	@if [ -f "${NAME_BONUS}" ]; then \
		echo "Running bonus: ${NAME_BONUS}"; \
		./${NAME_BONUS} ./maps/good/bonus1.cub; \
	else \
		echo "Running regular: ${NAME}"; \
		./${NAME} ./maps/good/creepy.cub; \
	fi

all: $(NAME) $(HEADER_FILE_M)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $@
	@echo "$(B_CYAN)✅ $@ successfully compiled.$(RST)"
	@echo "🚩 $(CYAN)Flags: \n$(CFLAGS)\n$(LDFLAGS)$(RST)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(CYAN)Compiling $<$(RST)"

-include $(DEPS)

# ------------------------------------------------------------------------------

bonus: $(LIBFT) $(NAME_BONUS) $(HEADER_FILE_B)

$(NAME_BONUS): $(OBJ_BONUS)
	@$(CC) $(CFLAGS) $(BONUSFLAGS) $(OBJ_BONUS) $(LDFLAGS) $(OS_FLAGS) -o $@
	@echo "$(B_MAGENTA)✅ $@ successfully compiled.$(RST)"
	@echo "🚩 $(MAGENTA)Bonus Flags:\n$(CFLAGS)\n$(LDFLAGS)\n$(BONUSFLAGS)$(RST)"

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(BONUSFLAGS) -c $< -o $@
	@echo "$(MAGENTA)Compiling $< (BONUS)$(RST)"

# ------------------------------------------------------------------------------

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR)

clean:
	@rm -rf $(OBJ_DIR) $(OBJ_DIR_BONUS) $(OBJ_DIR_DEV)
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@echo "$(B_YELLOW)🔥 Clean complete.$(RST)"

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	# @rm -f $(LIBFT)

re: fclean all

%:
	@echo "$(RED)Failure:$(RESET) target '$@' is not a valid target."
	@echo "Please use one of the following valid targets:"
	@echo "- $(GREEN)make$(RESET): compiles the project"
	@echo "- $(GREEN)make bonus$(RESET): compiles bonus part"
	@echo "- $(GREEN)make re$(RESET): recompiles the project"
	@echo "- $(GREEN)make clean$(RESET): removes object files"
	@echo "- $(GREEN)make fclean$(RESET): removes object files and the final binary"

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_DIR)

ubuntu:
	@echo Detected Ubuntu version: $(UBUNTU_VERSION)
	@echo Using OS tag: $(OS_VERSION_TAG)

# ------------------------------------------------------------------------------

.PHONY: all bonus clean fclean re minilibx ubuntu %
