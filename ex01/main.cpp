#include "Span.hpp"
#include <iostream>
#include <unistd.h>

void subjectTest();
int main(){
    std::srand(std::time(NULL));
	subjectTest();
    
    {   // span haven't number
        Span span(5);
        try{
            std::cout << "shortest: " << span.shortestSpan() << std::endl;
        }catch(Span::SpanEmpty& e){
            std::cerr << e.what() << std::endl;
        }
        try{
            std::cout << "longest: " << span.longestSpan() << std::endl;
        }catch(Span::SpanEmpty& e){
            std::cerr << e.what() << std::endl;
        }
    }

    EMPTY_LINE;
    {   //span have only one number
        Span span(5);
        span.addNumber(1);
        try{
            std::cout << "shortest: " << span.shortestSpan() << std::endl;
        }catch(Span::SpanOneElement& e){
            std::cerr << e.what() << std::endl;
        }
        try{
            std::cout << "longest: " << span.longestSpan() << std::endl;
        }catch(Span::SpanOneElement& e){
            std::cerr << e.what() << std::endl;
        }
    }

    EMPTY_LINE;
    {   //limit over case
        Span span(TEST_NUM);
		uVec vector(TEST_NUM, 42);
        try{
			span.addNumbers(vector);
			span.addNumber(1);
        }catch(Span::SpanFull& e){
            std::cout << e.what() << std::endl;
        }
    }

    EMPTY_LINE;
    { //true case
        Span span(TEST_NUM);
		uVec vector(TEST_NUM, 42);
        try{
			span.addNumbers(vector);
        }catch(Span::SpanFull& e){
            std::cout << e.what() << std::endl;
        }
        std::cout << "shortest: " << span.shortestSpan() << std::endl;
        std::cout << "longest: " << span.longestSpan() << std::endl;
        span.getMinMax();
    }

	EMPTY_LINE;
	{
        Span span(TEST_NUM);
		uDeq deque(TEST_NUM, 42);
        try{
			span.addNumbers(deque);
        }catch(Span::SpanFull& e){
            std::cout << e.what() << std::endl;
        }
        std::cout << "shortest: " << span.shortestSpan() << std::endl;
        std::cout << "longest: " << span.longestSpan() << std::endl;
        span.getMinMax();
	}
		
	EMPTY_LINE;
	{
        Span span(TEST_NUM);
		uList list(TEST_NUM, 42);
        try{
			span.addNumbers(list);
        }catch(Span::SpanFull& e){
            std::cout << e.what() << std::endl;
        }
        std::cout << "shortest: " << span.shortestSpan() << std::endl;
        std::cout << "longest: " << span.longestSpan() << std::endl;
        span.getMinMax();
	}

	EMPTY_LINE;
}

void subjectTest() {
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}
