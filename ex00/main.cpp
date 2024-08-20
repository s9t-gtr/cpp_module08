#include "easyfind.hpp"
#include <vector>

int main(){
    {
        std::vector<int> i_vec;
        for (int i = 0; i < 5; ++i) {
            i_vec.push_back(i);
        }
        try{
            easyfind(i_vec, 10);
        }catch(std::exception&){
            std::cerr << "i_vec: exception" << std::endl;
        }
    }
    {
        std::vector<std::string> s_vec(5);
        s_vec[0] = "hoge";
        s_vec[1] = "";
        s_vec[2] = "hello";
        s_vec[3] = "h";
        s_vec[4] = "o";
        try{
            easyfind(s_vec, 3);
            easyfind(s_vec, INT_MAX);
            // easyfind(s_vec, INT_MIN);
        }catch(std::exception&){
            std::cerr << "s_vec: exception" << std::endl;
        }
    }
}