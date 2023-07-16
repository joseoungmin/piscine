#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <string>
#include <iostream>

struct	Data {
	std::string	name;
};

uintptr_t	serialize(Data * ptr);
Data*		deserialize(uintptr_t int_ptr);

#endif
