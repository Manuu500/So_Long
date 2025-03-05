NAME = so_long.a

# Archivos fuente
SRCS = so_long.c

FLAGS = -Wall -Wextra -g -Werror

CC = cc

CLEAN = rm -rf

INCLUDES = -I/usr/include -Imlx

MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

# CLEAN = del /Q /F

OBJ := $(SRCS:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(OBJ): $(SRCS)
	$(CC) -g $(FLAGS) -c $(SRCS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

# $(NAME): $(OBJ)
# 	ar -rsc $(NAME) $(OBJ)

clean:
	@$(CLEAN) *.o

fclean: clean
	@$(CLEAN) *.a

re: fclean all

.PHONY: all clean fclean re bonus