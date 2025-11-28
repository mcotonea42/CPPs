#include "BitcoinExchange.hpp"

int main(int argc, char **argv){

	if (argc != 2){
		std::cerr << "Usage: ./btc <input_file>" << std::endl;
		return 1;
	}

	try {
		BitcoinExchange btc;
		btc.readFile("data.csv");
		btc.processInputFile(argv[1]);
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	return 0;
}