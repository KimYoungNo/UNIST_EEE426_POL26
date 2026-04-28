#include <cstdint>
#include "slp_ip.h"

template <size_t NUM, size_t DIM>
static void
load(float mem[NUM][DIM*DIM], axis_t& axis)
{
#pragma HLS INLINE off
	for (size_t n=0; n<NUM; ++n)
	for (size_t d=0; d<DIM*DIM; ++d)
	{
		cvt_fi cvt;
		axiu_t e = axis.read();
		cvt.rhs = e.data.to_int();
		mem[n][d] = cvt.lhs;
	}
}

template <size_t NUM>
static void
store(axis_t& axis, uint32_t mem[NUM])
{
#pragma HLS INLINE off
	for (size_t n=0; n<NUM; ++n)
	{
		axiu_t e{mem[n]};
		e.keep = -1;
		e.last = (n == (NUM-1));
		axis.write(e);
	}
}

template <size_t NUM, size_t DIM, size_t CLS>
static void
execute(uint32_t y[NUM], float x[NUM][DIM*DIM],
		const float a[CLS][DIM*DIM], const float b[CLS])
{
#pragma HLS INLINE off
	for (size_t n=0; n<NUM; ++n)
	{
		uint32_t pred = 0;
		float best;

		for (size_t c=0; c<CLS; ++c)
		{
			float prob = b[c];

			for (size_t d=0; d<DIM*DIM; ++d)
			{
				prob += a[c][d] * x[n][d];
			}
			pred = prob > best ? c : pred;
			best = (c == 0) 	 ? prob :
				   (prob > best) ? prob : best;
		}
		y[n] = pred;
	}
}

void mnist_slp(axis_t& mnist_img, axis_t& mnist_pred)
{
#pragma HLS INTERFACE axis port=mnist_img depth=MNIST::NUM
#pragma HLS INTERFACE axis port=mnist_pred depth=MNIST::NUM
#pragma HLS INTERFACE ap_ctrl_none port=return

	float img[MNIST::NUM][MNIST::IMG_DIM*MNIST::IMG_DIM];
	uint32_t pred[MNIST::NUM];

	load<MNIST::NUM, MNIST::IMG_DIM>(img, mnist_img);
	execute<MNIST::NUM, MNIST::IMG_DIM, MNIST::IMG_CLS>
	(pred, img, FC_WEIGHT, FC_BIAS);
	store<MNIST::NUM>(mnist_pred, pred);
}
