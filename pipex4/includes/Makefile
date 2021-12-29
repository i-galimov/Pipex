NAME 	        = libft_gnl.a
SRC_PATH 		= libft
GNL_PATH 		= gnl
INCLUDES		= includes

SRCS			=	$(SRC_PATH)/ft_isspace.c \
            		$(SRC_PATH)/ft_isdigit.c \
            		$(SRC_PATH)/ft_bzero.c \
            		$(SRC_PATH)/ft_strdup.c \
            		$(SRC_PATH)/ft_strndup.c \
					$(SRC_PATH)/ft_memdel.c \
            		$(SRC_PATH)/ft_memset.c \
	           		$(SRC_PATH)/ft_memcpy.c \
 					$(SRC_PATH)/ft_strlen.c \
 					$(SRC_PATH)/ft_strlcpy.c \
 					$(SRC_PATH)/ft_strlcat.c \
 					$(SRC_PATH)/ft_strcpy.c \
 					$(SRC_PATH)/ft_strcat.c \
 					$(SRC_PATH)/ft_strncpy.c \
 					$(SRC_PATH)/ft_strncat.c \
					$(SRC_PATH)/ft_substr.c \
					$(SRC_PATH)/ft_strjoin.c \
					$(SRC_PATH)/ft_strstr.c \
					$(SRC_PATH)/ft_strnstr.c \
					$(SRC_PATH)/ft_strdel.c \
					$(SRC_PATH)/ft_split.c \
					$(SRC_PATH)/ft_strchr.c \
					$(SRC_PATH)/ft_strrchr.c \
					$(SRC_PATH)/ft_strcmp.c \
					$(SRC_PATH)/ft_strncmp.c \
					$(SRC_PATH)/ft_putchar_fd.c \
					$(SRC_PATH)/ft_putnbr_fd.c \
					$(SRC_PATH)/ft_putstr_fd.c \
					$(SRC_PATH)/ft_putendl_fd.c \
					$(GNL_PATH)/get_next_line_utils.c \
					$(GNL_PATH)/get_next_line.c

OBJS	= $(SRCS:.c=.o)

HEADER 			= -I../$(INCLUDES)/libft.h -I../$(INCLUDES)/get_next_line.h

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror
OPTIM_FLAGS = -O2

LIBS = $(INCLUDES)/libft.h $(INCLUDES)/get_next_line.h

AR = ar rcs
RM = rm -f

.PHONY: 	all clean fclean re .c.o

all: $(NAME)

$(NAME) : $(OBJS) $(LIBS)
	$(AR) $(NAME) $^

.c.o:		
			${CC} ${CFLAGS} ${OPTIM_FLAGS} $(HEADER) -c $< -o ${<:.c=.o}

all:		${NAME}

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}	

re:			fclean all
