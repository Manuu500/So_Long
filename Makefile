NAME	:= so_long

CC = cc
CFLAGS	:= -Wextra -Wall -Werror -fsanitize=address -g

LIBMLX	:= ./libs/MLX42
LIBFT	:= ./libs/libft

HEADERS	:=	-I ./inc \
			-I $(LIBMLX)/include \
			-I $(LIBFT)

LIBS	:=	$(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm -fsanitize=address\
			$(LIBFT)/libft.a 

SRC :=	src/main.c \
		src/hooks.c \
		src/image.c \
		src/movement.c \
		src/map.c \
		src/utils.c \
		src/coins.c \
		src/error_handle.c \
		src/check_map.c \
		src/free.c \

OBJ	= $(patsubst src%, obj%, $(SRC:.c=.o))

all: libmlx libft obj $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@make -C libs/libft all

$(NAME): $(OBJ)
	@echo "compiling ${NAME}"
	@$(CC) $(OBJ) $(LIBS) $(HEADERS) -o $(NAME)

bonus: libmlx libft obj ${B_OBJ}
	@$(CC) $(B_OBJ) $(LIBS) $(HEADERS) -o $(NAME) && printf "Compiling ${NAME} with bonus"

obj/%.o: src/%.c
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@ && printf "Compiling: $(notdir $<)\n"

obj/%.o: bonus/%.c
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@ && printf "Compiling: $(notdir $<)\n"

obj:
	@mkdir -p obj

clean:
	@rm -rf obj
	@make -C libs/libft clean
	@rm -rf $(LIBMLX)/build

fclean: clean
	@make -C libs/libft fclean
	@rm -f $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx, libft, obj