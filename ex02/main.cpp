#include "MutantStack.hpp"
#include <list>
typedef std::list<int> list;
int main()
{
    MutantStack<int> stack;
    for (int i = 1; i < 5; i++) {
        stack.push(i);
    }
        MutantStack<int>::iterator it;
        it = stack.begin();
        
        MutantStack<int>::iterator it2;
        it2 = it;

        MutantStack<int>::iterator it3(it);
        MutantStack<int>::iterator it4(stack.begin());


        std::cout << *it << std::endl;
        it++;
        std::cout << *it << std::endl;
        std::cout << *it2 << std::endl;
        it2++;
        std::cout << *it2 << std::endl;
        std::cout << *it3 << std::endl;
        it3++;
        std::cout << *it3 << std::endl;
        std::cout << *it4 << std::endl;
        it4++;
        std::cout << *it4 << std::endl;
    // stack.pop();
    // {
    //     MutantStack<int>::iterator it = stack.end();
    //     it--;
    //     std::cout << *it << std::endl;
    //     it--;
    //     std::cout << *it << std::endl;
    //     --it;
    //     std::cout << *it << std::endl;
    // }   
    {  
        // MutantStack<int>::reverse_iterator it;

        // it++;
        // std::cout<< *it << std::endl;

        // it++;
        // std::cout<< *it << std::endl;
        // it++;
        // std::cout<< *it << std::endl;

    }
}
        // { // list iterator test
        //     list lst ;
        //     for (int i = 0; i < 5; ++i) {
        //         lst.push_back(i);
        //     }
        //     list::iterator it;
        //     it = lst.begin();
            
        //     list::iterator it2;
        //     it2 = it;

        //     list::iterator it3(it);
        //     list::iterator it4(lst.begin());


        //     std::cout << *it << std::endl;
        //     it++;
        //     std::cout << *it << std::endl;
        //     std::cout << *it2 << std::endl;
        //     it2++;
        //     std::cout << *it2 << std::endl;
        //     std::cout << *it3 << std::endl;
        //     it3++;
        //     std::cout << *it3 << std::endl;
        //     std::cout << *it4 << std::endl;
        //     it4++;
        //     std::cout << *it4 << std::endl;
        // } 

/* 代入はディープコピー
IntStack iStack, iStack2;
for (int i = 0; i < 5; ++i) {
    iStack.push(i);
}

iStack2 = iStack;
for (int i = 0; i < 5; ++i) {
    iStack2.push(i);
} 
std::cout << iStack.size() << "\n"
            << iStack2.size() << "\n"
            << std::boolalpha << (iStack == iStack2) << std::endl;

*/