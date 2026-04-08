#include <cstdint>
#include "gemm_ip.h"

template <size_t RMAX, size_t CMAX>
static void
load(float mem[RMAX][CMAX], axis_t& axis,
	 uint32_t nrow, uint32_t ncol)
{
#pragma HLS INLINE off

	for (int r=0; r<nrow; ++r)
#pragma HLS LOOP_TRIPCOUNT min=0 max=RMAX
	for (int c=0; c<ncol; ++c)
	{
#pragma HLS LOOP_TRIPCOUNT min=0 max=CMAX
		cvt_fi cvt;
		axiu_t e = axis.read();
		cvt.rhs = (uint32_t)e.data.to_int();
		mem[r][c] = cvt.lhs;
	}
}

template <size_t RMAX, size_t CMAX>
static void
store(axis_t& axis, float mem[RMAX][CMAX],
	  uint32_t nrow, uint32_t ncol)
{
#pragma HLS INLINE off

	for (int r=0; r<nrow; ++r)
#pragma HLS LOOP_TRIPCOUNT min=0 max=RMAX
	for (int c=0; c<ncol; ++c)
	{
#pragma HLS LOOP_TRIPCOUNT min=0 max=CMAX
		cvt_fi cvt;
		cvt.lhs = mem[r][c];

		axiu_t e{cvt.rhs};
		e.keep = -1;
		e.last = (r==(nrow-1) && c==(ncol-1)) ? 1:0;
		axis.write(e);
	}
}

template <size_t MMAX, size_t NMAX, size_t KMAX>
static void
execute(float C[MMAX][NMAX],
		float A[MMAX][KMAX],
		float B[KMAX][NMAX],
		uint32_t M, uint32_t N, uint32_t K)
{
#pragma HLS INLINE off

	for (int m=0; m<M; ++m)
#pragma HLS LOOP_TRIPCOUNT min=0 max=MMAX
	for (int n=0; n<N; ++n)
	{
#pragma HLS LOOP_TRIPCOUNT min=0 max=NMAX
		float acc = 0.0f;

		for (int k=0; k<K; ++k)
		{
#pragma HLS LOOP_TRIPCOUNT min=0 max=KMAX
			acc += A[m][k] * B[k][n];
		}
		C[m][n] = acc;
	}
}

void
gemm(axis_t& C_axis, axis_t& A_axis, axis_t& B_axis,
	 uint32_t M, uint32_t N, uint32_t K)
{
#pragma HLS INTERFACE axis port=A_axis depth=MAX::DIM
#pragma HLS INTERFACE axis port=B_axis depth=MAX::DIM
#pragma HLS INTERFACE axis port=C_axis depth=MAX::DIM
#pragma HLS INTERFACE s_axilite port=M bundle=CTRL
#pragma HLS INTERFACE s_axilite port=N bundle=CTRL
#pragma HLS INTERFACE s_axilite port=K bundle=CTRL
#pragma HLS INTERFACE s_axilite port=return bundle=CTRL

	static float C[MAX::M][MAX::N];
	static float A[MAX::M][MAX::K];
	static float B[MAX::K][MAX::N];

	load<MAX::M, MAX::K>(A, A_axis, M, K);
	load<MAX::K, MAX::N>(B, B_axis, K, N);
	execute<MAX::M, MAX::N, MAX::K>(C, A, B, M, N, K);
	store<MAX::M, MAX::N>(C_axis, C, M, N);
}
