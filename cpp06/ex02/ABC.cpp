#include  <ABC.hpp>

Base*	generate(void) {
	srand(time(0));

	 switch (rand() % 3) {
		case DA:
			return new A();
		case DB:
			return new B();
		case DC:
			return new C();

	 }
	 return NULL;
}

void	identify(Base* p) {
	A*	pA;	B*	pB; C*	pC;

	pA = dynamic_cast<A*>(p);
	pB = dynamic_cast<B*>(p);
	pC = dynamic_cast<C*>(p);
	switch (reinterpret_cast<uintptr_t>(pA)) {
		case 0:
			break ;
		default:
			std::cout << "A" << std::endl;
			return ;
	}
	switch (reinterpret_cast<uintptr_t>(pB)) {
		case 0:
			break ;
		default:
			std::cout << "B" << std::endl;
			return ;
	}
	switch (reinterpret_cast<uintptr_t>(pC)) {
		case 0:
			break ;
		default:
			std::cout << "C" << std::endl;
			return ;
	}
	std::cout << "unknown pointer!!!" << std::endl;
}

void	identify(Base& p) {

	try {
		A&	pA = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		pA.~A();	return ;
	} catch (const std::exception& exp) {

	} try {
		B&	pB = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		pB.~B();	return ;
	} catch (const std::exception& exp) {

	} try {
		C&	pC = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		pC.~C();	return ;
	} catch (const std::exception& exp) {
		std::cout << "unknown reference!!!" << std::endl;
	}
}
