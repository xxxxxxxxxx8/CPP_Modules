srcs	=	AMateria.cpp  Character.cpp  Cure.cpp  Ice.cpp \
			ICharacter.cpp IMateriaSource.cpp MateriaSource.cpp\
			main.cpp Exiter.cpp
objs	=	$(addprefix objs/, $(srcs:.cpp=.o))
flags	=	-Wshadow  -Wall -Wextra -Werror -MMD -Iincs -std=c++98 -g3
Name	=	Polymorphism4

all:	$(Name)

run:	all
	@if [ -f $(Name) ]; \
		then /bin/bash -c ./$(Name); \
	fi

$(Name): $(objs)
	c++ $(flags) $^ -o $@

objs/%.o:	%.cpp
	mkdir -p objs/
	c++ -c $(flags) $< -o $@

clean:
	rm -rf objs
	
fclean: clean
	rm -f $(Name)

re: fclean all

.PHONY: clean

-include $(objs:.o=.d)