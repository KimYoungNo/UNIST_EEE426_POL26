#include <iostream>
#include "gemm_ip.h"

int
main()
{
	uint32_t M = 10, N = 10, K = 5;
	axis_t C_axis, A_axis, B_axis;
	cvt_fi cvt;

	for (int i=0; i<M*K; ++i)
	{
		cvt.lhs = static_cast<float>(i*1e-1);
		axiu_t e{cvt.rhs};
		e.keep = -1;
		e.last = (i==(M*K-1));
		A_axis << e;
	}
	for (int i=0; i<K*N; ++i)
	{
		cvt.lhs = static_cast<float>(i*2e-1);
		axiu_t e{cvt.rhs};
		e.keep = -1;
		e.last = (i==(K*N-1));
		B_axis << e;
	}
	gemm(C_axis, A_axis, B_axis, M, N, K);

	for (int cr=0; cr<M; ++cr)
	{
		for (int cc=0; cc<N; ++cc)
		{
			axiu_t e = C_axis.read();
			cvt.rhs = e.data.to_int();
			std::cout << cvt.lhs << '\t';
		}
		std::cout << "\n";
	}
}
