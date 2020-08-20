#include <iostream>

// #define ERROR
#define PUBLIC
// #define PROTECTED
// #define PRIVATE

class Base {
 public:
    Base() { 
        public_val = 1;
        protected_val = 2;
        private_val = 3;
    };
    int public_val;
 protected:
    int protected_val;
 private:
    int private_val;
};

#ifdef PUBLIC
class Derived : public Base {
#elif defined(PROTECTED)
class Derived : protected Base {
#elif defined(PRIVATE)
class Derived : private Base {
#else
    #error
#endif
 public:
    Derived() {
        std::cout << "in Derived() public_val " << public_val << std::endl;
        std::cout << "in Derived() protected_val " << protected_val << std::endl;
        #ifdef ERROR
        std::cout << "in Derived() private_val " << private_val << std::endl; // error: ‘int Base::private_val’ is private within this context
        #endif
    }
#if defined(PROTECTED) || defined(PUBLIC)
    void set_protected_val(int val) {
        protected_val = val;
        std::cout << "protected_val " << protected_val << std::endl;
    }
#endif
};

int main(void) {
    Derived derived;
#ifdef PUBLIC
    derived.public_val = 3;
#endif
#if defined(PROTECTED) || defined(PUBLIC)
    derived.set_protected_val(5);
#endif

#ifdef PRIVATE
    #ifdef ERROR
    derived.public_val = 4; // error: ‘int Base::public_val’ is inaccessible within this context
    #endif
#endif
    return 0;
}
