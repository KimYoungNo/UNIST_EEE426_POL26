## LAB 6: Embedding & Optimizing Quantized Neural Network on Pynq-Z2

### Objectives

&emsp;For the acceleration and down-sizing of a neural network, quantization is often used. Although `fp32` is widely used for representing real numbers (ℝ), it is considered a large and inefficient type compared to other data types (e.g., `fp16`, `bf16`, `fp8`, `int8`, `fixed point`, etc.).  
&emsp;In this lab, we will emulate quantized numbers and perform **QAT** (Quantization-Aware Training) to increase inference accuracy on the **SLP** (Single-Layer Perceptron) neural network for the **MNIST** dataset.

+ Implement a hardware `mnist_slp` kernel.
+ Perform QAT and embed quantized weights to implement an optimized inference hardware.
+ Compare the performance and resource usage between the unquantized and quantized `mnist_slp` kernels.

</br>

---

### Materials

&emsp;For this lab, you will need:

+ A computer with Vitis HLS 2024.1 and Vivado 2024.1 installed   
+ Pynq-Z2 FPGA board  
+ Jupyter Notebook for testing and interfacing with the FPGA  

</br>

---

### Procedure

1. Study the `mnist_slp` example from the provided [train_sources](./train_sources), [inference_sources](./inference_sources) and [hls sources](./hls_sources), throughout the entire design process.

1. Quantize the SLP model by emulating **fixed point data type**, customizing `nn.Linear` and `torch.autograd.Function` classes.
    - Implement a class or function that rounds `float` values which of range is $[-1, 1]$ into `ap_fixed<>` type.
    - Implement a class inherited from `torch.autograd.Function` for applying `ap_fixed<>` emulation on forward and backward.
    - Implement a class inherit from `nn.Linear` applying `ap_fixed<>` emulation on its weights and bias.

    > Check [LAB6_JUPYTER.md](./LAB6_JUPYTER.md) for more contraints and tips.

1. Implement quantized version of `mnist_slp` kernel in HLS.  
    
    > Check [LAB6_HLS.md](./LAB6_HLS.md) for more tips.

1. Follow the standard flow:
    1. Run C Simulation, C Synthesis, and Cosimulation in Vitis HLS.  
    1. Export the IP and integrate it into Vivado.  
    1. Generate the bitstream and `.hwh` files.  
    1. Transfer the files to the Pynq board and validate using Python in Jupyter Notebook.  

    > Check [LAB6_VIVADO.md](./LAB6_VIVADO.md) for more tips.

</br>

---

### Report

&emsp;The report should include the following:

- **Screenshots** indicating actual resource usage.

- A **benchmark result** comparing the runtime for each type of IP.

#### Part 1. Implement `mnist_slp` floating point version kernel

&emsp;Generate a bitstream of `mnist_slp` ip working with the given [driver](./inference_sources/LAB6_DESIGN.ipynb).

#### Part 2. Quantize & Train MNIST SLP

&emsp;Quantize and train the given MNIST SLP model in PyTorch:
```python
class MNISTSLP(nn.Module):
    def __init__(self):
        super().__init__()
        self.fc = nn.Linear(784, 10, bias=True)

    def forward(self, x):
        x = x.view(x.size(0), -1)
        x = self.fc(x)
        return x
```

1. Explain the specification of `ap_fixed<>` used. How is the specification chosen?

1. The accuracy of the given floating poing version is **92.62%** in evaluation mode. Does the quantized model's accuracy increase or decrease?

#### Part 3. Optimize `mnist_slp` fixed point version kernel

&emsp;Implement the optimized & quantized version of `mnist_slp` kernel.
```cpp
void mnist_slp(hls::stream<ap_axiu<>>& mnist_img, 
               hls::stream<ap_axiu<>>& mnist_pred);
```

#### Part 4. Benchmark & Analysis the different version of `mnist_slp` kernels

1. Resource analysis of the designs:
    - Identify which resource type is consumed the most.
    - How much of that resource type is used for each version? Provide the correspoding usage figures.

1. Performance analysis of the designs:
    - How many kernel calls are made for each version of the drivers?
    - Compare the total runtime for each kernel. How much improvement is achieved by the quantized version?

</br>

---

### Assignment

&emsp;Please submit your work on Blackboard including:  

1. A compressed zip file containing:  
	+ HLS source files (*.cpp*, *.h*, etc.) of the quantized MNIST SLP
	+ C-simulation, C-Synthesis, Co-Simulation report files (*.rpt*, *.log*, etc.) of the quantized MNIST SLP
	+ an exported quantized MNIST SLP IP zip file

1. Another compressed zip file containing:  
	+ two bitstream *(.bit)* files for each `mnist_slp`   
	+ two hardware handoff *(.hwh)* files for each `mnist_slp`  
	+ a Jupyter Notebook *(.ipynb)* file for the benchmark  
	
1. The report file in *.pdf* format

</br>

---

#### References
