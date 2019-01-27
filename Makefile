NAME = ft_retro

SRC = Game.cpp \
	main.cpp \
	Player.cpp

all: $(NAME)

LIBS = -lncurses

FLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic-errors

$(NAME):
	# clang++ $(FLAGS) $(SRC) $(LIBS) -o $(NAME)
	clang++ $(SRC) $(LIBS) -o $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
