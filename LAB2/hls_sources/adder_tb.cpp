#include <iostream>
#include "adder_ip.h"
	
int main()
{
	int a = 1;
	int b = 5;
	int c;
		
	adder(a, b, c);
		
	std::cout << c << std::endl;
	return 0;
}