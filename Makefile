NAME		=	cub3D

SRC_DIR		=	src/
OBJ_DIR		=	obj/

HEADERS 	=	-Iinclude -I$(LIBMLX42DIR)/include

LIBFT_DIR	=	libft
LIBFT		=	$(LIBFT_DIR)/libft.a

LIBMLX42DIR	=	MLX42
LIBMLX42	=	$(LIBMLX42DIR)/build/libmlx42.a

SRC_MAIN	=	main.c move_keyhooks.c \
	rotate_keyhooks.c mapinfo_from_path.c \
	draw_cf_sys.c minimap_sys.c misc_keyhooks.c \
	movement_sys.c raycast_sys.c resize_sys.c \
	utils.c utils2.c

SRC_HASHTABLE	=	hashtable/hash_node_destroy.c \
	hashtable/hashtable_destroy.c hashtable/hashtable_init.c \
	hashtable/hashtable_insert.c hashtable/hashtable_new.c \
	hashtable/hashtable_search.c

SRC_QUEUE		=	queue/queue_destroy.c queue/queue_init.c \
	queue/queue_enqueue.c queue/queue_dequeue.c queue/queue_peek.c \
	queue/queue_isempty.c queue/queue_isfull.c

SRC_VECTOR		=	vector/vec2_add.c vector/vec2_sub.c vector/vec2_scale.c \
	vector/vec2_dot.c vector/vec2_cross.c vector/vec2_magnitude.c \
	vector/vec2_normalize.c vector/vec2.c vector/vec2_distance.c \
	vector/vec2_rotate.c vector/vec2_length.c

SRC_SYSMANAGER	=	sysmanager/sysmanager_add.c \
	sysmanager/sysmanager_init.c sysmanager/sysmanager_run.c \
	sysmanager/sysmanager_add_event.c

SRC_STORAGE		=	storage/storage_destroy.c storage/storage_init.c \
	storage/storage_add.c storage/storage_get.c storage/source_destroy.c

SRC_APP			=	app/app_destroy.c app/app_init.c \
	app/app_run.c app/app_system_add.c app/app_source_add.c \
	app/app_source_get.c app/app_set_hooks.c app/app_keyhook_add.c \
	app/app_event_add.c app/app_get.c app/app_set_cursor_mode.c \
	app/image_destroy.c app/app_image_new.c app/app_image_from_texture.c \
	app/app_image_to_window.c


SRC_MAPINFO		=	mapinfo/map_destroy.c mapinfo/map_init.c \
	mapinfo/map_new.c mapinfo/map_get.c mapinfo/mapinfo_init.c \
	mapinfo/mapinfo_parse_from_str.c mapinfo/mapinfo_destroy.c \
	mapinfo/mapinfo_parse_path.c mapinfo/mapinfo_parse_color.c \
	mapinfo/mapinfo_parse_map.c mapinfo/map_set.c \
	mapinfo/mapinfo_perror.c mapinfo/mapinfo_validate.c \
	mapinfo/flood_fill.c mapinfo/mapinfo_extract.c \
	mapinfo/mapinfo_new.c

SRC_CAMERA		=	camera/camera_destroy.c camera/camera_init.c \
	camera/camera_move.c camera/camera_new.c camera/camera_rotate.c \
	camera/camera_set_aspect_ratio.c camera/camera_set_position.c

SRC_DDA_RAYCAST	=	dda_raycast/camera_ray_gen.c \
	dda_raycast/dda_ray_cast.c dda_raycast/get_hit_point.c

SOURCES			=	$(SRC_MAIN) $(SRC_HASHTABLE) $(SRC_QUEUE) \
	$(SRC_SYSMANAGER) $(SRC_STORAGE) $(SRC_APP) $(SRC_MAPINFO) \
	$(SRC_VECTOR) $(SRC_CAMERA) $(SRC_DDA_RAYCAST)

OBJS	=	$(SOURCES:%.c=$(OBJ_DIR)%.o)
DEP		=	$(OBJS:.o=.d)

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -Iincludes -MMD
CFLAGS_DEBUG	=	-g3 -fsanitize=address,undefined,leak -fno-omit-frame-pointer
CFLAGS_RELEASE	=	-Ofast

LFLAGS	=	$(LIBFT) $(LIBMLX42) -ldl -lglfw -pthread -lm

all: release

debug: CFLAGS += $(CFLAGS_DEBUG)
debug: $(NAME)

release: CFLAGS += $(CFLAGS_RELEASE)
release: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(LIBMLX42)
	$(CC) $(OBJS) $(CFLAGS) $(LFLAGS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(LIBMLX42):
	@cmake $(LIBMLX42DIR) -B $(LIBMLX42DIR)/build && make -C $(LIBMLX42DIR)/build -j4

re: fclean all

clean:
	@rm	-rf	$(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm	-f  $(NAME)
	@rm -rf $(LIBMLX42DIR)/build
	@make -C $(LIBFT_DIR) fclean

-include $(DEP)

.PHONY: all debug release re clean fclean
