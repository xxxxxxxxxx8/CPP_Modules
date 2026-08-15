#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<class T>
class Array {
	private:
		unsigned int	len;
		T*				arr;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& copy);
Array&	operator=(const Array& copy);
T&		operator[](const int& index);
const T&		operator[](const int& index) const;
		~Array();

unsigned int	size() const;

};

#include <Array.tpp>

#endif
