#include <MutantStack.hpp>


template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>(){

}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& copy)
: std::stack<T>(copy)
{

}

template <typename T>
MutantStack<T>::~MutantStack() {

}

template <typename T>
MutantStack<T>&	MutantStack<T>::operator=(const MutantStack<T>& copy) {
	if (&copy != this) {
		std::stack<T>::operator=(copy);  
	}
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin() {
	return std::stack<T>::c.rbegin();
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end() {
	return std::stack<T>::c.rend();	
}