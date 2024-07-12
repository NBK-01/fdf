L_SRC = ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove ft_memchr ft_memcmp ft_strlen ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp ft_strlcpy ft_strlcat ft_strnstr ft_atoi ft_calloc ft_strdup ft_substr ft_strjoin ft_strtrim ft_split ft_itoa ft_strmapi ft_striteri ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_putptr ft_putnbr_unsigned_fd

P_SRC = ft_printf ft_output_two ft_verify ft_output

G_SRC = get_next_line

L_SRCS = $(addprefix srcs/, $(addsuffix .c, $(L_SRC)))

P_SRCS = $(addprefix srcs/ft_printf/, $(addsuffix .c, $(P_SRC)))

G_SRCS = $(addprefix srcs/gnl/, $(addsuffix .c, $(G_SRC)))

HEAD = lib.h

SHELL := /bin/bash

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

L_OBJS = $(addprefix objs/, $(addsuffix .o, $(L_SRC)))

P_OBJS = $(addprefix objs/ft_printf/, $(addsuffix .o, $(P_SRC)))

G_OBJS = $(addprefix objs/gnl/, $(addsuffix .o, $(G_SRC)))

NAME = lib.a

CC = cc
RM = rm -f
AR = ar rc
RN = ranlib

CFLAGS = -Wall -Wextra -Werror

objs/%.o: srcs/%.c
	@mkdir -p $(dir $@)
	@${CC} ${CFLAGS} -c $< -o $@

objs/gnl/%.o: srcs/gnl/%.c
	@mkdir -p $(dir $@)
	@${CC} ${CFLAGS} -c $< -o $@
	@printf "%-53b%b" "$(COM_COLOR)COMPILING GNL:" "$(WARN_COLOR)[....]$(NO_COLOR)\n"


objs/ft_printf/%.o: srcs/ft_printf/%.c
	@mkdir -p $(dir $@)
	@${CC} ${CFLAGS} -c $< -o $@


${NAME}: ${L_OBJS} ${P_OBJS} ${G_OBJS}
	@${AR} ${NAME} ${P_OBJS} ${L_OBJS} ${G_OBJS}
	@${RN} ${NAME}
	@printf "%-53b%b" "$(COM_COLOR)COMPILING LIBFT:" "$(WARN_COLOR)[....]$(NO_COLOR)\n"
	@printf "%-53b%b" "$(COM_COLOR)COMPILING PRINTF:" "$(WARN_COLOR)[....]$(NO_COLOR)\n"

all: ${NAME}

clean:
	${RM} ${P_OBJS} ${L_OBJS} rm -rf objs/
	@printf "%-53b%b" "$(COM_COLOR)Cleaning object files:" "$(WARN_COLOR)[....]$(NO_COLOR)\n"

fclean: clean
	${RM} ${NAME}
		@printf "%-53b%b" "$(COM_COLOR)Deleting binary file:" "$(WARN_COLOR)[....]$(NO_COLOR)\n"

re: fclean all

.PHONY: all clean fclean re

.SILENT: all clean fclean re
