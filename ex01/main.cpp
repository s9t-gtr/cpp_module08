#include "Span.hpp"
#include <unistd.h>
#define TEST_NUM 10000
#define EMPTY_LINE std::cout << std::endl
int main(){
    std::srand(std::time(NULL));
    
    {   // not exist number case
        Span emptySpan(5);
        try{
            std::cout << "shortest: " << emptySpan.shortestSpan() << std::endl;
        }catch(Span::SpanEmpty& e){
            std::cerr << e.what() << std::endl;
        }
        try{
            std::cout << "longest: " << emptySpan.longestSpan() << std::endl;
        }catch(Span::SpanEmpty& e){
            std::cerr << e.what() << std::endl;
        }
    }
    EMPTY_LINE;
    {   //one number case
        Span oneNumberSpan(5);
        oneNumberSpan.addNumber(1);
        try{
            std::cout << "shortest: " << oneNumberSpan.shortestSpan() << std::endl;
        }catch(Span::SpanOneElement& e){
            std::cerr << e.what() << std::endl;
        }
        try{
            std::cout << "longest: " << oneNumberSpan.longestSpan() << std::endl;
        }catch(Span::SpanOneElement& e){
            std::cerr << e.what() << std::endl;
        }
    }
    EMPTY_LINE;
    {   //limit over case
        Span limitSpan(TEST_NUM);
        try{
            for(size_t i=0;i<TEST_NUM+1;i++){
                limitSpan.addNumber(std::rand());
            }
        }catch(Span::SpanFull& e){
            std::cout << e.what() << std::endl;
        }
    }
    EMPTY_LINE;
    { //true case
        Span span(TEST_NUM);
        try{
            for(size_t i=0;i<TEST_NUM;i++){
                span.addNumber(std::rand());
            }
        }catch(Span::SpanFull& e){
            std::cout << e.what() << std::endl;
        }
        std::cout << "shortest: " << span.shortestSpan() << std::endl;
        std::cout << "longest: " << span.longestSpan() << std::endl;
        span.getMinMax();
    }
}