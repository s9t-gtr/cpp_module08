#ifndef __EASYFIND_HPP
# define __EASYFIND_HPP

#include <iostream>
#include <algorithm> // std::find

template <typename T>
void easyfind(const T& container, const int target) {
	typename T::const_iterator it = std::find(container.begin(), container.end(), target);
	if (it != container.end()) {
		std::cout << "Found " << target << " at position " << std::distance(container.begin(), it) + 1 << std::endl;
	} else {
		throw std::invalid_argument("Element not found");
	}
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
