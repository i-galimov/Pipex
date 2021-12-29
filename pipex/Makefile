NAME			= pipex

LIBFT_PATH		= includes
LIBFT 			= $(LIBFT_PATH)/libft_gnl.a
LIBFT_MAKE		= ${MAKE} -C ${LIBFT_PATH}

SRC_PATH 		= src

CMN 			= $(SRC_PATH)/error_handler.c \
				  $(SRC_PATH)/executer.c \
				  $(SRC_PATH)/filer.c \
				  $(SRC_PATH)/path_parser.c \
				  $(SRC_PATH)/cmd_parser.c \
				  $(SRC_PATH)/free_tab.c \
				  $(SRC_PATH)/piper.c \
				  $(SRC_PATH)/pipex_bonus.c

SRCS			= pipex.c

CMN_OBJS		= $(CMN:.c=.o)
OBJS			= $(SRCS:.c=.o)

CC				= gcc
HEADER 			= -I ../includes/pipex.h
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f

.PHONY: 		all clean fclean re

%.o:			%.c $(HEADER) Makefile
				${CC} $(CFLAGS) -c -I $(HEADER) $< -o $(<:.c=.o) 
			
${NAME}:		${CMN_OBJS} ${OBJS} 
				${LIBFT_MAKE}
				${CC} ${CFLAGS} ${CMN_OBJS} ${OBJS} $(HEADER) ${LIBFT} -o ${NAME}

all:			${NAME}

clean:		
				$(LIBFT_MAKE) clean
				${RM} ${CMN_OBJS} ${OBJS} $(BONUS_OBJS) $(LIBFT)

fclean:			clean
				$(LIBFT_MAKE) fclean
				${RM} ${NAME}	

re:				fclean all
