#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib>		// rand(), srand()
#include <ctime>		// time()
#include <stdexcept>	// std::exception

#define MAX_VAL 750

template <typename T>
class Array {
	private:
		T				*arr;
		unsigned int	idx;
	public:
		Array();
		Array(unsigned int num);
		Array(const Array & other);
		~Array();

		Array&	operator = (const Array & other);
		T&		operator [] (int idx) const;

		unsigned int	size() const;
};

template <typename T>
Array<T>::Array()
: arr(NULL), idx(0) {}

template <typename T>
Array<T>::Array(unsigned int num)
: idx(num) {
	arr = new T[num];
}

template <typename T>
Array<T>::Array(const Array & other) {
	*this = other;
}

template <typename T>
Array<T> & Array<T>::operator = (const Array & other) {
	if (this != &other) {
		idx = other.idx;
		arr = new T[idx];
		for (unsigned int i=0; i<idx; i++)
			arr[i] = other.arr[i];
	}
	return (*this);
}

template <typename T>
T& Array<T>::operator [] (int idx) const {
	if (idx < 0 || static_cast<unsigned int>(idx) >= this->idx)
		throw (std::exception());
	return (arr[idx]);
}

template <typename T>
Array<T>::~Array() {
	delete[] arr;
}

template <typename T>
unsigned int	Array<T>::size() const {
	return (idx);
}

#endif