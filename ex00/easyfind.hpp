#ifndef __EASYFIND_HPP
# define __EASYFIND_HPP

#include <iostream>
#include <algorithm>

template <typename T>
void easyfind(const T type, const int n){
    if(n < 0){
        std::cerr << "Error: Second argument must be greater than or equal to 0" << std::endl;
        return;
    }
    if((int)type.size()-1 < n)
        throw std::exception();
    std::cout << type[n] <<std::endl;
}

#endif