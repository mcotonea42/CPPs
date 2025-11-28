#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>

class BitcoinExchange{
	private:

		std::map<std::string, float> data;

		bool isValidDate(const std::string& date) const;
		bool isValidNumber(const std::string& value) const;

	public:

		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();
	
		BitcoinExchange& readFile(const std::string& file);
		void processInputFile(const std::string& filename) const;

};