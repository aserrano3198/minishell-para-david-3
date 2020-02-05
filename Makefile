# --------------------Rutas----------------------------#

SRCS_PATH = srcs/

OBJS_PATH = objs/

INCLUDES_PATH = includes/

LIBFT_PATH = srcs/libft

#--------------------Recursos---------------------------#

SRCS =	main_shell.c parse_commands.c launch_cmd.c execute.c \
		errors.c builtin_exit.c builtin_cd.c display_prompt.c \
		builtin_env.c builtin_echo.c builtin_pwd.c builtin_export.c \
		builtin_unset.c

INCLUDES = minishell.h

NAME = minishell

LIB_LIBFT = libft.a

#--------------------Comandos---------------------------#

GCC = gcc -Wall -Werror -Wextra

FLAGS = -L ${LIBFT_PATH} -lft

CREATEMKDIR = @mkdir -p objs

OBJS = ${addprefix ${SRCS_PATH}, ${SRCS:.c=.o}}

RM = rm -f

#---------------------Ordenes---------------------------#

.c.o:
			${CREATEMKDIR}
			${GCC} -c $< -o ${addprefix ${OBJS_PATH}, ${notdir ${<:.c=.o}}}

$(NAME):	${OBJS} ${addprefix ${INCLUDES_PATH}, ${INCLUDE}}
			make -C ${LIBFT_PATH}
			${GCC} ${addprefix ${OBJS_PATH}, ${notdir ${OBJS}}} ${FLAGS} -o ${NAME}

all:		$(NAME)

re:			fclean all

clean:
			${RM} ${addprefix ${OBJS_PATH}, ${notdir ${OBJS}}}

fclean:
			${RM} ${NAME}