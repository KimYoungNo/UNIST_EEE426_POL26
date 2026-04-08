#include <cstdint>
#include "hls_stream.h"
#include "ap_axi_sdata.h"

namespace MAX
{
	static const uint32_t M = 128;
	static const uint32_t K = 64;
	static const uint32_t N = 128;

	static constexpr
	uint32_t DIM = M > N ? M :
			       N > K ? N : K;
}

template <typename LHT, typename RHT>
union convert { LHT lhs; RHT rhs; };

using cvt_fi = convert<float, uint32_t>;
using axiu_t = ap_axiu<32, 4, 5, 5>;
using axis_t = hls::stream<axiu_t>;

void
gemm(axis_t&, axis_t&, axis_t&, uint32_t, uint32_t, uint32_t);
