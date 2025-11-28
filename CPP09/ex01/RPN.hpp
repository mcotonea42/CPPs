#pragma once

#include <iostream>
#include <sstream>
#include <stack>
#include <limits>

class RPN{
	private:

		std::stack<int> value;
	
	public:

		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		int processExpression(const std::string& expression);
};