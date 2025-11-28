#include "PmergeMe.cpp"

int main(int argc, char **argv){
	if (argc < 2){
		std::cerr << "\033[33mUsage: " << argv[0] << " n1 n2 n3...\033[0m" << std::endl;
		return 1;
	}

	std::vector<int> data;
	std::deque<int> atad;
	for (int i = 1; i < argc; i++){
		std::string arg(argv[i]);
		if (!isAllDigits(arg)){
			std::cerr << "\033[31mError\033[0m" << std::endl;
			return 1;
		}
		data.push_back(atoi(argv[i]));
		atad.push_back(atoi(argv[i]));
	}

	std::cout << "Before: ";
	for (size_t i = 0; i < data.size(); i++)
		std::cout << data[i] << " ";
	std::cout << std::endl;

	long vstart = getTime();
	std::vector<int> arr = vFordJohnson(data);
	long vend = getTime();

	long dstart = getTime();
	std::deque<int> rra = dFordJohnson(atad);
	long dend = getTime();
	
	std::cout << "After: ";
	for (size_t i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << data.size() << " elements with std::vector : " << (vend - vstart) << " us" << std::endl;
	std::cout << "Time to process a range of " << atad.size() << " elements with std::deque : " << (dend - dstart) << " us" << std::endl;

	if (visSorted(arr) && disSorted(rra))
		std::cout << "\033[32mCongrat\'s!\033[0m" << std::endl;
}