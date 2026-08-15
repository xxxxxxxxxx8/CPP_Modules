srcs	=	main.cpp #MutantStack.cpp
objs	=	$(addprefix objs/, $(srcs:.cpp=.o))
flags	=	-Wshadow  -Wall -Wextra -Werror -MMD \
			-I. -std=c++98 -g3 #-Wc++11-extensions
Name	=	Stack

all:	$(Name)

run:	all
	@if [ -f $(Name) ]; \
		then clear && /bin/bash -c './$(Name) "$$@"' __ "1" ; \
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