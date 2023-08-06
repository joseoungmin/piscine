#include <algorithm>
#include <cstdlib>
#include <fstream>
#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}
PmergeMe::~PmergeMe(void) {}

void PmergeMe::eraseWS(std::string& str)
{
	size_t	pos;

	pos = str.find_last_not_of(" \n\r\t\f\v");
	str.erase(pos + 1);
	pos = str.find_first_not_of(" \n\r\t\f\v");
	str.erase(0, pos);
}

void PmergeMe::initNumbers(std::string arg)
{
	std::string	num_str;
	long		num;
	size_t		pos;
	char*		pEnd(NULL);

	eraseWS(arg);
	if (arg.empty())
		throw std::runtime_error(std::string(INIT_ERR "Empty argument exists"));
	while (!arg.empty()) {
		pos = arg.find_first_of(" \n\r\t\f\v");
		if (pos != std::string::npos) {
			num_str = arg.substr(0, pos);
			arg.erase(0, pos);
			eraseWS(arg);
		}
		else {
			num_str = arg;
			arg.clear();
		}
		num = std::strtol(num_str.c_str(), &pEnd, 10);
		if (*pEnd)
			throw std::runtime_error(std::string(INIT_ERR "Invalid number ["
				C_YELLOW + std::string(num_str) + C_RESET "]"));
		if (num <= 0)
			throw std::runtime_error(std::string(INIT_ERR
				"Not a positive number [" C_YELLOW + std::string(num_str)
				+ C_RESET "]"));
		if (num > 2147483647)
			throw std::runtime_error(std::string(INIT_ERR
				"Too large a number [" C_YELLOW + std::string(num_str)
				+ C_RESET "]"));
		m_origin.push_back(static_cast<int>(num));
		m_vector.push_back(static_cast<int>(num));
		m_deque.push_back(static_cast<int>(num));
	}
}

void PmergeMe::createAnswer(void)
{
	std::ofstream	ofs_input, ofs_answer;

	system("mkdir -p result");
	ofs_input.open("result/input.txt");
	if (!ofs_input.is_open())
		throw std::runtime_error(std::string(RED_ERR "Failed to open file ["
			C_YELLOW "input.txt" C_RESET "]"));
	ofs_answer.open("result/answer.txt");
	if (!ofs_answer.is_open())
		throw std::runtime_error(std::string(RED_ERR "Failed to open file ["
			C_YELLOW "answer.txt" C_RESET "]"));
	m_answer = m_origin;
	sort(m_answer.begin(), m_answer.end());
	std::cout << C_CYAN "Before:" C_RESET;
	for (size_t i = 0; i < m_origin.size(); i++)
	{
		if (i < 9)
			std::cout << "\t" << m_origin[i];
		else if (i == 9)
			std::cout << "\t" << "[...]";
		ofs_input << m_origin[i] << "\n";
	}
	std::cout << C_CYAN "\n After:" C_RESET;
	for (size_t i = 0; i < m_answer.size(); i++)
	{
		if (i < 9)
			std::cout << "\t" << m_answer[i];
		else if (i == 9)
			std::cout << "\t" << "[...]";
		ofs_answer << m_answer[i] << "\n";
	}
	std::cout << std::endl;
	ofs_input.close();
	ofs_answer.close();
}

void PmergeMe::createResult(void)
{
	std::ofstream	ofs_vector, ofs_deque;

	ofs_vector.open("result/vector.txt");
	if (!ofs_vector.is_open())
		throw std::runtime_error(std::string(RED_ERR "Failed to open file ["
			C_YELLOW "vector.txt" C_RESET "]"));
	ofs_deque.open("result/deque.txt");
	if (!ofs_deque.is_open())
		throw std::runtime_error(std::string(RED_ERR "Failed to open file ["
			C_YELLOW "deque.txt" C_RESET "]"));
	for (size_t i = 0; i < m_vector.size(); i++)
		ofs_vector << m_vector[i] << "\n";
	for (size_t i = 0; i < m_deque.size(); i++)
		ofs_deque << m_deque[i] << "\n";
	ofs_vector.close();
	ofs_deque.close();
}

size_t PmergeMe::jacobsthal(size_t n){
	if(n < 2)
		return n;
	return jacobsthal(n-1) + 2 * jacobsthal(n-2);
}

void PmergeMe::checkRunningTime(e_containerType type)
{
	clock_t	begin, end;
	double	duration;
	int		prec(0);

	begin = clock();

	if (type == VECTOR)
	{
		std::cout << "Time to process a range of " C_GREEN << m_vector.size()
				<< C_RESET " elements with std::vector : ";
		sortFordJohnson(m_vector, m_vector2);
	}
	else if (type == DEQUE)
	{
		std::cout << "Time to process a range of " C_GREEN << m_deque.size()
				<< C_RESET " elements with std::deque  : ";
		sortFordJohnson(m_deque, m_deque2);
	}
	else
		throw std::runtime_error(std::string(RED_ERR "Container type not found"));

	end = clock();
	duration = static_cast<double>(end - begin);
	for (double i = CLOCKS_PER_SEC; i > 1; i /= 10)
		if (static_cast<int>(duration) % static_cast<int>(i))
			prec++;
	std::cout << std::fixed;
	std::cout.precision(prec);
	std::cout << BC_CYAN << duration / CLOCKS_PER_SEC << C_RESET " s" << std::endl;
}

int PmergeMe::run(int argc, char** argv)
{
	try {
		for (int i = 1; i < argc; i++)
			initNumbers(argv[i]);
		createAnswer();
		checkRunningTime(VECTOR);
		checkRunningTime(DEQUE);
		createResult();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}
