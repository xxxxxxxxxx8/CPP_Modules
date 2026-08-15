srcs	=	megaphone.cpp
objs	=	$(srcs:.cpp=.o)
flags	=	-Wshadow -Wall -Wextra -Werror -std=c++98
Name	=	megaphone

all:	$(Name)

$(Name): $(objs)
	c++ $(flags) $^ -o $@

%.o:	%.cpp
	c++ -c $(flags) $< -o $@ -MMD

clean:
	rm -f $(objs)
	rm -f $(objs:.o=.d)

fclean: clean
	rm -f $(Name)

re: fclean all

.PHONY: clean

-include $(objs:.o=.d)