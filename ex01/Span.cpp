#include "Span.hpp"

Span::Span(unsigned int N) try : span(new vec){
    std::cout << "Span: Unsigned int argument constructor called" << std::endl;
    span->reserve(N);
}catch(std::bad_alloc& e){
    std::cerr << "Span constructor: new failed" << std::endl;
}

Span::Span(const Span& other){
    std::cout << "Span: Copy constructor called" << std::endl;
    if(this != &other)
        *this = other;
}   
Span::~Span(){
    std::cout << "Span: Destructor called" << std::endl;
    delete span;
}
Span& Span::operator=(const Span& other){
    if(this != &other){
        try{
            vec *p = new vec;
            p->reserve(other.span->capacity());
            delete span;
            span = p;
        }catch(std::bad_alloc&){
            std::cerr << "Exception: Span new failed;" << std::endl;
        }
    }
    return *this;
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
    size_t len = span->size();
    unsigned int longDiff = span->at(len-1) - span->at(0);
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