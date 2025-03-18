#ifndef __SPAN_HPP
# define __SPAN_HPP

#include <vector>
#include <deque>
#include <list>
#define TEST_NUM 10000
#define EMPTY_LINE std::cout << std::endl

typedef std::vector<unsigned int> uVec;
typedef std::deque<unsigned int> uDeq;
typedef std::list<unsigned int> uList;
class Span{
    private:
        Span();
    public:
        Span(unsigned int N);
        Span(const Span& other);
        ~Span();
        Span& operator=(const Span& other);
    public:
        void addNumber(unsigned int number); 
		template <typename Container>
        void addNumbers(Container container); 
        unsigned int shortestSpan();
        unsigned int longestSpan();
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
void Span::addNumbers(Container container){
	if(span->size() + std::distance(container.begin(), container.end()) > span->capacity()) {
		throw std::runtime_error("can't store");
	}
	span->insert(span->end(), container.begin(), container.end());
}

#endif
