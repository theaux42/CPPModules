#include "BitcoinExchange.hpp"
// constructors and destructor
BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
    : _values(other._values) {}

// assign operator
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
  if (this != &other)
    _values = other._values;
  return (*this);
}

bool BitcoinExchange::getValuesFromCSV(const std::string path) {
  std::string buffer;
  std::ifstream data(path.c_str());

  if (!data.is_open())
    return (false);

  std::getline(data, buffer);
  while (std::getline(data, buffer)) {
    size_t pos = buffer.find(',');

    if (pos == std::string::npos)
      return (false);

    std::string date_str = buffer.substr(0, pos);
    std::string value_str = buffer.substr(pos + 1);
    time_t date = parseDate(date_str);
    double value = std::atof(value_str.c_str());
    if (date == -1) {
      std::cerr << "wrong format : " << date_str << std::endl;
      return (false);
    }
    this->_values[date] = value;
  }
  return (true);
}

double BitcoinExchange::getRateByDate(time_t udate) {
  if (!udate)
    return (-1);

  std::map<std::time_t, double>::iterator it = _values.find(udate);
  if (it != _values.end())
    return (it->second);

  std::map<std::time_t, double>::iterator lower = _values.lower_bound(udate);
  if (lower == _values.begin())
    return (-1);

  lower--;
  return (lower->second);
}

time_t BitcoinExchange::parseDate(const std::string &dateStr) {
  struct tm timeStruct = {};
  char *result = strptime(dateStr.c_str(), "%Y-%m-%d", &timeStruct);

  if (result == NULL) {
    return (-1);
  }

  time_t timestamp = mktime(&timeStruct);

  if (timestamp == -1) {
    return (-1);
  }

  return (timestamp);
}

bool BitcoinExchange::isValidValue(const std::string &value) {
  if ((value.find_first_of('.') != value.find_last_of('.')) ||
      value[value.length() - 1] == '.' ||
      (value.find_first_not_of("0123456789.-") != std::string::npos) ||
      ((value.find('-') != std::string::npos) && value[0] != '-')) {
    return (false);
  }
  return (true);
}

void BitcoinExchange::calculateFromInput(std::string fileName) {
  std::ifstream input(fileName.c_str());
  std::string line;

  if (!input.is_open()) {
    std::cerr << "Error: could not open file." << std::endl;
    return;
  }

  std::getline(input, line);
  if (line != "date | value") {
    std::cerr << "Error: invalid file format." << std::endl;
    return;
  }

  while (std::getline(input, line)) {
    size_t pos = line.find('|');
    if (pos == std::string::npos) {
      std::cerr << "Error: bad input => " << line << std::endl;
      continue;
    }

    if (pos == 0 || pos + 2 >= line.length()) {
      std::cerr << "Error: bad input => " << line << std::endl;
      continue;
    }

    std::string date_str = line.substr(0, pos - 1);
    std::string stringValue = line.substr(pos + 2);

    if (!isValidValue(stringValue)) {
      std::cerr << "Error: bad input => " << line << std::endl;
      continue;
    }

    double value = std::atof(stringValue.c_str());

    if (value <= 0) {
      std::cerr << "Error: not a positive number." << std::endl;
      continue;
    }
    if (value > 1000) {
      std::cerr << "Error: too large a number." << std::endl;
      continue;
    }

    time_t udate = parseDate(date_str);
    if (udate == -1) {
      std::cerr << "Error: bad input =>" << date_str << std::endl;
      continue;
    }
    double rate = getRateByDate(udate);

    if (rate == -1) {
      std::cerr << "Error: date too early." << std::endl;
      continue;
    }

    else {
      std::cout << date_str << " => " << value << " = " << (value * rate)
                << std::endl;
    }
  }
}