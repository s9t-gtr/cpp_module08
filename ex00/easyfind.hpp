#ifndef __EASYFIND_HPP
# define __EASYFIND_HPP

#include <iostream>


template <typename T>
void easyfind(const T& container, const int target){
	size_t firstOccurrence = 1;
	typename T::const_iterator it = container.begin();
	for (; it != container.end(); it++) {		
		if (*it == target) {
			std::cout << "        First occurrence position: " << firstOccurrence << std::endl;
			return;
		}
		firstOccurrence++;
	}
    throw std::invalid_argument("Not found in container");
}

// test code
template <typename T>
T createContainer(int *ptr, size_t size) {
	T container;
	for (size_t i = 0; i < size; i++) {
		container.insert(container.end(), ptr[i]);
	}
	return container;
}

#endif
