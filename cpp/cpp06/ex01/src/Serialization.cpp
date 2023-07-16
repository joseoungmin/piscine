#include "Serialization.hpp"

uintptr_t	serialize(Data * ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	deserialize(uintptr_t int_ptr) {
	return (reinterpret_cast<Data *>(int_ptr));
}
