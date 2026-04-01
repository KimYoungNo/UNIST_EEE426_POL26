## LAB 4: Vitis HLS - Vector Add w. DMA

### Objectives

&emsp;Vivado HLS provides tools for designing high-performance FPGA accelerators. This lab focuses on improving vector addition using Direct Memory Access (DMA) and introduces the `hls::stream<>` class. By completing this lab, you will:

+ Implement a DMA-based version of vector addition.
+ Learn to use `hls::steram<>` for efficient data movement.
+ Modify the design to be compatible with the Pynq-Z2 board.
+ Compare the performance of the DMA version against the AXI memory-mapped version.

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

1. Study the `vadd` example from the provided references, especially the usage of `hls::stream<>`.

1. Modify the vadd implementation to be compatible with the Pynq board by defining and using `load`, `store` and `execute` functions.

1. Use the `ap_axiu` type (defined in `"ap_axi_sdata.h"`) for implementing AXI streaming interfaces.

1. Follow the standard flow:
    1. Run C Simulation, C Synthesis, and Cosimulation in Vitis HLS.  
    1. Export the IP and integrate it into Vivado.  
    1. Generate the bitstream and `.hwh` files.  
    1. Transfer the files to the Pynq board and validate using Python in Jupyter Notebook.  

</br>

---

### Report

&emsp;The report should include the following:

- A **top-level block diagram** of your design.

- An analysis of the **Schedule Viewer** results for each IP. 

- A **graph** comparing the runtime against vector length for each type of IP.

#### Part 1: Implement float SAXPY .w dynamic length

&emsp;Implement the float SAXPY with two different protocols:
```cpp
void saxpy_maxi(float *z, float *x, float *y,
                float  a, uint32_t size)
{
    ...
    for (...)
    {
#pragma HLS PIPELINE 
// #pragma HLS UNROLL
// DO NOT USE UNROLL, only PIPELINE
        ...
    }
}

void saxpy_axis(hls::stream<ap_axiu<...>>& z,
                hls::stream<ap_axiu<...>>& x,
                hls::stream<ap_axiu<...>>& y,
                float a, uint32_t size)
{
    ...
#pragma HLS DATAFLOW
    ...
}
```

#### Part 2: Compare the different version of SAXPY (m_axi vs axis)

1. Benchmark the runtime between MAXI and AXIS version of SAXPY.

1. Vary the vector length and plot the runtime graph.


#### Part 3: Runtime analysis for different vector sizes

1. Analyze whether the design is ***memory-bound*** or ***compute-bound***:
    - Theoretical complexity of fully pipelined streaming SAXPY should be $O(n)$.
    - Compare actual results against expected behavior. Provide an explanation based on memory vs. computation bottlenecks.


</br>

---

### Assignment

&emsp;Please submit your work on Blackboard including:  

1. A compressed zip file with separate folders for each type of IP containing:
	+ HLS source files (*.cpp*, *.h*, etc.)
	+ C-simulation, C-Synthesis, Co-Simulation report files (*.rpt*, *.log*, etc.)
	+ an exported SAXPY IP zip file

1. Another compressed zip file containing:  
	+ a bitstream *(.bit)* file  
	+ a hardware handoff *(.hwh)* file  
	+ a Jupyter Notebook *(.ipynb)* file  
	
1. The report file in *.pdf* format

</br>

---

#### References

- [Vitis Accel Examples](https://github.com/Xilinx/Vitis_Accel_Examples/blob/2024.1/hello_world/src/vadd.cpp)

- [HLS Stream Library](https://docs.amd.com/r/2024.1-English/ug1399-vitis-hls/HLS-Stream-Library)

- [AXI4 Stream Interfaces](https://docs.amd.com/r/2024.1-English/ug1399-vitis-hls/AXI4-Stream-Interfaces)