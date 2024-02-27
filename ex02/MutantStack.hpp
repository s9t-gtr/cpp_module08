#ifndef __MUTANTSTACK_HPP
# define __MUTANTSTACK_HPP

#include <iostream>
#include <deque>    

template <typename T, typename Container = std::deque<T> >
class MutantStack{
    public:
        MutantStack();
        MutantStack(Container c);
        MutantStack(const MutantStack& other);
        ~MutantStack();
        MutantStack& operator=(const MutantStack& other);
    public:
        T& top() const;
        void push(T elem);
        void pop();
    public:
        class iterator;
        class reverse_iterator;
        MutantStack<T, Container>::iterator begin() const ;
        MutantStack<T, Container>::iterator end() const ;
        MutantStack<T, Container>::reverse_iterator rbegin() const ;
        MutantStack<T, Container>::reverse_iterator rend() const ;
    private:
        Container deque;

    public:
        class iterator{
            public:
                iterator(const T* p);
                T operator=(const iterator& other);
                T operator*();
                MutantStack<T, Container>::iterator operator++();
                MutantStack<T, Container>::iterator operator++(T);
                MutantStack<T, Container>::iterator operator--();
                MutantStack<T, Container>::iterator operator--(T);
                bool operator!=(const iterator& other);
            private:
                T* p_;
        };
        class reverse_iterator{
            public:
                reverse_iterator(const T* p);
                T operator=(const reverse_iterator& other);
                T operator*();
                MutantStack<T, Container>::reverse_iterator operator++();
                MutantStack<T, Container>::reverse_iterator operator++(T);
                MutantStack<T, Container>::reverse_iterator operator--();
                MutantStack<T, Container>::reverse_iterator operator--(T);
                bool operator!=(const reverse_iterator& other);
            private:
                T* p_;
        };
        class DequeEmpty: public std::exception{
            public:
                const char* what() const throw();
        };
};

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(){

}
template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(Container c){
    //iterators実装後でいいか
    (void)c;
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack(){
    // delete deque;
}

template <typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack& other){
    if(this != &other){
        try{
            // std::deque<T> *p = new std::deque<T>[other.deque.capacity()];
            // *p = *(other.deque);
            // delete deque;
            deque = other.deque;
        }catch(std::bad_alloc&){
            std::cerr << "Error: new std::deque<T> failed" << std::endl;
        }
    }
    return *this;
}


/*========================================================
            member_functions
========================================================*/
template <typename T, typename Container>
T& MutantStack<T, Container>::top() const{
    if(deque.empty())
        throw DequeEmpty();
    return deque.back();
}

template <typename T, typename Container>
void MutantStack<T, Container>::push(T elem){
    return deque.push_back(elem);
}

template <typename T, typename Container>
void MutantStack<T, Container>::pop(){
    if(deque.empty())
        throw DequeEmpty();
    deque.pop_back();
    return ;
}

template <typename T, typename Container>
const char* MutantStack<T, Container>::DequeEmpty::what() const throw(){
    return "DequeEmpty";
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin() const{
    return iterator(&(*deque.begin()));
}
template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end() const{
    return iterator(&(*deque.end()));
}
template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rbegin() const{
    return iterator(&(*deque.rbegin()));
}
template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rend() const{
    return iterator(&(*deque.rend()));
}

/*============================================
            iterator classes
============================================*/
template <typename T, typename Container>
MutantStack<T, Container>::iterator::iterator(const T* p){
    p_ = const_cast<T*>(p);
}
template <typename T, typename Container>
MutantStack<T, Container>::reverse_iterator::reverse_iterator(const T* p){
    p_ = const_cast<T*>(p);
}
//--------------- = ---------------------------
template <typename T, typename Container>
T MutantStack<T, Container>::iterator::operator=(const iterator& other){
    p_ = other.p_;
}
template <typename T, typename Container>
T MutantStack<T, Container>::reverse_iterator::operator=(const reverse_iterator& other){
    p_ = other.p_;
}
//--------------- * ---------------------------
template <typename T, typename Container>
T MutantStack<T, Container>::iterator::operator*(){
    return *p_;
}
template <typename T, typename Container>
T MutantStack<T, Container>::reverse_iterator::operator*(){
    return *p_;
}
//--------------- ++ ---------------------------
template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::iterator::operator++(){
    p_ = ++p_;
    return *this;
}
template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::reverse_iterator::operator++(){
    p_ = p_--;
    return *this;
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::iterator::operator++(T){
    iterator it=iterator(*this);
    p_ = ++p_;
    return it;
}
template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::reverse_iterator::operator++(T){
    iterator it=iterator(*this);
    p_ = p_--;
    return it;
}

//--------------- -- ---------------------------
template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::iterator::operator--(){
    return *p_;
}
template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::reverse_iterator::operator--(){
    return *p_;
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::iterator::operator--(T){
    return *p_;
}
template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::reverse_iterator::operator--(T){
    return *p_;
}

//--------------- != ---------------------------
template <typename T, typename Container>
bool MutantStack<T, Container>::iterator::operator!=(const iterator& other){
    if(p_ != other.p_)
        return true;
    return false;
}
template <typename T, typename Container>
bool MutantStack<T, Container>::reverse_iterator::operator!=(const reverse_iterator& other){
    if(p_ != other.p_)
        return true;
    return false;
}


#endif