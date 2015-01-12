CC          = /usr/bin/g++

NAME        = ft_retro

SRCDIR      = ./src/

SRC         =	AGameObject.class.cpp		\
				AsteroidField.class.cpp		\
				main.cpp					\
				Block.class.cpp				\
				BlockBase.class.cpp			\
				Level.class.cpp				\
				Vector2D.class.cpp			\
				Weapon.class.cpp			\
				WeaponBase.class.cpp		\
				WeaponEnemy.class.cpp		\
				Projectile.class.cpp		\
				ProjectileBase.class.cpp	\
				ProjectileEnemy.class.cpp	\
				Skin.class.cpp				\
				Player.class.cpp			\
				EnemyBase.class.cpp			\
				DelayEvent.class.cpp		\
				AUnit.class.cpp				\
				WinUI_dialogBox.class.cpp	\
				WinUI_screen.class.cpp		\
				WinUI.class.cpp				\
				List.struct.cpp				\
				Timer.class.cpp				\
				DelayEvent.class.cpp		

OBJ         = $(SRC:.cpp=.o)

HDFLAGS     = -I./includes/

LDFLAGS     = -lncurses

CFLAGS      = $(HDFLAGS) -Wall -Werror -Wextra -ansi -pedantic -g

RM          = rm -rf

all:        $(NAME)

$(NAME):    $(OBJ)
			@echo "\033[1;32m[Linking] \t\033[0m: \033[0;32m" | tr -d '\n'
			$(CC) -o $@ $^ $(LDFLAGS) 
			@echo "\033[0m" | tr -d '\n'

clean:
			@echo "\033[1;33m[Cleaning] \t\033[0m: \033[0;31m" | tr -d '\n'
			$(RM) $(OBJ)
			@echo "\033[0m" | tr -d '\n'

fclean:     clean
			@echo "\033[1;31m[Fcleaning] \t\033[0m: \033[0;31m" | tr -d '\n'
			$(RM) $(NAME)
			@echo "\033[0m" | tr -d '\n'

re:         fclean all

%.o:        %.cpp
			@echo "\033[1;36m[Compiling] \t\033[0m: \033[1;37m" | tr -d '\n'
			$(CC) $(CFLAGS) -c $< -o $@
			@echo "\033[0m" | tr -d '\n'

.PHONY:     all clean re fclean

				# $(SRCDIR)main.cpp			\
				# DelayEvent.class.cpp		\
				# Event.class.cpp
