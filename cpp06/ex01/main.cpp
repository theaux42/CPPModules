#include "Serializer.hpp"

void    print_data(Data data)
{
    std::cout << "Address of data : " << &data << "\n";
    std::cout << "First string : " << data.s1 << "\n";
    std::cout << "second string : " << data.s2 << "\n";
    std::cout << "int : " << data.i1 << "\n";
    std::cout << "bool : " << data.b1 << std::endl;
}

int main(void)
{
    Data    original_data = {"Hello", "World", 4242, true};
    Data    *recovered_data;
    uintptr_t temp = 0x0;

    print_data(original_data);
    temp = Serializer::serialize(&original_data);
    recovered_data = Serializer::deserialize(temp);
    print_data(*recovered_data);

    return (0);

}