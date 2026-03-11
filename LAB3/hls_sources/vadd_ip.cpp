#include "vadd_ip.h"

void
vadd(int *a, int *b, int *c)
{
#pragma HLS INTERFACE m_axi port=a offset=slave depth=20
#pragma HLS INTERFACE m_axi port=b offset=slave depth=20
#pragma HLS INTERFACE m_axi port=c offset=slave depth=20

#pragma HLS INTERFACE s_axilite port=a bundle=CTRL
#pragma HLS INTERFACE s_axilite port=b bundle=CTRL
#pragma HLS INTERFACE s_axilite port=c bundle=CTRL
#pragma HLS INTERFACE s_axilite port=return bundle=CTRL

	for (int i=0; i<SIZE; ++i)
	{
		c[i] = a[i] + b[i];
	}

}
