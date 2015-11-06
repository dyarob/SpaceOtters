CC          = /usr/bin/g++
NAME        = spaceotters
SRC         =	\
			data.cpp	\
			display.cpp	\
			Game.class.cpp	\
			main.cpp	\
			Timer.class.cpp	\

OBJDIR			= ./obj/
OBJ         = $(addprefix $(OBJDIR), $(SRC:.cpp=.o))
HDFLAGS     = -I./includes/ -I../boost_1_59_0/
LDFLAGS     = -lncurses
CFLAGS      =	\
			$(HDFLAGS) -Wall -Werror -Wextra -ansi -pedantic -g \
			-std=c++11	# for <thread> in main.cpp on arch-linux
RM          = rm -rf

all:        $(NAME)

$(NAME):    $(OBJ)
			@echo "\033[1;32m[Linking] \t\033[0m: \033[0;32m" | tr -d '\n'
			$(CC) -o $@ $^ $(LDFLAGS) 
			@echo "\033[0m" | tr -d '\n'
$(addprefix $(OBJDIR), %.o):        %.cpp
			@echo "\033[1;36m[Compiling] \t\033[0m: \033[1;37m" | tr -d '\n'
			$(CC) $(CFLAGS) -c $< -o $@
			@echo "\033[0m" | tr -d '\n'
re:         fclean all

.PHONY:     all clean re fclean

clean:
			@echo "\033[1;33m[Cleaning] \t\033[0m: \033[0;31m" | tr -d '\n'
			$(RM) $(OBJ)
			@echo "\033[0m" | tr -d '\n'
fclean:     clean
			@echo "\033[1;31m[Fcleaning] \t\033[0m: \033[0;31m" | tr -d '\n'
			$(RM) $(NAME)
			@echo "\033[0m" | tr -d '\n'
