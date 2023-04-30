#include "Bureaucrat.hpp"

int main(){	
	try{
		Bureaucrat seojo_one("seojo1", 1);
		Bureaucrat seojo_two("seojo2", 150);

		// seojo_one.incrementGrade();
		seojo_two.incrementGrade();

		std::cout << seojo_one << "\n";
		std::cout << seojo_two << "\n";

		seojo_one.decrementGrade();
		seojo_two.decrementGrade();

		std::cout << seojo_one << "\n";
		std::cout << seojo_two << "\n";
	}
	catch (std::exception &err){
		std::cerr << err.what() << std::endl;
	}
	return 0;
}
