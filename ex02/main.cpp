#include "MutantStack.hpp"
#include <stack>
typedef std::stack<int> IntStack;

int main()
{
    IntStack iStack, iStack2;
    for (int i = 0; i < 5; ++i) {
        iStack.push(i);
    }

    iStack2 = iStack;
    for (int i = 1; i < 6; ++i) {
        iStack2.push(i);
    } 
    std::cout << iStack.size() << "\n"
              << iStack2.size() << "\n"
              << std::boolalpha << (iStack == iStack2) << std::endl;
    MutantStack<int> stack;
    for (int i = 1; i < 5; i++) {
        stack.push(i);
    } 
    // stack.pop();
    MutantStack<int>::iterator it = stack.begin();
    MutantStack<int>::iterator itEnd = stack.end();
    std::cout << *it << std::endl;
    std::cout << *itEnd << std::endl;
    for(MutantStack<int>::iterator it2=stack.begin();it2 != itEnd;it2++){
        std::cout << *it2 << std::endl;
    }
    ++it;
    ++itEnd;
    std::cout << *it << std::endl;
    std::cout << *itEnd << std::endl;
}

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