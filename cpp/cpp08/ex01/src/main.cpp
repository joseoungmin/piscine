#include "Span.hpp"

int main()
{
	try
	{
		std::cout << "-- Basic -- \n";
		Span	test(5);

		test.addNumber(6);
		test.addNumber(3);
		test.addNumber(17);
		test.addNumber(9);
		test.addNumber(11);
		std::cout << "shortest " << test.shortestSpan() << std::endl;
		std::cout << "longest " << test.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "\n-- not enough space -- \n";
		Span	test(3);
		test.addNumber(3);
		test.addNumber(17);
		test.addNumber(9);
		test.addNumber(11);
		std::cout << "shortest " << test.shortestSpan() << std::endl;
		std::cout << "longest " << test.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "\n-- only one number -- \n";
		Span	test(5);

		test.addNumber(6);
		std::cout << "shortest " << test.shortestSpan() << std::endl;
		std::cout << "longest " << test.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "\n-- add_tenThousand_rand_num -- \n";
		Span	test(10000);
		
		test.add_tenThousand_rand_num();

		std::cout << "shortest " << test.shortestSpan() << std::endl;
		std::cout << "longest " << test.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
			std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "\n-- addManyNumbers -- \n";
		Span mySpan(5);
		std::vector<int> numbersToAdd;
		numbersToAdd.push_back(1);
		numbersToAdd.push_back(2);
		numbersToAdd.push_back(3);
		numbersToAdd.push_back(4);
		numbersToAdd.push_back(5);

		mySpan.addManyNumbers(numbersToAdd.begin(), numbersToAdd.end(), numbersToAdd.size());

		std::cout << "shortest " << mySpan.shortestSpan() << std::endl;
		std::cout << "longest " << mySpan.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
