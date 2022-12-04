NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c\
ft_printf_utils.c

OBJ = $(SRC:.c=.o)

#SRCB = 

#OBJB =$(SRCB:.c=.o)







all : $(NAME)

$(NAME) : $(OBJ) ft_printf.h
	ar rcs $(NAME) $(OBJ)

#bonus : $(OBJ) $(OBJB)
#	ar rcs $(NAME) $(OBJ) $(OBJB)

%.o : %.c
	$(CC) $(CFLAGS) -c $^

clean :
	rm -f $(OBJ) $(OBJB)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
