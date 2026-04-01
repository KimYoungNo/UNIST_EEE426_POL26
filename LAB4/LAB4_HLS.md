## LAB 4: Vitis HLS - Vector Add w. DMA

### Vitis HLS Tutorial

&emsp;In this lab, the IP `vadd` uses new `pragma`s:  
```cpp
#pragma HLS INTERFACE axis
#pragma HLS INLINE
#pragma HLS LOOP_TRIPCOUNT min=... max=...
#pragma HLS STREAM variable=... depth=...
```

&emsp;and new classes:
```cpp
ap_axiu<D, U, TI, TD>
hls::stream<value_type>
```

---

#### `ap_axiu<D, U, TI, D>`

&emsp;`ap_axiu<>` class is a parameterized alias of `hls::axis<>`. The letter '`u`' at the end of the class name stands for `unsigned`, meaning its data fields is of type `ap_uint<>`&mdash;the variant whose data field is `signed`(`ap_int<>`) is named `ap_axis<>`. Data transfered via AXI-Streaming protocol (`AXIS`) follows the data structure defined by either `ap_axis<>` or `ap_axiu<>`.  
&emsp;In this lab, we only use `ap_axiu<>` because it is more convenient to treat data as raw '**32-bit**', avoiding sign-bit concerns.

```cpp
// in "ap_axi_sdata.h"...
template <int D, int U, int TI, int TD>
struct ap_axiu
{
	ap_uint<D>       data;
    ap_uint<(D+7)/8> keep;
    ap_uint<(D+7)/8> strb;
    ap_uint<U>       user;
    ap_uint<1>       last;
    ap_uint<TI>      id;
    ap_uint<TD>      dest;
};
```

---

#### `hls::stream<DATA_TYPE>`

&emsp;`hls::stream<>` class is a template class that models a hardware FIFO (First-In, First-Out). Although it is internally written using `std::deque<>`, operations such as random access (`operator[]`), copying (`operator=`) are **strictly prohibited**. Only sequential insertion at the back and removal from the front of the queue are allowed.

```cpp
// example type using hls::stream as a simple fifo
using fifo_t = hls::stream<int32_t>;

// example type using hls::stream in top function port
// with AXIS protocol
using axis_t = hls::stream<ap_axiu<32, 1, 1, 1>>;

// representative method when push & pop elements
// in the hls::stream
static hls::stream<int32_t> fifo;

fifo.write(1);      // push
fifo << 1;          // push, equivalent

a = fifo.read();    // pop
fifo >> a;          // pop, equivalent
```

&emsp;It is officially recommended to declare `hls::stream` variables with the `static` keyword. Check [UG1399-Statics](https://docs.amd.com/r/2024.1-English/ug1399-vitis-hls/Statics) for the rationale.

&emsp;**NOTE**: `union` is useful when you need to reinterpret a value at the raw-bit level. It is preferred over `reinterpret_cast<>` in C++. It is particularly helpful for the following type conversion chain: `ap_axiu<>` → `ap_uint<>` → `uin32_t` → `float`.

```cpp
template <typename T1, typename T2>
union converter { T1 t1; T2 t2; };

converter<float, uint32_t> cvt;
cvt.t1 = 12345678.0f
std::cout << cvt.t1 << ", " << cvt.t2 << std::endl;
// output: 12345678.0, 1262248270
// both values share the same bit pattern in hex: 0x4b3c614e
```