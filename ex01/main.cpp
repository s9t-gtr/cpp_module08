#include "Span.hpp"
#define NUMS 0,1,2,3,4,5,6,7,8,9
int main(){
    Span span(20);
    try{
        int nums[] = {NUMS,NUMS,NUMS};
        vec vNums(nums, nums+30);
        span.addNumbers(std::begin(vNums), std::end(vNums));
    }catch(Span::SpanFull& e){
        std::cout << e.what() << std::endl;
    }

}