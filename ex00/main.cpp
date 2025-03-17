#include "easyfind.hpp"

#include <deque>
#include <list>
#include <set>
#include <vector>

#include <sstream>
// Need to think containers (exclude associative containers)
//  - deque
//  - list
//  - vector
//  - set

//can i create test by shell script?.
// i should think about that i can't turn in the script fil"\t" << e.
// but the test by shell script is most simple, and need to change c++ code to this test execution.
// if write test code in c++ only, i have to write many various container definition. this is inefficient.
// can you write simple test code in c++?
// i should make my test require command line argument. 

bool checkOnlyDigit(char *arg) {
	std::string str(arg);	
	if (str[0] == '-') { str = str.substr(1); }
	for (size_t i = 0; i < str.size(); i++) {
		if (!std::isdigit(str[i])) {
			return false;
		}
	}
	return true;
}

int main(int argc, char **argv){
	/*
	 * argments explanation:
	 *  - argv[0 < argc - 1]: container elements
	 *  - argv[argc - 1]    : target
	 */
	// 1. error handling
	if (argc < 3) {
		std::cerr << "Usage: ./ex00 [numbers] [target]" << std::endl;
		return 1;
	}
	int arrSize = argc - 2;
	// 2. parse arguments
	int arr[arrSize]; // exclude program_name and target
	int arrIndex = 0;
	int target = 0;
	for (int i = 1; i < argc; i++) {
		if (!checkOnlyDigit(argv[i])) { 
			std::cerr << "Invalid argument: " << argv[i] << std::endl;
			return 1; 
		}
		int num = 0;
		std::stringstream ss(argv[i]);
		if (!(ss >> num)) {
			std::cerr << "Invalid argument: " << argv[i] << std::endl;
			return 1;
		}
		if (i == argc - 1) {
			target = num;
			break;
		}
		arr[arrIndex++] = num;
	}
	// 3. test
	// - deque
	std::deque<int> deque = createContainer<std::deque<int> >(arr, arrSize);
	std::cout << "\tdeque: " << std::endl;
	try{
		easyfind(deque, target);
	}catch(std::invalid_argument& e){
		std::cerr << "\t\t" << e.what() << std::endl;
	}
	// - list
	std::list<int> list = createContainer<std::list<int> >(arr, arrSize);
	std::cout << "\tlist: " << std::endl;
	try{
		easyfind(list, target);
	}catch(std::invalid_argument& e){
		std::cerr << "\t\t" << e.what() << std::endl;
	}
	// - vector
    std::vector<int> vector = createContainer<std::vector<int> >(arr, arrSize);
	std::cout << "\tvector: " << std::endl;
    try{
        easyfind(vector, target);
    }catch(std::invalid_argument& e){
		std::cerr << "\t\t" << e.what() << std::endl;
    }
	    
	// - set
	std::set<int> set = createContainer<std::set<int> >(arr, arrSize);
	std::cout << "\tset: " << std::endl;
	try{
		easyfind(set, target);
	}catch(std::invalid_argument& e){
		std::cerr << "\t\t" << e.what() << std::endl;
	}
}

