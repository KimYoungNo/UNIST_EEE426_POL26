#include <iostream>
#include "vadd_ip.h"

int
main()
{
	int a[SIZE];
	int b[SIZE];
	int c[SIZE];

	for (int i=0; i<SIZE; ++i)
	{
		a[i] = 1 * i;
		b[i] = 2 * i;
	}
	vadd(a, b, c);

	for (int i=0; i<SIZE; ++i)
		std::cout
			<< "c["   << i
			<< "] = " << a[i]
			<< " + "  << b[i]
			<< " = "  << c[i]
			<< std::endl;
}
