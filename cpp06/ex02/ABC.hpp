#ifndef ABC_HPP
# define ABC_HPP

#include <Base.hpp>
#include <math.h>
#include <sstream>

typedef enum dx {
	DA,
	DB,
	DC
} DERIVED;

class A : public Base{

};

class B : public Base{

};

class C : public Base{

};

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif
