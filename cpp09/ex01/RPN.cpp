#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN &other) : _stack(other._stack) {}

RPN &RPN::operator=(const RPN &other) {
  if (this != &other)
    _stack = other._stack;
  return *this;
}

bool RPN::isNumber(const std::string &token) {
  return (token.length() == 1 && token[0] >= '0' && token[0] <= '9');
}

bool RPN::isOperator(const std::string &token) {
  return (token.length() == 1 && (token[0] == '+' || token[0] == '-' ||
                                  token[0] == '*' || token[0] == '/'));
}

int RPN::operate(int a, int b, std::string op) {
  switch (op[0]) {
  case '+':
    return (a + b);
  case '-':
    return (a - b);
  case '*':
    return (a * b);
  case '/':
    if (b == 0) {
      std::cerr << "Error" << std::endl;
      exit(1);
    }
    return (a / b);
  default:
    break;
  }
  return 0;
}

void RPN::iterate(std::string token) {
  if (_stack.size() < 2) {
    std::cerr << "Error" << std::endl;
    exit(1);
  }
  int b = _stack.top();
  _stack.pop();
  int a = _stack.top();
  _stack.pop();
  int res = operate(a, b, token);
  _stack.push(res);
}

int RPN::calculate(const std::string &expression) {
  std::istringstream iss(expression);
  std::string token;

  while (iss >> token) {
    if (!isNumber(token) && !isOperator(token)) {
      std::cerr << "Error" << std::endl;
      exit(1);
    }
    if (isNumber(token))
      _stack.push(std::atoi(token.c_str()));
    if (isOperator(token)) {
      iterate(token);
    }
  }
  if (_stack.size() != 1) {
    std::cerr << "Error" << std::endl;
    exit(1);
  }
  return (_stack.top());
}