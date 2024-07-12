NAME	=	fdf

CC	=	gcc

AUTHOR 	=	nkanaan

FLAGS	=	-Wall -Wextra -Werror

MLX	=	mlx/Makefile.gen

LFT	=	lib/lib.a

INC	=	-I ./includes -I ./mlx

LIB	=	-L ./mlx -lmlx -lXext -lX11 -lm -lbsd

SRCS	= 	main parse validation map init mlx_hooks

SRC 	=	$(addprefix src/, $(addsuffix .c, $(SRCS)))

SHELL	:=	/bin/bash

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

OBJS = $(addprefix objs/, $(addsuffix .o, $(SRCS)))

all:	header $(MLX) $(LFT) $(NAME)

header:
	@printf "%b" "$(OK_COLOR)"
	@echo ".------..------."
	@echo "|4.--. ||2.--. |"
	@echo "| :/\: || (\/) |"
	@echo "| :\/: || :\/: |"
	@echo "| '--'4|| '--'2|"
	@echo "'------''------'"
	@echo "NKANAAN"

	@printf "%b" "$(OBJ_COLOR)Flags: 	$(WARN_COLOR)$(FLAGS)\n\033[m"
	@echo


objs/%.o:	src/%.c
			@mkdir -p $(dir $@)
			@${CC} ${FLAGS} $(INC) -c $< -o $@


$(NAME):	$(OBJS) $(LFT)
			@$(CC) $(FLAGS) -o $@ $^ $(LIB)
		@echo " [ OK ] Project Compiled "


$(LFT):		
			@echo " [ .. ] | Compiling libft.."
			@make -s -C lib
			@echo " [ OK ] | Libft ready!"

$(MLX):
			@echo " [ .. ] | Compiling minilibx.."
			@make -s -C mlx
			@echo " [ OK ] | Minilibx ready!"

clean:
			rm -rf $(OBJS) ./objs
			@make clean -C ./lib
			@printf "%-53b%b" "$(COM_COLOR)OBJECT FILES DELETED:" "$(ERROR_COLOR)[✓]$(NO_COLOR)\n"


fclean:		clean
				rm $(NAME)
				rm ./lib/lib.a
				@printf "%-53b%b" "$(COM_COLOR)ALL CLEAN:" "$(ERROR_COLOR)[✓]$(NO_COLOR)\n"

re:			fclean all

.PHONY: 	all clean fclean re

.SILENT: 	clean fclean re all
