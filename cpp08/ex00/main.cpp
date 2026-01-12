#include "easyfind.hpp"

int main(void)
{
    std::vector<int> vec;
    int found_pos = 0;

    vec.push_back(10);
    vec.push_back(98);
    vec.push_back(67);
    vec.push_back(38);
    vec.push_back(234);

    found_pos = easyfind(vec, 38);
    std::cout << "The target is at slot " << found_pos << std::endl;

    // try
    // {
    //     found_pos = easyfind(vec, 3489);
    //     std::cout << "The target is at slot " << found_pos << std::endl;
    // }
    // catch (std::exception & e)
    // {
    //     std::cerr << e.what() << std::endl;
    // }

    return (0);
}