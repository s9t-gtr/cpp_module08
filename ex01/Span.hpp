#ifndef __SPAN_HPP
# define __SPAN_HPP

#include <stdexcept>
#include <deque>
#include <list>
#include <set>
#include <vector>

#define TEST_NUM 10000
#define EMPTY_LINE std::cout << std::endl

typedef std::vector<int> uVec;
typedef std::deque<int> uDeq;
typedef std::list<int> uList;
typedef std::set<int> uSet;

class Span{
    private:
        Span();
    public:
        Span(int N);
        Span(const Span& other);
        ~Span();
        Span& operator=(const Span& other);
    public:
        void addNumber(int number); 
		template <typename Container>
        void addNumber(Container container); 
        int shortestSpan();
        int longestSpan();
        void getMinMax();
    private:
        uVec *span;

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

template <typename Container>
void Span::addNumber(Container container){
	if(span->size() + std::distance(container.begin(), container.end()) > span->capacity()) {
		throw std::runtime_error("can't store");
	}
	span->insert(span->end(), container.begin(), container.end());
}

#endif
