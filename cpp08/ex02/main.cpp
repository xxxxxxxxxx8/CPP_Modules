#include <MutantStack.hpp>
#include <list>

int main () {
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);

	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout <<"my stack:\t"<< *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::list<int>  list;
	while (s.size() > 0) {
		list.push_back(s.top());
		std::cout <<"normal stack:\t"<< s.top() << std::endl;
		s.pop();
	}

	for (std::list<int>::iterator i = list.begin(); i != list.end(); i++)
		std::cout << "list:\t" << *i << std::endl;
	return 0;
}
