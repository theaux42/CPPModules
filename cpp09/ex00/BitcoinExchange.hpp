#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>

class BitcoinExchange {

  private:
    std::map<std::string,double> _prices;
  public:
    void processFile(char *fpath);
};


#endif