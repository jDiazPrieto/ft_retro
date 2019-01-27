CPP		= clang++
FLAGS	= -Wextra -Wall -Werror
NAME	= ft_retro

SRCDIR = ./srcs/
INCDIR = ./includes/
OBJDIR = ./obj/

SRCS_FILES		= main.cpp Board.cpp Display.cpp Enemy.cpp GameObject.cpp \
				Player.cpp Shoot.cpp
HDRS_FILES		= Board.hpp Display.hpp DisplayList.hpp Enemy.hpp \
				GameObject.hpp Player.hpp Shoot.hpp
OBJS_FILES		= $(SRCS_FILES:.cpp=.o)

SRCS	= $(addprefix $(SRCDIR), $(SRC_FILES))
HEADERS	= $(addprefix $(INCDIR), $(HEADERS_FILES))
OBJS	= $(addprefix $(OBJDIR), $(OBJS_FILES))

all: $(NAME)

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.cpp
	$(CPP) $(FLAGS) -o $@ -c $< -I $(INCDIR)

$(NAME): $(OBJS) $(HEADERS)
	$(CPP) $(FLAGS) $(OBJS) -o $@ -lncurses

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
