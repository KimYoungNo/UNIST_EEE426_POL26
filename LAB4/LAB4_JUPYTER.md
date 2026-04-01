## LAB 4: Vitis HLS - Vector Add w. DMA

### Jupyter Notebook Tutorial

&emsp;Basic modules import, class definition:

```python
import numpy as np
from pynq import Overlay, allocate

class Buffer:
    def __init__(self, size, dtype):
        self.size = size
        self.in1 = allocate(shape=(self.size,), dtype=dtype)
        self.in2 = allocate(shape=(self.size,), dtype=dtype)
        self.out = allocate(shape=(self.size,), dtype=dtype)

class DMA:
    def __init__(self, ip):
        self.in1 = ip.axi_dma_0.sendchannel
        self.in2 = ip.axi_dma_1.sendchannel
        self.out = ip.axi_dma_2.recvchannel
        
    def __call__(self, buffer):
        self.in1.transfer(buffer.in1)
        self.in2.transfer(buffer.in2)
        self.out.transfer(buffer.out)
        self.in1.wait()
        self.in2.wait()
        self.out.wait()
```

&emsp;Our `VADD` class, inherited from `Overlay`:
```python
class VADD(Overlay):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        # main IP
        self.ip = self.vadd_0

        # regisermap for s_axilite ports
        self.reg = self.ip.register_map

        # initiate DMA objects
        self.dma = DMA(self)

    def __call__(self, in1, in2):
        # gatekeeper in case of unquivalent vertor length
        assert len(in1) == len(in2), "Invalid operand length"
        
        # allocate new buffer
        buffer = Buffer(len(in1), np.int32)
        
        # write 'n' first (s_axilite)
        self.ip.write(self.reg.n.address, len(in1))
        
        # copy data to buffer
        np.copyto(buffer.in1, in1)
        np.copyto(buffer.in2, in2)
        
        # transfer buffer to dma and wait
        self.dma(buffer)
        
        # retrieve result
        return buffer.out
```

&emsp;With the class definition above, write python script to test the `vadd` functionality. Note that the max size of DMA buffer would be **128** if you don't change any line of the given HLS sources.