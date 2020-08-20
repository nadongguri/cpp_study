

/*
class_default.cpp:10:13: error: no matching function for call to ‘MyClass::MyClass()’
     MyClass nc;
             ^~
class_default.cpp:5:5: note: candidate: MyClass::MyClass(const MyClass&)
     MyClass(const MyClass&);
     ^~~~~~~
class_default.cpp:5:5: note:   candidate expects 1 argument, 0 provided
*/
#if 0
class MyClass
{
private:
    MyClass(const MyClass&); // Copy constructor is defined, so constructor is required to define!
};
#else
class MyClass
{
public:
	MyClass() = default; // The same as MyClass() {};
private:
    MyClass(const MyClass&); // Copy constructor is defined, so constructor is required to define!
};
#endif
  
int main()
{
    MyClass nc;
	return 0;
}
