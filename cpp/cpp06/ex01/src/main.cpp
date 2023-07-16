#include "Serialization.hpp"

int main(void)
{
	Data		first;
	Data*		second;
	uintptr_t	num_ptr;

	first.name = "seojo";
	num_ptr = serialize(&first);
	second = deserialize(num_ptr);
	std::cout << "Data first - name is " << first.name << "\n";
	std::cout << "Data second - name is " << second->name << "\n";
	return (0);
}
