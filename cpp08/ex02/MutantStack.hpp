#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
	typedef typename std::stack<T>::container_type::reverse_iterator iterator;

				MutantStack();
				MutantStack(const MutantStack<T>& copy);
MutantStack<T>&	operator=(const MutantStack<T>& copy);
				~MutantStack();
iterator		begin();
iterator		end();

};

#include <MutantStack.tpp>

#endif
