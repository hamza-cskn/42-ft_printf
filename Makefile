sources	= ${wildcard *.c}
objects	= ${sources:.c=.o}

%.o: %.c
	gcc -Wall -Wextra -Werror -c $< -o $@ -I includes

libftprintf.a: ${objects}
	ar -rc libft.a ${objects}

all: libftprintf.a

clean:
	rm -f ${objects}

fclean: clean
	rm -f libftprintf.a

re: clean all

