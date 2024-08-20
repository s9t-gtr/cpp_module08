#ifndef __SPAN_HPP
# define __SPAN_HPP

#include <iostream>
#include <vector>
typedef std::vector<unsigned int>::iterator vecIter;
typedef std::vector<unsigned int> vec;

class Span{
    private:
        Span();
    public:
        Span(unsigned int N);
        Span(const Span& other);
        ~Span();
        Span& operator=(const Span& other);
    public:
        void addNumber(unsigned int n); 
        unsigned int shortestSpan();
        unsigned int longestSpan();
        void getMinMax();
    private:
        std::vector<unsigned int> *span;

    public:
        class SpanNotFound: public std::exception{
            public:
                const char* what() const throw();
        };
        class SpanEmpty: public std::exception{
            public:
                const char* what() const throw();
        };
        class SpanOneElement: public std::exception{
            public:
                const char* what() const throw();
        };
        class SpanFull: public std::exception{
            public:
                const char* what() const throw();
        };
         
};

#endif