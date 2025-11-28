#include "RPN.hpp"

RPN::RPN(): value(){}

RPN::RPN(const RPN& other): value(other.value){}

RPN& RPN::operator=(const RPN& other){
	if (this != &other)
		value = other.value;
	return *this;
}

RPN::~RPN(){}

int	RPN::processExpression(const std::string& expression){
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token){
		if (token.size() == 1 && isdigit(token[0]))
			value.push(token[0] - '0');
		else if (token == "+" || token == "-" || token == "*" || token == "/"){
			if (value.size() < 2)
				throw std::runtime_error("Error: not enough elements.");
			
			int b = value.top();
			value.pop();
			int a = value.top();
			value.pop();

			long long result = 0;

			if (token == "+")
				result = static_cast<long long>(a) + static_cast<long long>(b);
			else if (token == "-")
				result = static_cast<long long>(a) - static_cast<long long>(b);
			else if (token == "*"){
				result = static_cast<long long>(a) * static_cast<long long>(b);
			}
			else{
				if (b == 0)
					throw std::runtime_error("Error: division by zero.");
				result = static_cast<long long>(a) / static_cast<long long>(b);
			}
			if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min())
				throw std::runtime_error("Error: overflow.");
			value.push(static_cast<int>(result));
		}
		else
			throw std::runtime_error("Error: unauthorised character.");
	}
	return value.top();
}