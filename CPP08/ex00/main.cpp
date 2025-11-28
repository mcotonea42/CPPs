#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main(){
	{
		std::cout << GREEN "First test with a vector: " RESET << std::endl;
		std::vector<int> v;
		for (int i = 0; i < 10; ++i)
			v.push_back(i);
		for (int i = 0; i < 10; ++i)
			std::cout << v[i] << " " ;
		std::cout << std::endl;
		try{
			std::cout << "I search 5 in the container: " << std::endl;
			std::vector<int>::iterator result = easyfind(v, 5);
			std::cout << "Value found in the container: " << *result << std::endl;
		}
		catch (std::exception& e){
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << GREEN "Second test with a list: " RESET << std::endl;
		std::list<int> l;
		for (int i = 0; i < 10; ++i)
			l.push_front(i * 10);
		// A list cannot be accessed using the index operator
		// You have to go through the list with an iterator
		std::list<int>::iterator it;
		for (it = l.begin(); it != l.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
		try {
			std::cout << "I search 55 in the container: " << std::endl;
			std::list<int>::iterator result = easyfind(l, 55);
			std::cout << "Value found in the container: " << *result << std::endl;
		}
		catch (std::exception& e){
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << GREEN "Third test with a deque: " RESET << std::endl;
		std::deque<int> d;
		for (int i = 0; i < 10; ++i){
			if (i % 2 == 0)
				d.push_front(i * 10);
			else
				d.push_back(i * 10);
		}
		std::deque<int>::iterator it;
		std::cout << "Use an iterator to traverse the container" << std::endl;
		for (it = d.begin(); it != d.end(); ++it)
			std::cout << *it << " " ;
		std::cout << std::endl;
		std::cout << "Use an index operator to traverse the container" << std::endl;
		for (int i = 0; i < 10; ++i)
			std::cout << d[i] << " " ;
		std::cout << std::endl;
		try{			
			std::cout << "I search 70 in the container: " << std::endl;
			std::deque<int>::iterator result = easyfind(d, 70);
			std::cout << "Value found in the container: " << *result << std::endl;
		}
		catch(std::exception& e){
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}