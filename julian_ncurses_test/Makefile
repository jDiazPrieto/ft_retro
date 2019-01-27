NAME = ft_retro

SRC = ncurses.cpp

all: $(NAME)

$(NAME): $(SRC)
	clang++ -lncurses $(SRC) -o $(NAME)

clean: 
	/bin/rm -rf $(NAME)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
