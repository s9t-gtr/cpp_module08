#ifndef __MUTANTSTACK_HPP
# define __MUTANTSTACK_HPP

#include <iostream>
#include <typeinfo>
#include <deque>    
#include <stack>

template <typename T, class Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>{
    public:
        MutantStack();
        MutantStack(const MutantStack& other);
        virtual ~MutantStack();
        MutantStack& operator=(const MutantStack& other);
    public:
		typedef typename Container::iterator iterator;
		typedef typename Container::reverse_iterator reverse_iterator;
		typedef typename Container::const_iterator const_iterator;
		typedef typename Container::const_reverse_iterator const_reverse_iterator;

        using std::stack<T, Container>::top;
        using std::stack<T, Container>::push;
        using std::stack<T, Container>::pop;
        using std::stack<T, Container>::size;

		iterator begin();
		iterator end();
		reverse_iterator rbegin();
		reverse_iterator rend();
		const_iterator begin() const;
		const_iterator end() const;
		const_reverse_iterator rbegin() const;
		const_reverse_iterator rend() const;
	private:
		using std::stack<T, Container>::c;
};

template <typename T, class Container>
MutantStack<T, Container>::MutantStack(){}

template <typename T, class Container>
MutantStack<T, Container>::~MutantStack(){}

template <typename T, class Container>
MutantStack<T, Container>::MutantStack(const MutantStack& other): Container(other){}

template <typename T, class Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack& other) {
    if (this != &other) {
        this->c = other.c; // stackのprotectedメンバc（Container）を直接代入
    }
    return *this;
}

/*======================================================
 * Member_functions
========================================================*/

template <typename T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin() {
	return this->c.begin(); 
}
template <typename T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end() {
	return this->c.end(); 
}
template <typename T, class Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rbegin() {
	return this->c.rbegin(); 
}
template <typename T, class Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rend() {
	return this->c.rend(); 
}


template <typename T, class Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::begin() const {
	return this->c.begin(); 
}
template <typename T, class Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::end() const {
	return this->c.end(); 
}
template <typename T, class Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rbegin() const {
	return this->c.rbegin(); 
}
template <typename T, class Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rend() const {
	return this->c.rend(); 
}

/*========================================================
 * Test functions
========================================================*/
template <class Container>
void subjectTest(){
    std::cout << "---- "<< typeid(Container).name() << std::endl; //C

    Container container;
    container.push_back(5);

    container.push_back(17);
    
    std::cout << container.back() << std::endl;

    container.pop_back();

    std::cout << container.size() << std::endl;
    container.push_back(3); 
    container.push_back(5); 
    container.push_back(737); 
    //[...] 
    container.push_back(0);

    typename Container::iterator it = container.begin();
    typename Container::iterator ite = container.end();
    
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it; 
    }
    // s(container); 

}

template <class Container>
void deepCopyTest(){
    Container stack, sub_stack;
    //push sub_stack
	sub_stack.push(1);
	sub_stack.push(2);
	sub_stack.push(3);
    //copy
    stack = sub_stack;
	stack.push(4);
	for (size_t i = 0; i < 3; i++) {
		std::cout << sub_stack.top() << std::endl;
		sub_stack.pop();
	}
	std::cout << "stack.size()" << sub_stack.size() << std::endl;

	for (size_t i = 0; i < 4; i++) {
		std::cout << stack.top() << std::endl;
		stack.pop();
	}
	std::cout << "sub_stack.size()" << stack.size() << std::endl;
    //stack
    std::cout << std::endl;
}

template <class Container>
void iteratorTest_emptyStack_begin(){
    Container container;
    typename Container::iterator it = container.begin();
    std::cout << "it++" << std::endl;
    for(size_t i=0;i<5;i++){
        std::cout << &it << std::endl;
        std::cout << *it << std::endl;
        it++; //--itでもit--でも++itでも動作は変わらない 
    }
    std::cout << "it--" << std::endl;
    for(size_t i=0;i<3;i++){
        std::cout << &it << std::endl;
        std::cout << *it << std::endl;
        it--;
    }
    std::cout << "++it" << std::endl;
    for(size_t i=0;i<2;i++){
        std::cout << &it << std::endl;
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << "--it" << std::endl;
    for(size_t i=0;i<4;i++){
        std::cout << &it << std::endl;
        std::cout << *it << std::endl;
        --it; 
    }
}

template <class Container>
void iteratorTest_emptyStack_end(){
    Container container;
    typename Container::iterator it = container.end();
    std::cout << &it << std::endl;
    std::cout << *it << std::endl;
    it++;
    std::cout << &it << std::endl;
    std::cout << *it << std::endl;
    it++;
    std::cout << &it << std::endl;
    std::cout << *it << std::endl;
    it--;
    std::cout << &it << std::endl;
    std::cout << *it << std::endl;
}

#endif
