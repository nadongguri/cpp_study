class MyClass {
public:
    MyClass(int a) {
    }

    // CASE 1
    // MyClass(float) = delete;
    // CASE 2
    // MyClass& operator=(const MyClass&) = delete;
};

int main() {
    MyClass A(10);
    MyClass B(10.25); //CASE 1 error: call of overloaded ‘MyClass(double)’ is ambiguous
    A = B; //CASE2 error: use of deleted function ‘MyClass& MyClass::operator=(const MyClass&)’
    return 0;
}
