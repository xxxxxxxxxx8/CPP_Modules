
#include <Cat.hpp>
#include <Dog.hpp>

int main()
{
	Animal *arr[2];

	arr[0] = new Dog();
	arr[1] = new Cat();

	for (int i(0); i < 2; i++) {
		delete arr[i];
	}

	Animal* j = new Dog();
	Animal* i = new Cat();
	Animal* k = new Cat();

	Cat		t1;
	Cat		t2(t1);
	std::cout <<k->getType()<<'\n';
	*i = *k;
	delete j;
	delete i;
	delete k;

	return 0;
}
