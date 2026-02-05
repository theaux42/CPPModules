#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
  BitcoinExchange btc;
  
  if (ac != 2) {
    std::cerr << "Error: could not open file." << std::endl;
    return (1);
  }

  std::string inputFile(av[1]);

  if (!btc.getValuesFromCSV("data.csv")) {
    std::cerr << "Error: could not open database file." << std::endl;
    return (1);
  }

  btc.calculateFromInput(inputFile);

  return (0);
}
