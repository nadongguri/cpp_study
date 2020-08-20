
int main(void) {
    constexpr int val = 3;
    int val2 = 2;
    // constexpr int val3 = val2;
    #if 0
	5:26: error: the value of ‘val2’ is not usable in a constant expression
     constexpr int val3 = val2;
                          ^~~~
	4:9: note: ‘int val2’ is not const
     int val2 = 2;
	if val2 is const, it compiles
	#endif

    return 0;
}
