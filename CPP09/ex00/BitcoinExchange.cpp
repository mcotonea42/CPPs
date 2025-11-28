#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other){
	this->data = other.data;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other){
	if (this != &other)
		this->data = other.data;
	return *this;
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange& BitcoinExchange::readFile(const std::string& file){
	std::ifstream infile(file.c_str());
	if (!infile){
		throw std::runtime_error("Cannot open .csv file");
	}
	std::string line;
	while (std::getline(infile, line)){
		if (line == "date,exchange_rate")
			continue;
		std::string date;
		float value;
		size_t pos;

		pos = line.find(",");
		date = line.substr(0, pos);
		value = atof(line.substr(pos + 1).c_str());
		data[date] = value;
	}
	return *this;
}

bool BitcoinExchange::isValidNumber(const std::string& value) const{
	if (value.empty())
		return false;
	
	size_t start = 0;
	if (value[0] == '-')
		start = 1;
	int dot = 0;
	for (size_t i = start; i < value.length(); ++i){
		if (value[i] == '.'){
			dot++;
			if (dot > 1)
				return false;
		}
		else if (!isdigit(value[i]))
			return false;
	}
	return true;
}

bool BitcoinExchange::isValidDate(const std::string& date) const{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8, 2);

	for (size_t i = 0; i < 4; ++i)
		if (!isdigit(year[i]))
			return false;
	for (size_t i = 0; i < 2; ++i)
		if (!isdigit(month[i]) || !isdigit(day[i]))
			return false;

	int y;
	std::istringstream(year) >> y;

	int m;
	std::istringstream(month) >> m;

	int d;
	std::istringstream(day) >> d;

	if (m < 1 || m > 12)
		return false;
	
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
		daysInMonth[1] = 29;
	if (d < 1 || d > daysInMonth[m - 1])
		return false;
	return true;
}

void BitcoinExchange::processInputFile(const std::string& filename) const{
	std::ifstream infile(filename.c_str());
	if (!infile){
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	while (std::getline(infile, line)){
		if (line == "date | value" || line.empty())
			continue;
		
		size_t pos = line.find(" | ");
		if (pos == std::string::npos){
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, pos);
		std::string value = line.substr(pos + 3);

		if (!isValidDate(date)){
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (!isValidNumber(value)){
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		
		double convert = atof(value.c_str());
		if (convert < 0){
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if(convert > 1000){
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		std::map<std::string, float>::const_iterator it = data.lower_bound(date);
		if (it == data.end() || it->first != date){
			if (it == data.begin()){
				std::cerr << "Error: no earlier data available." << std::endl;
				continue;
			}
			--it;
		}

		double rate = it->second;
		double result = convert * rate;
		std::cout << date << " => " << convert << " = " << result << std::endl;
	}
}