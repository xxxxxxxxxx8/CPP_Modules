#include <Serializer.hpp>

int main() {
	Data	data;

	data.RandomData = 1337;
	std::cout << "data value before serializing:\t" <<data.RandomData<< std::endl;
	uintptr_t	p	= Serializer::serialize(&data);
	Data*		ptr	= Serializer::deserialize(p);

	if (ptr == &data) std::cout << "deserialized successefully!"<<std::endl;
	std::cout << "data value after deserializing:\t" <<ptr->RandomData<< std::endl;
}
