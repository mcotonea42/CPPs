#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cstdlib>
#include <sys/time.h>

long getTime(){
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec* 1000000L + tv.tv_usec;
}

bool isAllDigits(const std::string& str){
	if (str.empty())
		return false;
	for (size_t i = 0; i < str.size(); i++){
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

/* Ford-Johnson sort with std::vector */

std::vector<int> vJacobstahl(int n){
	std::vector<int> seq;

	seq.push_back(0);
	if (n <= 0)
		return seq;
	seq.push_back(1);
	if (n == 1)
		return seq;
	for (int i = 2; i < n + 2; i++){
		int next = seq[i - 1] + 2 * seq[i - 2];
		seq.push_back(next);
	}
	return seq;
}

void vbinaryInsert(std::vector<int>& sorted, int value){
	std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), value);
	sorted.insert(pos, value);
}


std::vector<int> vFordJohnson(const std::vector<int>& arr){
	if (arr.size() <= 1)
		return arr;
	
	std::vector<int> larges;
	std::vector<int> smalls;

	for (size_t i = 0; i + 1 < arr.size(); i +=2){
		if (arr[i] < arr[i + 1]){
			smalls.push_back(arr[i]);
			larges.push_back(arr[i + 1]);
		}
		else{
			smalls.push_back(arr[i + 1]);
			larges.push_back(arr[i]);
		}
	}

	bool hasOrphan = (arr.size() % 2 == 1);
	int orphan = -1;
	if (hasOrphan)
		orphan = arr.back();

	std::vector<int> sortedLarges = vFordJohnson(larges);

	std::vector<int> sortedSmalls;
	for (size_t i = 0; i < sortedLarges.size(); i++){
		for (size_t j = 0; j < larges.size(); j++){
			if (sortedLarges[i] == larges[j]){
				sortedSmalls.push_back(smalls[j]);
				break;
			}
		}
	}

	if (!sortedSmalls.empty()){
		std::vector<int> J = vJacobstahl(sortedSmalls.size());
		std::vector<int> inserted(sortedSmalls.size(), 0);

		vbinaryInsert(sortedLarges, sortedSmalls[0]);
		inserted[0] = 1;

		for (size_t i = 2; i < J.size(); i++){
			int index = J[i] - 1;
			int prevIndex = J[i - 1] - 1;

			if (index >= static_cast<int>(sortedSmalls.size()))
				break;

			for (int k = index; k > prevIndex; --k){
				if (k >= 0 && k < static_cast<int>(sortedSmalls.size()) && !inserted[k]){
					vbinaryInsert(sortedLarges, sortedSmalls[k]);
					inserted[k] = 1;
				}
			}
		}

		for (size_t i = 0; i < sortedSmalls.size(); i++){
			if (!inserted[i]){
				vbinaryInsert(sortedLarges, sortedSmalls[i]);
				inserted[i] = 1;
			}
		}
		
	}
	if (hasOrphan)
		vbinaryInsert(sortedLarges, orphan);
	return sortedLarges;
}

bool visSorted(const std::vector<int> data){
	for (size_t i = 0; i + 1 < data.size(); i++)
		if (data[i] > data[i + 1])
			return false;
	return true;
}

/* Ford-Johnson sort with std::deque */

std::deque<int> dJacobstahl(int n){
	std::deque<int> seq;

	seq.push_back(0);
	if (n <= 0)
		return seq;
	seq.push_back(1);
	if (n == 1)
		return seq;
	for (int i = 2; i < n + 2; i++){
		int next = seq[i - 1] + 2 * seq[i - 2];
		seq.push_back(next);
	}
	return seq;
}

void dbinaryInsert(std::deque<int>& sorted, int value){
	std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), value);
	sorted.insert(pos, value);
}


std::deque<int> dFordJohnson(const std::deque<int>& arr){
	if (arr.size() <= 1)
		return arr;
	
	std::deque<int> larges;
	std::deque<int> smalls;

	for (size_t i = 0; i + 1 < arr.size(); i +=2){
		if (arr[i] < arr[i + 1]){
			smalls.push_back(arr[i]);
			larges.push_back(arr[i + 1]);
		}
		else{
			smalls.push_back(arr[i + 1]);
			larges.push_back(arr[i]);
		}
	}

	bool hasOrphan = (arr.size() % 2 == 1);
	int orphan = -1;
	if (hasOrphan)
		orphan = arr.back();

	std::deque<int> sortedLarges = dFordJohnson(larges);

	std::deque<int> sortedSmalls;
	for (size_t i = 0; i < sortedLarges.size(); i++){
		for (size_t j = 0; j < larges.size(); j++){
			if (sortedLarges[i] == larges[j]){
				sortedSmalls.push_back(smalls[j]);
				break;
			}
		}
	}

	if (!sortedSmalls.empty()){
		std::deque<int> J = dJacobstahl(sortedSmalls.size());
		std::deque<int> inserted(sortedSmalls.size(), 0);

		dbinaryInsert(sortedLarges, sortedSmalls[0]);
		inserted[0] = 1;

		for (size_t i = 2; i < J.size(); i++){
			int index = J[i] - 1;
			int prevIndex = J[i - 1] - 1;

			if (index >= static_cast<int>(sortedSmalls.size()))
				break;

			for (int k = index; k > prevIndex; --k){
				if (k >= 0 && k < static_cast<int>(sortedSmalls.size()) && !inserted[k]){
					dbinaryInsert(sortedLarges, sortedSmalls[k]);
					inserted[k] = 1;
				}
			}
		}

		for (size_t i = 0; i < sortedSmalls.size(); i++){
			if (!inserted[i]){
				dbinaryInsert(sortedLarges, sortedSmalls[i]);
				inserted[i] = 1;
			}
		}
		
	}
	if (hasOrphan)
		dbinaryInsert(sortedLarges, orphan);
	return sortedLarges;
}

bool disSorted(const std::deque<int> data){
	for (size_t i = 0; i + 1 < data.size(); i++)
		if (data[i] > data[i + 1])
			return false;
	return true;
}

