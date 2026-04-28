#include <iostream>
#include "slp_ip.h"
#include "images.h"

int main()
{
	axis_t images, pred;
	cvt_fi cvt;

	for (size_t n=0; n<MNIST::NUM; ++n)
	for (size_t d=0; d<784; ++d)
	{
		cvt.lhs = IMAGES[n][d];
		axiu_t e{cvt.rhs};
		e.keep = -1;
		e.last = (n==(MNIST::NUM-1)) && (d==783);
		images << e;
	}
	mnist_slp(images, pred);

	for (size_t n=0; n<MNIST::NUM; ++n)
	{
		if (n%10 == 0) std::cout << "\n";
		std::cout << pred.read().data << "   ";
	}
	std::cout << "\n";
	return 0;
}
