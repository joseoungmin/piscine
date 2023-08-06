#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>

enum	e_containerType
{
	DEQUE,
	VECTOR
};

class	PmergeMe {
private:
	std::vector<int>	m_origin;
	std::vector<int>	m_answer;
	std::vector<int>	m_vector;
	std::vector<int>	m_vector2;
	std::deque<int>		m_deque;
	std::deque<int>		m_deque2;

	void	eraseWS(std::string& str);
	void	initNumbers(std::string arg);
	void	createAnswer(void);
	void	createResult(void);
	size_t	jacobsthal(size_t n);
	void	checkRunningTime(e_containerType type);
	
	template <typename T> void	mergeInsertion(T& c1, T& c2);
	template <typename T> void	sortPair(T& c1, T& c2);
	template <typename T> void	sortFordJohnson(T& c1, T& c2);

	PmergeMe(const PmergeMe& ref);
	PmergeMe& operator=(const PmergeMe& ref);

public:
	PmergeMe(void);
	~PmergeMe(void);

	int	run(int argc, char** argv);
};

template <typename T>
void	PmergeMe::sortPair(T& c1, T& c2) {
	size_t	size = c1.size();
	size_t	halfSize = size / 2;

	for (size_t i = 0; i < halfSize; i++) {
		if (c1[i] > c1[i + 1]) {
			c2.push_back(c1[i + 1]);
			c1.erase(c1.begin() + i + 1);
		}else {
			c2.push_back(c1[i]);
			c1.erase(c1.begin() + i);
		}
	}
	if (size % 2) {
		c2.push_back(c1[c1.size() - 1]);
		c1.pop_back();
	}
	for (size_t i = 0; i < halfSize - 1; i++) {
		for (size_t j = i + 1; j < halfSize; j++) {
			if (c1[i] > c1[j]) {
				int tmp = c1[j];
				c1.erase(c1.begin() + j);
				c1.insert(c1.begin() + j, c1[i]);
				c1.erase(c1.begin() + i);
				c1.insert(c1.begin() + i, tmp);
				tmp = c2[j];
				c2.erase(c2.begin() + j);
				c2.insert(c2.begin() + j, c2[i]);
				c2.erase(c2.begin() + i);
				c2.insert(c2.begin() + i, tmp);
			}
		}
	}
}

template <typename T> void	PmergeMe::mergeInsertion(T& c1, T& c2) {
	size_t	j_idx(1);
	size_t	idx(0);

	while (c2.size())
	{
		c1.insert(std::lower_bound(c1.begin(), c1.end(), c2[idx]), c2[idx]);
		c2.erase(c2.begin() + idx);
		if (idx == 0) {
			idx = jacobsthal(j_idx++) * 2 - 1;
			if (idx > c2.size() - 1)
				idx = c2.size() - 1;
		}
		else
			idx--;
	}
}

template <typename T> 
void	PmergeMe::sortFordJohnson(T& c1, T& c2) {
	if (c1.size() < 2)
		return ;
	sortPair(c1, c2);
	mergeInsertion(c1, c2);
}

#endif
