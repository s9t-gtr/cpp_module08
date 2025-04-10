#include "Span.hpp"
#include <algorithm>
#include <iostream>
#include <limits.h>

Span::Span(int N) try : span(new uVec){ //std::cout << "Span: Unsigned int argument constructor called" << std::endl;
    span->reserve(N);
}catch(std::bad_alloc& e){
    std::cerr << "Span constructor: new failed" << std::endl;
}

Span::Span(const Span& other){
    //std::cout << "Span: Copy constructor called" << std::endl;
    if(this != &other)
        *this = other;
}   

Span::~Span(){
    //std::cout << "Span: Destructor called" << std::endl;
    delete span;
}

Span& Span::operator=(const Span& other){
    if(this != &other){
        try{
            uVec *p = new uVec;
            p->reserve(other.span->capacity());
			for(uVec::iterator it = other.span->begin(); it != other.span->end(); ++it)
				p->push_back(*it);
			if (span != NULL)
				delete span;
			span = p;
		}catch(std::bad_alloc& e){
			std::cerr << "Span: new failed" << std::endl;
		}
	}
    return *this;
}

void Span::addNumber(int number){
    if(span->size() == span->capacity())
        throw SpanFull();
    span->push_back(number);
}   

int Span::shortestSpan(){
    if(span->empty())
        throw SpanEmpty();
    if(span->size() == 1)
        throw SpanOneElement();
    std::sort(span->begin(), span->end());
    int shortDiff = UINT_MAX;
    size_t size = span->size() - 1;
    for(size_t i=0; i<size; i++) {
        int diff = span->at(i+1) - span->at(i);
        shortDiff = std::min(shortDiff, diff); 
    }
    return shortDiff;
}

int Span::longestSpan(){
    if(span->empty())
        throw SpanEmpty();
    if(span->size() == 1)
        throw SpanOneElement();
    std::sort(span->begin(), span->end());
    size_t len = span->size();
    int longDiff = span->at(len-1) - span->at(0);
    return longDiff;
}

const char* Span::SpanNotFound::what() const throw(){
    return "Exception: SpanNotFound";
}

const char* Span::SpanEmpty::what() const throw(){
    return "Exception: SpanEmpty";
}
const char* Span::SpanOneElement::what() const throw(){
    return "Exception: SpanOneElement";
}
const char* Span::SpanFull::what() const throw(){
    return "Exception: SpanFull";
}

void Span::getMinMax(){
    std::sort(span->begin(), span->end());
    std::cerr << " - span min num: "<<span->at(0) << std::endl;;
    std::cerr << " - span max num: "<<span->at(span->size()-1) << std::endl;;
}


