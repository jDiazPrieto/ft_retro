CPP		= clang++
FLAGS	= -Wextra -Wall -Werror
NAME	= fixed

SRC		= $(wildcard *.cpp)
HEADERS	= $(wildcard *.hpp)
OBJS	= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(CPP) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
