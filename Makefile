CPP        = clang++
FLAGS    = -Wextra -Wall -Werror
NAME    = ft_retro

SRC        = srcs/$(wildcard *.cpp)
HEADERS    = includes/$(wildcard *.hpp)
OBJS    = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
    $(CPP) $(FLAGS) $(OBJS) -lncurses -o $(NAME)

clean:
    /bin/rm -f *.o

fclean: clean
    /bin/rm -f $(NAME)

re: fclean all
