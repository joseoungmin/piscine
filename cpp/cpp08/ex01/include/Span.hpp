#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <limits>

class Span {
	private:
		std::vector<int>	mNumbers;
		unsigned int		mAdd;
		unsigned int		mMax;
	public:
		Span();
		Span(unsigned int num);
		Span(const Span & other);
		~Span();

		Span&	operator = (const Span & other);

		void				addNumber(int num);
		unsigned int		shortestSpan(void);
		unsigned int		longestSpan(void);
		void				add_tenThousand_rand_num(void);
		template <typename InputIterator>
		void				addManyNumbers(InputIterator begin, InputIterator end, int size);
};

template<typename InputIterator>
void Span::addManyNumbers(InputIterator begin, InputIterator end, int size) {
	if (mAdd + size > mMax)
		throw std::runtime_error("There is not enough space.");
	mAdd += size;
	mNumbers.insert(mNumbers.end(), begin, end);
}

#endif
