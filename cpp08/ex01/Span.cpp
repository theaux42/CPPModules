#include "Span.hpp"

Span::Span(const Span &src) {
    this->_size = src._size;
}

Span &Span::operator=(const Span &src) {
    if (this != &src) {
        this->_size = src._size;
    }
    return (*this);
}

void Span::addNumber(int number) {
    if (this->_numbers.size() >= this->_size) {
        throw std::out_of_range("Cannot add more numbers, span is full.");
    }
    this->_numbers.push_back(number);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    for (std::vector<int>::iterator it = begin; it != end; ++it) {
        if (this->_numbers.size() >= this->_size) {
            throw std::out_of_range("Cannot add more numbers, span is full.");
            break;
        }
        this->_numbers.push_back(*it);
    }
}

int Span::shortestSpan(void) {
    if (this->_numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to find a span.");
    }

    std::vector<int> sortedNumbers = this->_numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    int minSpan = INT_MAX;
    for (size_t i = 1; i < sortedNumbers.size(); ++i) {
        int span = sortedNumbers[i] - sortedNumbers[i - 1];
        if (span < minSpan) {
            minSpan = span;
        }
    }
    return minSpan;
}

int Span::longestSpan(void) {
    if (this->_numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to find a span.");
    }
  int max = *std::max_element(this->_numbers.begin(), this->_numbers.end());
  int min = *std::min_element(this->_numbers.begin(), this->_numbers.end());
  return (max - min);
}