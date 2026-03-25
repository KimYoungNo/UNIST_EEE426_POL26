#include "vadd_ip.h"

void
TOP_VADD(int *a, int *b, int *c)
{
#pragma HLS INTERFACE m_axi port=a offset=slave depth=20
#pragma HLS INTERFACE m_axi port=b offset=slave depth=20
#pragma HLS INTERFACE m_axi port=c offset=slave depth=20

#pragma HLS INTERFACE s_axilite port=a bundle=CTRL
#pragma HLS INTERFACE s_axilite port=b bundle=CTRL
#pragma HLS INTERFACE s_axilite port=c bundle=CTRL
#pragma HLS INTERFACE s_axilite port=return bundle=CTRL

//#pragma HLS DATAFLOW

	for (int i=0; i<SIZE; ++i)
	{
//#pragma HLS PIPELINE
//#pragma HLS UNROLL
		c[i] = a[i] + b[i];
	}
}
