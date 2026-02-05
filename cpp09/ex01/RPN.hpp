#ifndef RPN_HPP
#define RPN_HPP

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

class RPN {
private:
  std::stack<int> _stack;

  bool isNumber(const std::string &token);
  bool isOperator(const std::string &token);
  int operate(int a, int b, std::string op);
  void iterate(std::string token);
public:
  RPN();
  RPN(const RPN &other);
  RPN &operator=(const RPN &other);
  ~RPN();

  int calculate(const std::string &expression);
};

#endif