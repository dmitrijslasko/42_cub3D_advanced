include config.mk

# Library name
NAME = libft.a

AR = ar
CFLAGS = -Wall -Wextra -Werror -fPIC

INC = ./inc

SRC_DIR = ./src/
OBJ_DIR = ./obj/

SRC = $(wildcard $(SRC_DIR)*.c) $(wildcard $(SRC_DIR)**/*.c)
OBJ = $(patsubst $(SRC_DIR)%, $(OBJ_DIR)%, $(SRC:.c=.o))

#SRC = \
#	ft_isalpha.c \
#	ft_isdigit.c \
#	ft_isalnum.c \
#	ft_isascii.c \
#	ft_isprint.c \
#	ft_strlen.c \
#	ft_memset.c \
#	ft_bzero.c \
#	ft_memcpy.c \
#	ft_memmove.c \
#	ft_strlcpy.c \
#	ft_strlcat.c \
#	ft_toupper.c \
#	ft_tolower.c \
#	ft_strchr.c \
#	ft_strrchr.c \
#	ft_strncmp.c \s
#	ft_memchr.c \
#	ft_calloc.c \
#	ft_strdup.c \
#	ft_substr.c \s
#	ft_memcmp.c \
#	ft_strnstr.c \
#	ft_atoi.c \
#	ft_strjoin.c \
#	ft_strtrim.c \
#	ft_split.c \
#	ft_itoa.c \
#	ft_strmapi.c \
#	ft_striteri.c \
#	ft_putchar_fd.c \
#	ft_putstr_fd.c \
#	ft_putendl_fd.c \
#	ft_putnbr_fd.c \
#	ft_lstadd_front.c \
#	ft_lstsize.c \
#	ft_lstlast.c \
#	ft_lstnew.c \
#	ft_lstadd_back.c \
#	ft_lstdelone.c \
#	ft_lstclear.c \
#	ft_lstiter.c \
#	ft_lstmap->c

.DEFAULT_GOAL := all

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) rcs $(NAME) $(OBJ)
	@echo "$(B_GREEN)✅ $(NAME) got successfully compiled.\n$(RST)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@echo "$(GREEN)Compiling $<$(RST)"
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

clean:
	@rm -f $(OBJ_DIR)**/*.o
	@rm -rf $(OBJ_DIR)
	@echo "$(B_YELLOW)🔥 libft - clean complete!$(RST)"

fclean: clean
	@rm -f $(NAME) $(HEADER_FILE)
	@rm -rf ./logs/

re: fclean all

.PHONY: all clean fclean re
