## LAB 3: Vitis HLS - Vector Add

### Jupyter Notebook Snippets
&emsp;In this lab, the IP `vadd` uses new `pragma` as follows:  
```cpp
#pragma HLS INTERFACE m_axi port=...
```

&emsp;At the same time, the port is also assigned with another protocol used in the previous lab:  
```cpp
#pragma HLS INTERFACE s_axiliate port=...
```

&emsp;The following instructions explain how `m_axi` works with `s_axilite` at both the conceptual level and the actual Python implementation level.

---

#### `m_axi` and `s_axilite`

&emsp;`m_axi` is a **data transfer protocol** which transfers ***array data*** from/to the memory subsystem, while `s_axilite` is a **control protocol** which transfers ***scalar base addresses*** from the PS. The following diagram depicts the simple address hierarchy combining the two protocols:

```cpp
┌──────────────────┐          ┌──────────────────────────┐
│    Processing    │          │       HLS IP Core        │
│      System      │          │                          │
│                  │          │                          │
│  1. Writes base  │ AXI-Lite │  ┌────────────────────┐  │
│     address ─────┼─────────►│  │ Control Registers  │  │
│    (0x1000000)   │ (slave)  │  │  - address of 'a'  │  │
│                  │          │  │  - value of 'size' │  │
│  2. Writes size  │          │  │  - start bit       │  │
│                  │          │  └────────┬───────────┘  │
│                  │          │           │ base address │
│  3. Starts the   │          │           ▼              │                ┌──────────────┐
│     kernel       │          │  ┌────────────────────┐  │  Master AXI    │  DDR Memory  │
│                  │          │  │   Compute Logic    │──┼───────────────►│  0x1000000:  │
│                  │          │  └────────────────────┘  │ R/W data from  │ [data array] │
│                  │          │                          │  0x10000000    └──────────────┘
└──────────────────┘          └──────────────────────────┘
```

&emsp;Understanding this concept makes it easier to understand ***why*** the following script is written the way it is.

---

#### Skeleton Script for `vadd_baseline` with `m_axi`

***`In[1]:`***
```python
import numpy as np
from pynq import Overlay

overlay = Overlay( "<YOUR_BITSTREAM_FILENAME_IN_STR>" )
```

***`In[2]:`***
```python
class Buffer:
    # implement your own Buffer class
    ...

class VADD:
    def __init__(self, overlay, name, size):
        self.ip = getattr(overlay, f"vadd_{name}_0")
        self.reg = self.ip.register_map
        self.buf = Buffer(size, np.int32)

    def __call__(self, a, b):
        np.copyto(self.buf.a, a)
        np.copyto(self.buf.b, b)

        # some signal writing for satisfying s_axilite protocol
        ...

        # since m_axi protocol receives a pointer, it is implemented
        # to expose begin/end pointer in the register_map
        # 
        # the m_axi port of the HLS-generated IP
        # follows the name convention:
        #
        # register_map.<port name>_1 == begin pointer
        # register_map.<port name>_2 == end pointer
        # 
        # we only use the begin pointer and naively assume that the buffer size
        # does not exceed the length between the pointers
        self.reg.a_1 = self.buf.a.device_address
        self.reg.b_1 = self.buf.b.device_address
        self.reg.c_1 = self.buf.c.device_address

        # again, s_axilite control signal writing
        ...

        return self.buf.c
```

***`In[3]:`***
```python
vadd_baseline = VADD(overlay, 'baseline', size=16)
```

***`In[4]:`***
```python
a = np.array([1*n for n in range(16)], dtype=np.int32)
b = np.array([2*n for n in range(16)], dtype=np.int32)

print(a, '+', b, sep='\n', end='\n▼\n')
print(vadd_baseline(a, b))
```

Expected output:  

***`Out[4]:`***
```python
[ 0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15]
+
[ 0  2  4  6  8 10 12 14 16 18 20 22 24 26 28 30]
▼
[ 0  3  6  9 12 15 18 21 24 27 30 33 36 39 42 45]
```

&emsp;Based on the skeleton script, write down the complete script that tests and benchmarks all types of `vadd`s.