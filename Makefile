NAME = queens

FILE = *.c
CFLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -pthread $(FILE) $(CFLAG) -o $(NAME)

clean:
	rm -f *.txt

fclean: clean
	rm -f $(NAME)

.SILENT: clean fclean $(NAME)
re: fclean all
