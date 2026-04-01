#include "ap_int.h"
#include "vadd_dma.h"

static void
load(fifo_t& in_fifo, axis_t& in_stream, uint32_t n)
{
#pragma HLS INLINE off
	for (int i=0; i<n; ++i)
	{
#pragma HLS LOOP_TRIPCOUNT min=0 max=fifo_depth
#pragma HLS PIPELINE II=1
		axiu_t e = in_stream.read();
		in_fifo.write((int32_t)e.data.to_int());
	}
}

static void
store(axis_t& out_stream, fifo_t& out_fifo, uint32_t n)
{
#pragma HLS INLINE off
	for (int i=0; i<n; ++i)
	{
#pragma HLS LOOP_TRIPCOUNT min=0 max=fifo_depth
#pragma HLS PIPELINE II=1
		axiu_t e{out_fifo.read()};
		e.keep = -1;
		e.last = i>=(n-1) ? 1:0;
		out_stream.write(e);
	}
}

static void
execute(fifo_t& out_fifo, fifo_t& in1_fifo,
		fifo_t& in2_fifo, uint32_t n)
{
#pragma HLS INLINE off
	for (int i=0; i<n; ++i)
	{
#pragma HLS LOOP_TRIPCOUNT min=0 max=fifo_depth
#pragma HLS PIPELINE II=1
		out_fifo.write(in1_fifo.read() + in2_fifo.read());
	}
}

void
vadd(axis_t& in1_stream, axis_t& in2_stream,
	 axis_t& out_stream, uint32_t n)
{
#pragma HLS INTERFACE axis port=in1_stream depth=fifo_depth
#pragma HLS INTERFACE axis port=in2_stream depth=fifo_depth
#pragma HLS INTERFACE axis port=out_stream depth=fifo_depth
#pragma HLS INTERFACE s_axilite port=n
#pragma HLS INTERFACE ap_ctrl_none port=return

	static fifo_t in1_fifo("in1_fifo");
	static fifo_t in2_fifo("in2_fifo");
	static fifo_t out_fifo("out_fifo");
#pragma HLS STREAM variable=in1_fifo depth=fifo_depth
#pragma HLS STREAM variable=in2_fifo depth=fifo_depth
#pragma HLS STREAM variable=out_fifo depth=fifo_depth

#pragma HLS DATAFLOW

	load(in1_fifo, in1_stream, n);
	load(in2_fifo, in2_stream, n);
	execute(out_fifo, in1_fifo, in2_fifo, n);
	store(out_stream, out_fifo, n);
}
