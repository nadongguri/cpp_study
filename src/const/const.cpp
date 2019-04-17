//http://www.cplusplus.com/forum/general/223039/
#include <iostream>

using namespace std;

void testFunction() //const //error: non-member function ‘void testFunction()’ cannot have cv-qualifier
{
	cout << "testFunction()" << endl;
	return;
}

int gmyprop;

class MyClass {
	private:
		int myprop {}; // priavte, init as 0 like myprop = 0;
		const int *myptr;
	public:
		MyClass() {
			//// const variables ////
			int c0 = 96, c0_0 = 96;
			int const c1 = 96; // ok
			const int c2 = 96; // ok
			// int c3 const = 96; // error: expected initializer before ‘const’
			// const int const c4 = 96; // error: duplicate ‘const’
			
			// c1 = 97; // error: assignment of read-only variable ‘c1’
			// c2 = 97; // error: assignment of read-only variable ‘c2’
			
			//// const pointers ////
			int* const p1_0 = &c0; // const for pointer address
			//int* const p1_1 = &c1; //error: invalid conversion from ‘const int*’ to ‘int*’ [-fpermissive]
			//int* const p1_2 = &c2; //error: invalid conversion from ‘const int*’ to ‘int*’ [-fpermissive]
			//int* const p1_3; //error: uninitialized const ‘p1_3’ [-fpermissive]
			int* const p1_3 = NULL;
			//p1_3 = &c0_0; //error: assignment of read-only variable ‘p1_3’
			
			//p1_0 = &c0_0; // error: assignment of read-only variable ‘p1_0’
			*p1_0 = 97; // Okay.

			const int* p2_0 = &c0; // const for value of address
			const int* p2_1 = &c1; // const for value of address
			const int* p2_2 = &c2; // const for value of address

			p2_1 = &c0; // Okay
			//*p2_2 = 97; // error: assignment of read-only location ‘* p2_2’

			//both
			const int* const p3_0 = &c0;
			const int* const p3_1 = &c1;
			const int* const p3_2 = &c2;

			int* const p_p1_0 = p1_0;
			//int* const p_p2_0 = p2_0; // error: invalid conversion from ‘const int*’ to ‘int*’ [-fpermissive]
			//int* const p_p2_1 = p2_2; // error: invalid conversion from ‘const int*’ to ‘int*’ [-fpermissive]
			//int* const p_p3_0 = p3_0; // error: invalid conversion from ‘const int*’ to ‘int*’ [-fpermissive]
			//int* const p_p3_1 = p3_1; // error: invalid conversion from ‘const int*’ to ‘int*’ [-fpermissive]
			//int* const p_p3_2 = p3_2; // error: invalid conversion from ‘const int*’ to ‘int*’ [-fpermissive]

			myptr = &myprop;

		};
		// A const method can't modify class properties:
		// int modMyprop1(const Myclass *this) so this->myprop++ 
		// int modMyprop1() const { return ++myprop; } 	// error: increment of member
								// 'MyClass::myprop' in
								// read-only object

		int modMyprop2() const { return myprop + 1; } // fine - myprop is untouched
		int modMyprop3()       { return ++myprop; } // this is not const, so it's
								// allowed to modify myprop;
								// on the other hand, it can't
								// be invoked by instances
								// of MyClass which are
								// declared 'const'

		// error: assignment of member ‘MyClass::myptr’ in read-only object
		// void modMyprop4() const { myptr = &gmyprop; }
};

int main()
{
	MyClass myinst1; // not const
	// myinst1 can invoke every method (const and not const)
	std::cout << "myinst1.modMyprop2(): " << myinst1.modMyprop2() << '\n';
	std::cout << "myinst1.modMyprop3(): " << myinst1.modMyprop3() << '\n';

	const MyClass myinst2;
	// myinst2 can invoke only const methods
	std::cout << "myinst2.modMyprop2(): " << myinst2.modMyprop2() << '\n';
	// error: passing 'const MyClass' as 'this' argument discards qualifiers:
	// std::cout << "myinst2.modMyprop3(): " << myinst2.modMyprop3() << '\n';
	return 0;
}
