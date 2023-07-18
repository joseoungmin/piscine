#ifndef ITER_HPP
#define ITER_HPP

#include "iostream"

template <typename T>
void	iter(T *array, size_t size, void (*f)(T&)) {
	for (size_t i=0; i<size; i++)
		f(array[i]);
}

template <typename T>
void	print(T &str) {
	std::cout << str << " ";
}

template <typename T>
void	plus_ten(T &array) {
	array[0] += 10;
}

template <typename T>
void	minus_ten(T &array) {
	array[0] -= 10;
}

#endif
