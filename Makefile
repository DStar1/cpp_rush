NAME = ft_retro

SRC = *.cpp

all: $(NAME)

LIBS = -lncurses

FLAGS = -Wall -Werror -Wextra

$(NAME):
	# clang++ $(FLAGS) $(SRC) $(LIBS) -o $(NAME)
	clang++ $(SRC) $(LIBS) -o $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all