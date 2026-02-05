#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

class BitcoinExchange {
private:
  std::map<std::time_t, double> _values;
  double getRateByDate(time_t udate);

public:
  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &other);
  BitcoinExchange &operator=(const BitcoinExchange &other);
  ~BitcoinExchange();

  bool getValuesFromCSV(const std::string path);
  void calculateFromInput(const std::string path);
  time_t parseDate(const std::string &dateStr);
  bool isValidValue(const std::string &value);
};

#endif