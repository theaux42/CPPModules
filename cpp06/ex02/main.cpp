#include "Base.hpp"

class D : public Base {};

Base * generate(void)
{
    int num;
    srand(time(NULL));
    num = rand() % 300;
    if (num < 100)                    {std::cout << "The generated class is a A" << std::endl; return new A();}
    else if ( 100 < num && num < 200) {std::cout << "The generated class is a B" << std::endl; return new B();}
    else                              {std::cout << "The generated class is a C" << std::endl; return new C();}

}

void identify(Base* p)
{
    if (dynamic_cast<A *>(p)) {std::cout << "This point to a A class" << std::endl; return;};
    if (dynamic_cast<B *>(p)) {std::cout << "This point to a B class" << std::endl; return;};
    if (dynamic_cast<C *>(p)) {std::cout << "This point to a C class" << std::endl; return;};
    std::cout << "This point to an unknown class :(" << std::endl;
    return;
}

void identify(Base& p)
{
    try {
        dynamic_cast<A &>(p);
        std::cout << "This point to a A class" << std::endl;
        return;
    } catch (std::exception &e) {}
    
    try {
        dynamic_cast<B &>(p);
        std::cout << "This point to a B class" << std::endl;
        return;
    } catch (std::exception &e) {}
    
    try {
        dynamic_cast<C &>(p);
        std::cout << "This point to a C class" << std::endl;
        return;
    } catch (std::exception &e) {}
    
    std::cout << "This point to an unknown class :(" << std::endl;
    return;
}

int main(void)
{
    Base    *random = generate();
    D       *suspect = new D;

    identify(random);
    identify(*random);

    std::cout << "Testing with an unknown class." << std::endl;
    identify(suspect);
    identify(*suspect);

    delete random;
    delete suspect;

    return (0);

}