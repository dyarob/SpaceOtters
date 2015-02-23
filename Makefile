CC          = /usr/bin/g++

NAME        = ft_retro

SRCDIR      = ./src/

SRC         =	AGameObject.class.cpp		\
				AsteroidField.class.cpp		\
				AUnit.class.cpp				\
				Block.class.cpp				\
				BlockBase.class.cpp			\
				EnemyBase.class.cpp			\
				Game.class.cpp				\
				Level.class.cpp				\
				main.cpp					\
				objchain.class.cpp		\
				objlist.class.cpp			\
				Player.class.cpp			\
				Projectile.class.cpp		\
				ProjectileBase.class.cpp	\
				ProjectileEnemy.class.cpp	\
				Skin.class.cpp				\
				Spawner.class.cpp			\
				Timer.class.cpp				\
				vector2.class.cpp			\
				Weapon.class.cpp			\
				WeaponBase.class.cpp		\
				WeaponEnemy.class.cpp		\
				WinUI_dialogBox.class.cpp	\
				WinUI_screen.class.cpp		\
				WinUI.class.cpp				\


OBJ         = $(SRC:.cpp=.o)

HDFLAGS     = -I./includes/

LDFLAGS     = -lncurses

CFLAGS      = $(HDFLAGS) -Wall -Werror -Wextra -ansi -pedantic -g \
							-std=c++11	# for <thread> in main.cpp on arch-linux

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

EDITOR_SRC   =	\
				Asciimg.class.cpp			\
				editor_img.cpp				\
				Skin.class.cpp				\
				WinUI_dialogBox.class.cpp	\
				WinUI.class.cpp				\
				WinColor.class.cpp			\

e:
	rm -f editor
	g++ -Wall -Wextra -Werror -g $(EDITOR_SRC) -lncurses -o editor

.PHONY:     all clean re fclean
