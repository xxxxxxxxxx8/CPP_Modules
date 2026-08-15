#include <Array.hpp>

template <class T>
Array<T>::Array() : len(0), arr(NULL) {

}

template <class T>
Array<T>::Array(unsigned int n) : len(0), arr(NULL) {
	if (n > 0) {
		try {
			arr = new T[n]();
			len = n;
		} catch (const std::exception& exp) {
			std::cerr << "Array parametric constructor" << std::endl;
			std::cerr << exp.what() << std::endl;
		}
	}
}

template <class T>
Array<T>::Array(const Array& copy)  {
	*this = copy;
}

template <class T>
Array<T>&		Array<T>::operator=(const Array& copy)  {

	if (&copy != this) {
		if (copy.len > 0) {
			delete[] arr;
			try {
				len = copy.len;
				arr = new T[copy.len]();
				for (unsigned int i(0); i < copy.len; i++)
					arr[i] =  copy.arr[i];
			} catch (const std::exception& exp) {
				arr = 0; len = 0;
				std::cerr << "Array '=' operator failed!!"<< exp.what() <<std::endl;
			}
		} else {
			arr = NULL; len = 0;
		}
	}
	return *this;
}

template <class T>
unsigned int Array<T>::size() const {
	return len;
}

template <class T>
Array<T>::~Array()  {
	delete[] arr;
}

template <class T>
T&	Array<T>::operator[](const int& index) {
	if (!(index >= 0 && index < static_cast<int>(len)))
		throw std::out_of_range("out of boundries index");
	return arr[index];
}

template <class T>
const T&	Array<T>::operator[](const int& index) const {
	if (!(index >= 0 && index < static_cast<int>(len)))
		throw std::out_of_range("out of boundries index");
	return arr[index];
}