#include "MutantStack.hpp"
#include <list>


//utils -----------------------
typedef std::stack<int> IntStack;
typedef std::list<int> IntList;
typedef std::list<std::string> strList;

#define NEW_LINE std::cout << std::endl;
#define EMPTY_LINE std::cout << "\n\n\n";
#define MUTANT_STACK std::cout << "MutantStack--------" << std::endl;
#define STD_LIST std::cout << "std::list--------" << std::endl;
#define STD_STACK_INT std::cout << "std::stack<int>--------" << std::endl;
void testTitle(const std::string test_name);
//-----------------------------

void subjectTest();
void stackFunctionsTest();
void deepCopyTest();
void iteratorTest();

int main()
{
    subjectTest();
    stackFunctionsTest();
        //- push()
        //- pop()
        //- top()
    deepCopyTest();
    iteratorTest();
}    
    // IntStack iStack, iStack2;
    // for (int i = 0; i < 5; ++i) {
    //     iStack.push(i);

    // iStack2 = iStack;
    // for (int i = 1; i < 6; ++i) {
    //     iStack2.push(i);
    // } 
    // std::cout << iStack.size() << "\n"
    //           << iStack2.size() << "\n"
    //           << std::boolalpha << (iStack == iStack2) << std::endl;
    // MutantStack<int> stack;
    // for (int i = 1; i < 5; i++) {
    //     stack.push(i);
    // } 
    // // stack.pop();
    // MutantStack<int>::iterator it = stack.begin();
    // MutantStack<int>::iterator itEnd = stack.end();
    // std::cout << *it << std::endl;
    // std::cout << *itEnd << std::endl;
    // for(MutantStack<int>::iterator it2=stack.begin();it2 != itEnd;it2++){
    //     std::cout << *it2 << std::endl;
    // }
    // ++it;
    // ++itEnd;
    // std::cout << *it << std::endl;
    // std::cout << *itEnd << std::endl;


//  代入はディープコピー
// IntStack iStack, iStack2;
// for (int i = 0; i < 5; ++i) {
//     iStack.push(i);
// }

// iStack2 = iStack;
// for (int i = 0; i < 5; ++i) {
//     iStack2.push(i);
// } 
// std::cout << iStack.size() << "\n"
//             << iStack2.size() << "\n"
//             << std::boolalpha << (iStack == iStack2) << std::endl;
void testTitle(const std::string test_name){
    std::cout << std::endl << "=================================================" << std::endl;
    std::cout << "|   " << test_name << std::endl;
    std::cout << "=================================================" << std::endl;
}

void subjectTest_mutantStack();
void subjectTest(){
    testTitle("subject test");
    subjectTest_mutantStack();
    subjectTest<std::list<int> >();
    subjectTest<std::deque<int> >();
    subjectTest<std::vector<int> >();
}
void subjectTest_mutantStack(){
    std::cout << "---- Mutant Stack test" << std::endl;

    MutantStack<int> mstack;
    mstack.push(5);

    mstack.push(17);
    
    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;
    mstack.push(3); 
    mstack.push(5); 
    mstack.push(737); 
    //[...] 
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin(); 
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it; 
    }
    std::stack<int> s(mstack); 
}

void stackFunctionsTest(){
   testTitle("stack functions test");
   STD_STACK_INT
   {
        IntStack stack;
        {
            // std::cout << "exec top() for empty stack" << std::endl;
            //stack.top(); //<- undefined behavior (segv)
        }
        std::cout << "stack.size(): " << stack.size() << std::endl;
        std::cout << "exec push(): 0~4" << std::endl;
        for (size_t i = 0; i < 5; ++i){
            stack.push(i);
        }
        std::cout << "stack.size(): " << stack.size() << std::endl;
        std::cout << "exec top(): " << stack.top() << std::endl;
        std::cout << "exec pop(): 4~0" << std::endl;
        for (int i = 0; i < 5; ++i) {
            stack.pop(); 
        }
        std::cout << "stack.size(): " << stack.size() << std::endl;
        {
            // std::cout << "exec pop() for empty stack" << std::endl;
            // stack.pop(); //<- undefined behavior
        }
    }
    MUTANT_STACK
    {
        try{
            MutantStack<int> stack;
            {
                // std::cout << "exec top() for empty stack" << std::endl;
                // stack.top(); //<- undefined behavior
            }
            std::cout << "stack.size(): " << stack.size() << std::endl;
            std::cout << "exec push(): 0~4" << std::endl;
            for (size_t i = 0; i < 5; ++i){
                stack.push(i);
            }
            std::cout << "stack.size(): " << stack.size() << std::endl;
            std::cout <<"exec top(): " << stack.top() << std::endl;
            std::cout << "exec pop(): 4~0" << std::endl;
            for (int i = 0; i < 5; ++i){
                stack.pop(); 
            }
            std::cout << "stack.size(): " << stack.size() << std::endl;
            {
                // std::cout << "exec pop() for empty stack" << std::endl;
                // stack.pop(); //<- undefined behavior(exception) 
            }
        }catch(MutantStack<int>::DequeEmpty& e){
            std::cerr << e.what() << std::endl;
        }
    }
}
    
void deepCopyTest(){
    testTitle("deep copy test");
    STD_STACK_INT
    {
        deepCopyTest<std::stack<int> >();
    }
    MUTANT_STACK
    {
        deepCopyTest<MutantStack<int> >();
    }
}

