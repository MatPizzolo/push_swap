NAME = push_swap
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_LISTS_DIR = ./libft-lists
SRCS_DIR = ./srcs
HANDLE_ALGOS_DIR = ./handles-algorithms
HANDLE_MOREARGS_DIR = ./handle-more-args
RADIX_DIR = ./radix-sort
LIBFT_INC = $(LIBFT_DIR)/libft.h

SRCS = $(SRCS_DIR)/push_swap.c $(SRCS_DIR)/push_swap_algorithms.c $(SRCS_DIR)/push_swap_algorithms_two.c $(SRCS_DIR)/utils.c \
			$(HANDLE_ALGOS_DIR)/handle_two.c $(HANDLE_ALGOS_DIR)/handle_three.c $(HANDLE_ALGOS_DIR)/handle_fourfive.c $(HANDLE_ALGOS_DIR)/find_max_min.c \
			$(RADIX_DIR)/start.c $(RADIX_DIR)/to_positive.c  $(SRCS_DIR)/initialize_stack.c $(SRCS_DIR)/checks.c $(SRCS_DIR)/ft_atoi_err.c $(SRCS_DIR)/print_functions.c \

LIBTLISTS = $(LIBFT_LISTS_DIR)/ft_lstnew.c $(LIBFT_LISTS_DIR)/ft_lstadd_front.c $(LIBFT_LISTS_DIR)/ft_lstsize.c $(LIBFT_LISTS_DIR)/ft_lstlast.c \
				$(LIBFT_LISTS_DIR)/ft_lstadd_back.c $(LIBFT_LISTS_DIR)/ft_lstdelone.c $(LIBFT_LISTS_DIR)/ft_lstclear.c $(LIBFT_LISTS_DIR)/ft_lstiter.c \


OBJS = $(SRCS:.c=.o)
LIBTOBJS = $(LIBTLISTS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
#CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

# DEBUG_NAME = push_swap_debug 

# $(DEBUG_NAME): $(LIBTOBJS) $(LIBFT)
# 	$(CC) $(CFLAGS) -fdiagnostics-color=always -g -o $(DEBUG_NAME) $(SRCS) $(LIBTOBJS) -L$(LIBFT_DIR) -lft 

# debug: $(DEBUG_NAME)

all: $(NAME)

$(NAME): $(OBJS) $(LIBTOBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBTOBJS) -L$(LIBFT_DIR) -lft

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c $(LIBFT_INC)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(OBJS) $(LIBTLISTS:.c=.o) 
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
