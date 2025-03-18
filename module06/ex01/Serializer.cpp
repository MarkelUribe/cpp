#include "Serializer.hpp"

Serializer::Serializer(){}
Serializer::Serializer(const Serializer& to_copy){(void)to_copy;}
Serializer::~Serializer(){}
Serializer& Serializer::operator=(const Serializer& to_asign){(void)to_asign;return (*this);}

uintptr_t	Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}