void iteratorTest_emptyStack();
void iteratorTest_increment();
void iteratorTest_decrement();

void iteratorTest_emptyStack_begin();
void iteratorTest_emptyStack_end();

void iteratorTest_increment_overStackSize();
void iteratorTest_increment_overStackSize_reverseIterator();

void iteratorTest_decrement();

void iteratorTest_indirect();
void iteratorTest(){
    testTitle("iterator test");
    iteratorTest_emptyStack();
    iteratorTest_increment();
    // iteratorTest_decrement();
    iteratorTest_indirect();
}

void iteratorTest_emptyStack(){
    testTitle("---- empty stack test");
    iteratorTest_emptyStack_begin();
    iteratorTest_emptyStack_end();
}

void iteratorTest_emptyStack_begin(){
    testTitle("---- ---- begin()");
    STD_LIST
    {
        iteratorTest_emptyStack_begin<std::list<int> >();
    }
    MUTANT_STACK
    {
        iteratorTest_emptyStack_begin<MutantStack<int> >();
    }
}

void iteratorTest_emptyStack_end(){
    testTitle("---- ---- end()");
    STD_LIST
    {
        iteratorTest_emptyStack_end<std::list<int> >();
    }
    MUTANT_STACK
    {
        iteratorTest_emptyStack_end<MutantStack<int> >();
    }
}

void iteratorTest_increment(){
    testTitle("---- increment test");
    iteratorTest_increment_overStackSize();
    iteratorTest_increment_overStackSize_reverseIterator();
}

void iteratorTest_increment_overStackSize(){
    testTitle("---- ---- increment over stack size");
    STD_LIST
    {
        IntList itList;
        for(size_t i=0;i<5;i++){
            itList.push_back(i);
        }
        IntList::iterator it=itList.begin();
        for(;it!=itList.end();it++){
            std::cout << *it << std::endl;
        }
        std::cout << " achieve end()" << std::endl;
        for(size_t i=0;i<10;i++){
            it++;
            std::cout << *it << std::endl;
        }
        std::cout << "copy" << std::endl;
        IntList::iterator cpIt = it;
        std::cout << "copy iterator :" << *cpIt << std::endl;
    }
    MUTANT_STACK
    {
        MutantStack<int> stack;
        MutantStack<int>::iterator it=stack.begin();
        for(size_t i=0;i<5;i++){
            stack.push(i);
        }
        it=stack.begin();
        for(;it!=stack.end();it++){
            std::cout << *it << std::endl;
        }
        std::cout << " achieve end()" << std::endl;
        for(size_t i=0;i<10;i++){
            it++;
            std::cout << *it << std::endl;
        }
        std::cout << "copy" << std::endl;
        MutantStack<int>::iterator cpIt = it;
        std::cout << "copy iterator :" <<  *cpIt << std::endl;
    }
}

void iteratorTest_increment_overStackSize_reverseIterator(){
    testTitle("---- ---- increment over stack size by reverse iterator");
    STD_LIST
    {
        IntList itList;
        for(size_t i=0;i<5;i++){
            itList.push_back(i);
        }
        IntList::reverse_iterator it=itList.rbegin();

        for(;it!=itList.rend();it++){
            std::cout << *it << std::endl;
        }
        std::cout << " achieve rend()" << std::endl;
        for(size_t i=0;i<10;i++){
            it++;
            std::cout << *it << std::endl;
        }
        std::cout << "copy" << std::endl;
        IntList::reverse_iterator cpIt = it;
        std::cout << "copy iterator :" <<  *cpIt << std::endl;
    }
    MUTANT_STACK
    {
        MutantStack<int> stack;
        for(size_t i=0;i<5;i++){
            stack.push(i);
        }
        MutantStack<int>::reverse_iterator it=stack.rbegin();

        for(;it!=stack.rend();it++){
            std::cout << *it << std::endl;
        }
        std::cout << " achieve rend()" << std::endl;
        // for(size_t i=0;i<10;i++){
        //     it++;
        //     std::cout << *it << std::endl;
        // }
        // std::cout << "copy" << std::endl;
        // MutantStack<int>::reverse_iterator cpIt = it;
        // std::cout << "copy iterator :" <<  *cpIt << std::endl;
    }
}

void iteratorTest_decrement_for_indirect();
void iteratorTest_indirect(){
   iteratorTest_decrement_for_indirect();
}

void iteratorTest_decrement_for_indirect(){
   STD_LIST
   {
       IntList itList;
       IntList::iterator it;
    //    std::cout << "empty stack: " << *it << std::endl;//segv

       for(size_t i=0;i<5;i++){
           itList.push_back(i);
       }
        it = itList.begin();
       IntList::iterator itEnd = itList.end();
       while(it != itEnd){
           std::cout <<--*it << std::endl;
           it++;
       }
       std::cout << "end() indirect" << std::endl;
       std::cout << *it << std::endl;

   }
   MUTANT_STACK
   {
       MutantStack<int> stack;
       MutantStack<int>::iterator it;
    //    std::cout << "empty stack: " << *it << std::endl; //segv
       for(size_t i=0;i<5;i++){
           stack.push(i);
       }
        it = stack.begin();
       MutantStack<int>::iterator itEnd = stack.end();
       while(it != itEnd){
           std::cout << --*it << std::endl;
           it++;
       }
       std::cout << "end() indirect" << std::endl;
       std::cout << *it << std::endl;
   }
}

