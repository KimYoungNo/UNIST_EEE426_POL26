#include <cstdint>
#include "hls_stream.h"
#include "ap_axi_sdata.h"
#include "weights.h"

namespace MNIST
{
	static const uint32_t NUM = 140;
	static const uint32_t IMG_DIM = 28;
	static const uint32_t IMG_CLS = 10;
}

template <typename LHT, typename RHT>
union convert { LHT lhs; RHT rhs; };

using cvt_fi = convert<float, uint32_t>;
using axiu_t = ap_axiu<32, 4, 5, 5>;
using axis_t = hls::stream<axiu_t>;

void mnist_slp(axis_t&, axis_t&);
