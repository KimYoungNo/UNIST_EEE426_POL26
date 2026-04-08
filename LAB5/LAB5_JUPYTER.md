## LAB 5: Vitis HLS - General Matrix Multiplication

### Jupyter Notebook Snippets

&emsp;Basic modules import, class definition:

```python
import numpy as np
from pynq import Overlay, allocate

class Buffer:
    def __init__(self, A, B, dtype):
        C = A @ B
        self.A = allocate(shape=A.shape, dtype=dtype)
        self.B = allocate(shape=B.shape, dtype=dtype)
        self.C = allocate(shape=C.shape, dtype=dtype)
        
        np.copyto(self.A, A)
        np.copyto(self.B, B)
        
class DMA:
    def __init__(self, ip):
        self.A = ip.axi_dma_0.sendchannel
        self.B = ip.axi_dma_1.sendchannel
        self.C = ip.axi_dma_2.recvchannel
        
    def __call__(self, buffer):
        self.A.transfer(buffer.A)
        self.B.transfer(buffer.B)
        self.C.transfer(buffer.C)
        
        self.A.wait()
        self.B.wait()
        self.C.wait()
```

&emsp;Our `GEMM` class, inherited from `Overlay`:
```python
class GEMM(Overlay):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.ip = self.gemm_0
        self.reg = self.ip.register_map
        self.buffer = None
        self.dma = DMA(self)
        
    def __bool__(self):
        return not self.reg.CTRL.AP_DONE
        
    def allocate(self, A, B):
        self.buffer = Buffer(A, B, np.float32, self.T)
        
    def __call__(self, A, B):
        M, K = A.shape
        _, N = B.shape
        
        # implement your own
```

&emsp;Example routine:
```python
M, N, K = 128, 128, 64
A = (np.arange(M*K, dtype=np.float32) * 1e-1).reshape(M, K)
B = (np.arange(K*N, dtype=np.float32) * 1e-2).reshape(K, N)
A @ B
```

&emsp;Expected output:
```
array([[  10924.033,   10926.048,   10928.063, ...,   11176.034,
          11178.047,   11180.063],
       [  27439.105,   27445.219,   27451.33 , ...,   28203.105,
          28209.22 ,   28215.33 ],
       [  43954.17 ,   43964.387,   43974.582, ...,   45230.17 ,
          45240.383,   45250.586],
       ...,
       [2075308.   , 2075821.9  , 2076335.8  , ..., 2139560.   ,
        2140073.8  , 2140587.8  ],
       [2091823.4  , 2092341.5  , 2092859.6  , ..., 2156587.5  ,
        2157105.5  , 2157623.5  ],
       [2108338.2  , 2108860.2  , 2109382.8  , ..., 2173614.2  ,
        2174136.5  , 2174658.8  ]], dtype=float32)
```

&emsp;Running example:
```python
raw_gemm = GEMM("lab5_raw_gemm.bit")
raw_gemm.allocate(A, B)
raw_gemm(A, B)
```

&emsp;Expected output:
```
PynqBuffer([[  10924.033,   10926.048,   10928.063, ...,   11176.034,
               11178.047,   11180.063],
            [  27439.105,   27445.219,   27451.33 , ...,   28203.105,
               28209.22 ,   28215.33 ],
            [  43954.17 ,   43964.387,   43974.582, ...,   45230.17 ,
               45240.383,   45250.586],
            ...,
            [2075308.   , 2075821.9  , 2076335.8  , ..., 2139560.   ,
             2140073.8  , 2140587.8  ],
            [2091823.4  , 2092341.5  , 2092859.6  , ..., 2156587.5  ,
             2157105.5  , 2157623.5  ],
            [2108338.2  , 2108860.2  , 2109382.8  , ..., 2173614.2  ,
             2174136.5  , 2174658.8  ]], dtype=float32)
```


&emsp;TA's benchmark result: 

+ Unoptimized `GEMM`:  

    *`In [12]:`*
    ```python
    %%timeit -n 10 -r 10
    raw_gemm(A, B)
    ```

    *`Out [12]:`*
    ```
    66 ms ± 54.5 µs per loop (mean ± std. dev. of 10 runs, 10 loops each)
    ```

    *Estimated Resource Usage:*  
    
    | Resource | Utilization(%) |
    | :-- | :-- |
    | BRAM_18K | 22 |
    | DSP | 5 |
    | FF | 1 |
    | LUT | 5 |
    | URAM | 0 |

    *Actual Resource Usage:*

    | Resource | Utilization(%) |
    | :-- | :-- |
    | LUT | 8.89 |
    | LUTRAM | 1.60 |
    | FF | 6.24 |
    | BRAM | 25.00 |
    | DSP | 5.91 |
    | BUFG | 3.13 |

+ Optimized `GEMM`:  

    *`In [30]:`*
    ```python
    %%timeit -n 10 -r 10
    optim_gemm(A, B)
    ```

    *`Out [30]:`*
    ```
    22.6 ms ± 60.2 µs per loop (mean ± std. dev. of 10 runs, 10 loops each)
    ```

    *Estimated Resource Usage:*

    | Resource | Utilization(%) |
    | :-- | :-- |
    | BRAM_18K | 12 |
    | DSP | 8 |
    | FF | 5 |
    | LUT | 16 |
    | URAM | 0 |

    *Actual Resource Usage:*

    | Resource | Utilization(%) |
    | :-- | :-- |
    | LUT | 13.07 |
    | LUTRAM | 1.65 |
    | FF | 8.06 |
    | BRAM | 8.21 |
    | DSP | 8.64 |
    | BUFG | 3.13 |