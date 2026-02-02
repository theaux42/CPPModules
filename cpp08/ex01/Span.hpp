#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

class Span {
private:
  unsigned int _size;
  std::vector<int> _numbers;

public:
  Span(void) : _size(10) {};
  Span(unsigned int size) : _size(size) {};
  ~Span(void) {};

  Span(const Span &src);
  Span &operator=(const Span &src);

  void addNumber(int number);
	void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
  int shortestSpan(void);
  int longestSpan(void);
};

#endif
