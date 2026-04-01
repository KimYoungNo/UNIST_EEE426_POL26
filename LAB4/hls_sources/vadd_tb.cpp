#include <iostream>
#include "vadd_dma.h"

int
main()
{
	axis_t A;
	axis_t B;
	axis_t C;

	for (int i=0; i<fifo_depth; ++i)
	{
		axiu_t a{i};
		a.keep = -1;
		a.last = (i==(fifo_depth-1)) ? 1:0;
		A << a;

		axiu_t b{2*i};
		b.keep = -1;
		b.last = (i==(fifo_depth-1)) ? 1:0;
		B << b;
	}
	vadd(A, B, C, fifo_depth);

	for (int i=0; i<fifo_depth; ++i)
	{
		axiu_t c = C.read();

		std::cout
			<< "C["   << i
			<< "] = " << (int32_t)(c.data.to_int())
			<< std::endl;
	}
	return 0;
}
