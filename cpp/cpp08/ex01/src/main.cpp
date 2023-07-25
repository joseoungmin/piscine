#include "Span.hpp"

int main()
{
	try
	{
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
	std::cout << std::endl;
	try
	{
		Span	test(3); // not enough space

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
	std::cout << std::endl;
	try
	{
		Span	test(5); // only one number

		test.addNumber(6);
		std::cout << "shortest " << test.shortestSpan() << std::endl;
		std::cout << "longest " << test.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
		{
		Span	test(10000);
		test.add_tenThousand_rand_num();
		std::cout << "shortest " << test.shortestSpan() << std::endl;
		std::cout << "longest " << test.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
			std::cerr << e.what() << '\n';
	}
}
