#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    Bureaucrat First("Martin", 1);
    Bureaucrat Second; // default to "George" 150

    Form form("Meow", 10, 10);
    Form form2; // default to "Contract" 150 150

    try { Form Third("BrokenForm", 0, 12183); }  catch (std::exception & e) { std::cerr << e.what() << std::endl; }
    try { Form Third("BrokenForm", 4242, 0); }  catch (std::exception & e) { std::cerr << e.what() << std::endl; }

    std::cout << std::endl;
    std::cout << form << "\n" << form2 << std::endl;
    std::cout << std::endl;
    std::cout << Second << "\n" << First << std::endl;
    std::cout << std::endl;


    Second.signForm(form2);
    First.signForm(form2);
    First.signForm(form2);
    Second.signForm(form2);

    std::cout << std::endl;
    std::cout << form << "\n" << form2 << std::endl;
    
    return 0;
}