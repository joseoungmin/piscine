#include "Span.hpp"

Span::Span()
: mAdd(0), mMax(0) {}

Span::Span(unsigned int num)
: mAdd(0), mMax(num) {}

Span::Span(const Span & other)
: mAdd(other.mAdd), mMax(other.mMax) {
	*this = other;
}

Span& Span::operator = (const Span & other) {
	if (this != &other) {
		mAdd = other.mAdd;
		mMax = other.mMax;
		mNumbers = other.mNumbers;
	}
	return (*this);
}

void	Span::addNumber(int num) {
	if (mAdd == mMax)
		throw std::runtime_error("There is not enough space.");
	mAdd++;
	mNumbers.push_back(num);
}

unsigned int	Span::shortestSpan(void) {
	if (mAdd == 0)
		throw std::runtime_error("There are no numbers.");
	else if (mAdd == 1)
		throw std::runtime_error("There is only one number.");
	std::sort(mNumbers.begin(), mNumbers.end());

	std::vector<int>::iterator	it = mNumbers.begin();
	unsigned int				rt_num = std::numeric_limits<unsigned int>::max();;
	int							prev = mNumbers.front();

	while (++it != mNumbers.end()) {
		if (rt_num > static_cast<unsigned int>(*it - prev))
			rt_num = static_cast<unsigned int>(*it - prev);
		prev = *it;
	}
	return (rt_num);
}

unsigned int	Span::longestSpan(void) {
	if (mAdd == 0)
		throw std::runtime_error("There are no numbers.");
	if (mAdd == 1)
		throw std::runtime_error("There is only one number.");
	return (*std::max_element(mNumbers.begin(), mNumbers.end()) 
			- *std::min_element(mNumbers.begin(), mNumbers.end()));
}

void	Span::add_tenThousand_rand_num(void) {
	if (mMax - mAdd < 10000)
		throw std::runtime_error("There is not enough space.");
	srand(time(NULL));
	for (int i = 0; 10000 > i; i++)
		mNumbers.push_back(rand());
	mAdd += 10000;
}

Span::~Span() {}
