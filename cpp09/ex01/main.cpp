#include "RPN.hpp"

int main(int argc, char **argv) {
  if (argc != 2)
    return (std::cerr << "Error" << std::endl, 1);

  RPN rpn;
  std::cout << rpn.calculate(argv[1]) << std::endl;

  return (0);
}
