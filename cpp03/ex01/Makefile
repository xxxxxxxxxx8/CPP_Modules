srcs	=	main.cpp ClapTrap.cpp ScavTrap.cpp
objs	=	$(addprefix objs/, $(srcs:.cpp=.o))
flags	=	-Wshadow -Wall -Wextra -Werror -MMD -I. -std=c++98 -g3
Name	=	ScavTrap

all:	$(Name)

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