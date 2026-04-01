#include <cstdint>
#include "ap_int.h"
#include "hls_stream.h"
#include "ap_axi_sdata.h"

static const size_t fifo_depth = 128;

using axiu_t = ap_axiu<32, 1, 1, 1>;
using axis_t = hls::stream<axiu_t>;
using fifo_t = hls::stream<int32_t>;

void vadd(axis_t&, axis_t&, axis_t&, uint32_t);
