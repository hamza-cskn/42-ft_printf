SOURCES	= ${wildcard *.c}
OBJECTS	= ${SOURCES:.c=.o}
LIBFT_OBJECTS = libft/*.o

%.o: %.c
	gcc -Wall -Wextra -Werror -c $< -o $@ -I includes

libftprintf.a: ${OBJECTS} libft/libft.a
	ar -rc libftprintf.a ${OBJECTS} ${LIBFT_OBJECTS}

all: libftprintf.a

libft/libft.a:
	make -C libft

clean:
	rm -f ${OBJECTS}
	rm -f *.h.gch *.out
	make -C libft clean

fclean: clean
	rm -f libftprintf.a libft/libft.a

re: fclean all