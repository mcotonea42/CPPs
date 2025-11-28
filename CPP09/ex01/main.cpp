#include "RPN.hpp"

int main(int argc, char **argv){
	
    if (argc != 2){
        std::cerr << "Usage: ./RNP \"expression\"" << std::endl;
        return 1;
    }

    std::string expression = argv[1];
    RPN rnp;

    try{
        int result = rnp.processExpression(expression);
        std::cout << result << std::endl;
    }
    catch (std::runtime_error& e){
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}