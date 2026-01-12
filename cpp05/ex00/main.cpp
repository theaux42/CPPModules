#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat First("Martin", 1);
    Bureaucrat Second;

    std::cout << "Trying to declare impossible bureaucrats" << std::endl;
    try { Bureaucrat Third("BreakingMan", 0); }  catch (std::exception & e) { std::cerr << e.what() << std::endl; }
    try { Bureaucrat Third("BreakingMan", 4242); }  catch (std::exception & e) { std::cerr << e.what() << std::endl; }

    std::cout << Second << std::endl;
    std::cout << First << std::endl;
    
    std::cout << "Trying to break limits of grade" << std::endl;
    try { First.increaseGrade(); } catch (std::exception &e) { std::cerr << e.what() << std::endl; };
    try { Second.decreaseGrade(); } catch (std::exception &e) { std::cerr << e.what() << std::endl; };
    
    First.decreaseGrade();
    Second.increaseGrade();

    std::cout << "After Increase" << std::endl;
    std::cout << Second << std::endl;
    std::cout << First << std::endl;

    return 0;
}