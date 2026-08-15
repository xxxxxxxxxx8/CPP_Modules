srcs	=	main.cpp Bureaucrat.cpp AForm.cpp \
			ShrubberyCreationForm.cpp RobotomyRequestForm.cpp \
			PresidentialPardonForm.cpp Intern.cpp
objs	=	$(addprefix objs/, $(srcs:.cpp=.o))
flags	=	-Wshadow  -Wall -Wextra -Werror -MMD -I. -std=c++98 -g3
Name	=	AForm

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
	rm -rf $(shell ls | grep _shrubbery)
	
fclean: clean
	rm -f $(Name)

re: fclean all

.PHONY: clean

-include $(objs:.o=.d)