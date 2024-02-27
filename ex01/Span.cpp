#include "Span.hpp"

Span::Span(){
    std::cout << "Span: Default constructor called" << std::endl;
}
Span::Span(unsigned int N): span(new  vec[N]){
    std::cout << "Span: Unsigned int argument constructor called" << std::endl;
}
Span::Span(const Span& other){
    std::cout << "Span: Copy constructor called" << std::endl;
    if(this != &other)
        *this = other;
}   
Span::~Span(){
    std::cout << "Span: Destructor called" << std::endl;
    delete [] span;
}
Span& Span::operator=(const Span& other){
    if(this != &other){
        try{
             vec *p = new  vec[other.span->max_size()];
            delete [] span;
            span = p;
        }catch(std::bad_alloc&){
            std::cerr << "Exception: Span new failed;" << std::endl;
        }
    }
    return *this;
}

void Span::addNumbers(vecIter begin, vecIter end){
    while(begin != end){
        addNumber(*begin);
        ++begin;
    } 
}       

void Span::addNumber(unsigned int n){
    if(span->size() >= span->capacity())
        throw SpanFull();
    span->push_back(n);
}   

unsigned int Span::shortestSpan(){
    if(span->empty())
        throw SpanEmpty();
    if(span->size() == 1)
        throw SpanOneElement();
    std::sort(span->begin(), span->end());
    unsigned int shortDiff = UINT_MAX;
    size_t size = span->size() - 1;
    for(size_t i=0; i<size; i++) {
        unsigned int diff = span->at(i+1) - span->at(i);
        shortDiff = std::min(shortDiff, diff); 
    }
    return shortDiff;
}

unsigned int Span::longestSpan(){
    if(span->empty())
        throw SpanEmpty();
    if(span->size() == 1)
        throw SpanOneElement();
    std::sort(span->begin(), span->end());
    unsigned int longDiff = 0;
    size_t size = span->size() - 1;
    for(size_t i=0; i<size; i++) {
        unsigned int diff = span->at(i+1) - span->at(i);
        longDiff = std::max(longDiff, diff); 
    }
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