#ifndef EASY_FIND_HPP
#define EASY_FIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, int find_num) {
	typename T::iterator it;  // C 라는 클래스에 iterator 라는 이름의 멤버변수가 있을지도 모르니 typename을 붙여 자료형을 고정시켜주어야 한다.
		it = std::find(container.begin(), container.end(), find_num);
		if (it == container.end())
			throw std::runtime_error("number is not in this container");
	return it;
}

#endif
