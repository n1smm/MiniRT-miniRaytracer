CC = cc
CFLAGS = -Wall -Wextra -Werror -Llibft -lft -Lminilibx-linux -lml -lXext -lX11 -lm

NAME = minirt.a
HEADER = includes/minirt.h

SRC_DIR = srcs
OBJ_DIR = objs
GEO_DIR = $(SRC_DIR)/objects
INIT_DIR = $(SRC_DIR)/inits
GNL_DIR = $(SRC_DIR)/get_line
LIGHT_DIR = $(SRC_DIR)/light
GEOMETRY = $(wildcard $(GEO_DIR)/*.c)
INITS = $(wildcard $(INIT_DIR)/*.c)
GNL = $(wildcard $(GNL_DIR)/*.c)
LIGHT = $(wildcard $(LIGHT_DIR)/*.c)
FILES_SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/manage_win.c $(SRC_DIR)/clean.c \
			 $(SRC_DIR)/parsing.c $(SRC_DIR)/split.c $(SRC_DIR)/safe_ft.c \
			 $(SRC_DIR)/safe_ft2.c \
			 $(SRC_DIR)/parsing_utils.c \
			 $(SRC_DIR)/color_creation.c $(SRC_DIR)/color.c \
			 $(SRC_DIR)/color_utils.c \
			 $(SRC_DIR)/vector_utils.c \
			 $(SRC_DIR)/vector_utils3.c \
			 $(SRC_DIR)/math_utils.c \
			 $(SRC_DIR)/math_utils2.c $(SRC_DIR)/vector_utils2.c \
			 $(SRC_DIR)/render.c \
			 $(SRC_DIR)/debug_utils.c $(SRC_DIR)/free_functions.c \
			 $(SRC_DIR)/debug_utils2.c $(SRC_DIR)/debug_utils3.c \
			 $(SRC_DIR)/bonus_checker.c \
			 $(SRC_DIR)/camera_rays.c \
			 $(GEOMETRY) $(INITS) $(GNL) $(LIGHT)

FILES_OBJS = $(FILES_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)


EXECUTABLE = miniRT

MLX_PATH	= minilibx-linux/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

LIBFT_PATH	= libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

all: $(MLX) $(LIBFT) $(NAME) $(EXECUTABLE)

$(LIBFT):
	@make -sC libft/

$(MLX):
	@make -sC minilibx-linux/

$(NAME): $(FILES_OBJS)
		ar rc $(NAME) $(FILES_OBJS)
		ranlib $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(GEOMETRY) $(INITS) $(GNL) $(HEADER)
		# @mkdir -p $(OBJ_DIR)
		# @mkdir -p $(GEO_DIR)
		# @mkdir -p $(INIT_DIR)
		# @mkdir -p $(GNL_DIR)
		@mkdir -p $(dir $@)
		$(CC)  -c $< -o $@

$(EXECUTABLE): $(FILES_OBJS)
		$(CC) -o $(EXECUTABLE) $(FILES_OBJS) -Llibft -lft -Lminilibx-linux -lmlx -lXext -lX11 -lm

clean:
		rm -f $(FILES_OBJS)
		make -C $(LIBFT_PATH) clean
		make -C $(MLX_PATH) clean

fclean: clean
		rm -f $(NAME) $(EXECUTABLE)
		rm -rf $(OBJ_DIR)
		make -C $(LIBFT_PATH) fclean

re: fclean all
