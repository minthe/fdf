SHELL	= /bin/sh

NAME =	fdf


OBJECTS = $(subst .c,.o,$(SOURCES))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

MINILIBX_DIR	= ./minilibx-linux
LIBFT_DIR		= ./libft
X11_INC			= /usr/X11/include
X11_LIB			= /usr/X11/lib

LFLAGS 			= -L${LIBFT_DIR} -L${MINILIBX_DIR} -L${X11_LIB} -lmlx -lXext -lX11 -lft -lm

IDIR			= .
IFLAGS			= -I${IDIR} -I${LIBFT_DIR} -I${MINILIBX_DIR} -I${X11_INC}

SRCS =	main.c \
		fdf.c \
		./functions/draw_line.c \
		./functions/count_lines.c \
		./functions/initialize_map.c \
		./gnl/get_next_line.c \
		./gnl/get_next_line_utils.c \


RM = rm -f

${NAME} : ${SRCS}
		@make -C ${LIBFT_DIR}
		@make -C ${MINILIBX_DIR}
		${CC} ${CFLAGS} ${SRCS} ${IFLAGS} ${LFLAGS} -o ${NAME}

all: ${NAME}

clean:
		@${RM} ${NAME}
		@make clean -C ${LIBFT_DIR}
		@make clean -C ${MINILIBX_DIR}

fclean: clean
		@make fclean -C ${LIBFT_DIR}

re: fclean all

.PHONY: all clean fclean re
