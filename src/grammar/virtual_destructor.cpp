#include <iostream>

// #define ERROR
// #define WRONG

class P {
 public:
    P() { std::cout << "P constructor" << std::endl; }
    #ifdef WRONG
    ~P() { std::cout << "P destructor" << std::endl; } // ~C() never be called
    #else
    virtual ~P() { std::cout << "P destructor" << std::endl; }
    #endif
    int PTask1() { std::cout << "PTask1" << std::endl; }
};

class C : public P {
 public:
    C() { std::cout << "C constructor" << std::endl; }
    ~C() { std::cout << "C destructor" << std::endl; }
    int CTask1() { std::cout << "CTask1" << std::endl; }
};

int main(void) {
    class P* p = new C();
    p->PTask1();
  #ifdef ERROR
    p->CTask1(); // error: ‘class P’ has no member named ‘CTask1’; did you mean ‘PTask1’?
  #endif
    delete p;
    return 0;
}
