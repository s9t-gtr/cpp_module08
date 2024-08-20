#ifndef __MUTANTSTACK_HPP
# define __MUTANTSTACK_HPP

#include <iostream>
#include <deque>    
#include <stack>



template <typename T >
class MutantStack: public std::stack<T>{
    public:
        MutantStack();
        MutantStack(const MutantStack& other);
        virtual ~MutantStack();
        MutantStack& operator=(const MutantStack& other);
    public:
        // const T& top() const;
        // void push(T elem);
        // void pop();
        // size_t size();
        using std::stack<T>::top;
        using std::stack<T>::push;
        using std::stack<T>::pop;
        using std::stack<T>::size;
    public:
        class iterator;
        class reverse_iterator;
        MutantStack<T>::iterator begin() ;
        MutantStack<T>::iterator end()  ;
        MutantStack<T>::reverse_iterator rbegin()  ;
        MutantStack<T>::reverse_iterator rend()  ;

    private:
        using std::stack<T>::c;
        static MutantStack<T> *mutantStack;
        
    public:
        class iterator{
            public:
                iterator();
                iterator(typename std::stack<T>::container_type::iterator newIt);
                ~iterator();
                iterator& operator=(const iterator& other);
                T& operator*();
                MutantStack<T>::iterator operator++();
                MutantStack<T>::iterator operator++(T);
                MutantStack<T>::iterator operator--();
                MutantStack<T>::iterator operator--(T);
                bool operator!=(const iterator& other);
            private:
                typename std::stack<T>::container_type::iterator it;
                static const T nil;
        };
        
        class reverse_iterator{
            public:
                reverse_iterator();
                reverse_iterator(MutantStack<T> *mutantStack);
                reverse_iterator(typename std::stack<T>::container_type::reverse_iterator newIt);
                typename MutantStack<T>::reverse_iterator& operator=(const reverse_iterator& other);
                ~reverse_iterator();
                T& operator*();
                MutantStack<T>::reverse_iterator operator++();
                MutantStack<T>::reverse_iterator operator++(T);
                MutantStack<T>::reverse_iterator operator--();
                MutantStack<T>::reverse_iterator operator--(T);
                bool operator!=(const reverse_iterator& other);
            private:
                typename std::stack<T>::container_type::reverse_iterator it;
                static const T nil;
        };
        class DequeEmpty: public std::logic_error{
            public:
                DequeEmpty(const std::string message);
        };
        class DequeLimit: public std::logic_error{
            public:
                DequeLimit(const std::string message);
        };
};

//template <typename T>
// MutantStack<T>::deque;

template <typename T>
const T MutantStack<T>::iterator::nil = T();
template <typename T>
const T MutantStack<T>::reverse_iterator::nil = T();

template <typename T>
MutantStack<T>::MutantStack(): std::stack<T>(){
    mutantStack = this;
}
template <typename T>
MutantStack<T> *MutantStack<T>::mutantStack = 0;
// template <typename T>
// MutantStack<T>::MutantStack(std::stack<T> c): std::stack<T>(c){
//     //iterators実装後でいいか
//     (void)c;
// }
template <typename T>
MutantStack<T>::~MutantStack(){
    // for(typename ::iterator it=deque.begin(); it != deque.end(); it++){
    //     *it = 0;
    // }s
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other){
    if(this != &other){
        try{
            c = other.c;
        }catch(std::bad_alloc&){
            std::cerr << "Error: new std::deque<T> failed" << std::endl;
        }
    }
    return *this;
}

/*========================================================
            member_functions
========================================================*/
// template <typename T>
// const T& MutantStack<T>::top() const{
//     if(deque.empty())
//         throw DequeEmpty("Error top(): stack is empty");
//     return deque.back();
// }

// template <typename T>
// void MutantStack<T>::push(T elem){
//     if(deque.size() == deque.max_size())
//         throw DequeLimit("Error push(): stack is fully");
//     return deque.push_back(elem);
// }

// template <typename T>
// void MutantStack<T>::pop(){
//     if(deque.empty())
//         throw DequeEmpty("Error top(): stack is empty");
//     deque.pop_back();
//     return ;
// }

// template <typename T>
// size_t MutantStack<T>::size(){
//     return deque.size();
// }

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(){
    return iterator(c.begin());
}
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(){
    return iterator(c.end());
}
template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin(){
    return reverse_iterator(c.rbegin());
}
template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend(){
    return reverse_iterator(c.rend());
}

