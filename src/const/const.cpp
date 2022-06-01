// http://www.cplusplus.com/forum/general/223039/
#include <iostream>

using namespace std;

// void testFunction() const //error: non-member function ‘void testFunction()’ cannot have cv-qualifier
void testFunction()
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
			int c0 = 96;
            int c0_0 = 96;
			int const c1 = 96;
			const int c2 = 96;
			// int c3 const = 96; // error: expected initializer before ‘const’

            // Apple clang version 13.1.6 (clang-1316.0.21.2.5) warning: duplicate 'const' declaration specifier [-Wduplicate-decl-specifier]
            // error: duplicate ‘const’
			// const int const c4 = 96; 
			
			// c1 = 97; // error: assignment of read-only variable ‘c1’
			// c2 = 97; // error: assignment of read-only variable ‘c2’
			
			//// const pointers ////
            // const for pointer address
			int* const p1_0 = &c0;
			// int* const p1_1 = &c1; //error: invalid conversion from ‘const int*’ to ‘int*’ [-fpermissive]
			// int* const p1_2 = &c2; //error: invalid conversion from ‘const int*’ to ‘int*’ [-fpermissive]
			// int* const p1_3; //error: uninitialized const ‘p1_3’ [-fpermissive]
			int* const p1_3 = NULL;
			// p1_3 = &c0_0; //error: assignment of read-only variable ‘p1_3’
			// p1_0 = &c0_0; // error: assignment of read-only variable ‘p1_0’
			*p1_0 = 97;
            *p1_0 = 100;

            // const for value of address
			const int* p2_0 = &c0; // const for value of address
			const int* p2_1 = &c1; // const for value of address
			const int* p2_2 = &c2; // const for value of address
			p2_1 = &c0;
			//*p2_2 = 97; // error: assignment of read-only location ‘* p2_2’

			//both
			const int* const p3_0 = &c0;
			const int* const p3_1 = &c1;
			const int* const p3_2 = &c2;
            // p3_0 = &c1; // error
            // p3_0 = p3_1; // error
            // *p3_0 = 100; // error

            int* p_p1_0 = p1_0;
            p_p1_0 = &c0;
            // int *p_p2_0 = p2_0; // error
            // int *p_p3_0 = p3_0; // error
			int* const p_c_p1_0 = p1_0; // int* const p1_0
			// int* const p_c_p2_0 = p2_0; // error: invalid conversion from ‘const int*’ to ‘int*’ [-fpermissive]
			const int* c_p_p2_0 = p2_0; // const int* p2_0
			// int* const p_c_p3_0 = p3_0; // error: invalid conversion from ‘const int*’ to ‘int*’ [-fpermissive]
			const int* c_p_p3_0 = p3_0; // const int* const p3_0
            c_p_p3_0 = &c0;
            c_p_p3_0 = p3_0;
            // c_p_p3_0 = &p3_0; // error
            
            const int* const c_p_c_p3_0 = p3_0; // const int* const p3_0
            // c_p_c_p3_0 = &c0; // error
            // c_p_c_p3_0 = p3_0; // error
            const int* const *c_p_c_p3_1 = &p3_1;
            const int* const *c_pp_c_p3_0 = &p3_0;
            // const int const *c_t_c_p_p3_0 = p3_0; // warning or error, duplicate const declaration

			myptr = &myprop;
		};
		// A const method can't modify class properties:
		// int modMyprop1(const MyClass *this) so this->myprop++ 
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