template <typename T>
MutantStack<T>::DequeEmpty::DequeEmpty(const std::string message): std::logic_error(message){}
template <typename T>
MutantStack<T>::DequeLimit::DequeLimit(const std::string message): std::logic_error(message){}
/*============================================
            iterator classes
============================================*/
template <typename T>
MutantStack<T>::iterator::iterator(){
    std::cout << "iterator: default constructor called" << std::endl;
}
template <typename T>
MutantStack<T>::reverse_iterator::reverse_iterator(){}
template <typename T>
MutantStack<T>::iterator::iterator(typename std::stack<T>::container_type::iterator newIt){
    it = newIt;
}
template <typename T>
MutantStack<T>::reverse_iterator::reverse_iterator(typename std::stack<T>::container_type::reverse_iterator newIt){
    it = newIt;
}

template <typename T>
MutantStack<T>::iterator::~iterator(){}
template <typename T>
MutantStack<T>::reverse_iterator::~reverse_iterator(){}

//--------------- = ---------------------------
template <typename T>
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator=(const iterator& other){
    it = other.it;
    return *this;
}
template <typename T>
typename MutantStack<T>::reverse_iterator& MutantStack<T>::reverse_iterator::operator=(const reverse_iterator& other){
    it = other.it;
    return *this;
}

//--------------- * ---------------------------
template <typename T>
T& MutantStack<T>::iterator::operator*(){
    if(mutantStack->size() == 0){
        return const_cast<T&>(nil);
    }
    return *it;
}
template <typename T>
T& MutantStack<T>::reverse_iterator::operator*(){
    if(mutantStack->size() == 0)
        return const_cast<T&>(nil);
    return *it;
}

//--------------- ++ ---------------------------
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator++(){
    if(mutantStack->size() == 0)
        return *this;
    ++it;
    return *this;
}
template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::reverse_iterator::operator++(){
    if(mutantStack->size() == 0)
        return *this;
    ++it;
    return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator++(T){
    if(mutantStack->size() == 0)
        return *this;
    iterator ret=iterator(*this);
    ++it;
    return ret;
}
template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::reverse_iterator::operator++(T){
    if(mutantStack->size() == 0)
        return *this;
    reverse_iterator ret =reverse_iterator(*this);
    ++it;
    return ret;
}

//--------------- -- ---------------------------
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator--(){
    if(mutantStack->size() == 0)
        return *this;
    --it;
    return *this;
}
template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::reverse_iterator::operator--(){
    if(mutantStack->size() == 0)
        return *this;
    ++it;
    return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator--(T){
    if(mutantStack->size() == 0)
        return *this;
    iterator ret = iterator(it);
    --it;
    return ret;
}
template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::reverse_iterator::operator--(T){
    if(mutantStack->size() == 0)
        return *this;
    reverse_iterator ret = reverse_iterator(it);
    return ret;
}

//--------------- != ---------------------------
template <typename T>
bool MutantStack<T>::iterator::operator!=(const iterator& other){
    if(it != other.it)
        return true;
    return false;
}
template <typename T>
bool MutantStack<T>::reverse_iterator::operator!=(const reverse_iterator& other){
    if(it != other.it)
        return true;
    return false;
}














//test functions 












template<typename Container>
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

template <typename Container>
void deepCopyTest(){
    Container stack, sub_stack;
    //push sub_stack
    for(size_t i=0;i<5;i++){
        sub_stack.push(i);
    }
    //copy
    stack = sub_stack;
    //push stack
    for(size_t i=0;i<5;i++){
        stack.push(i);
    }
    //confirm stack and sub_stack
    //stack
    std::cout << "stack contents" << std::endl;
    std::string::value_type size = stack.size();
    for(std::string::value_type i=0;i<size;i++){
        std::cout << stack.top() << ", ";
        stack.pop();
    }
    std::cout << std::endl;
    //sub_stack
    std::cout << "sub_stack contents" << std::endl;
    size = stack.size();
    for(std::string::value_type i=0;i<size;i++){
        std::cout << stack.top() << ", ";
        sub_stack.pop();
    }

    std::cout << std::endl;
}

template <typename Container>
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

template <typename Container>
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
