## LAB 5: Vitis HLS - General Matrix Multiplication

### Objectives

&emsp;General Matrix Multiplication, commonly known as `GEMM`, is a fundamental operation in linear-algebra-related computation. This lab focuses on optimizing a `GEMM` kernel for either (1) **reduced resource usage**, or (2) **increased throughput**.

+ Implement a hardware `GEMM` kernel.
+ Learn to apply different optimization strategies.
+ Compare the performance and resource usage between the unoptimized and optimized `GEMM` kernels.

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

1. Study `gemm` example from the provided [hls sources](./hls_sources), throughout the entire design process.

1. Optimize the `gemm` to either (a) consume fewer hardware resources, or (b) execute faster.

    - For optimization (a), the optimized design must not be slower than the given unoptimized version.
    - For optimization (b), the optimized design is permitted to use more hardware resources than the given unoptimized version.

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

- **Screenshots** indicating estimated and actual resource usage.

- A **benchmark result** comparing the runtime for each type of IP.

#### Part 1. Implement GEMM

&emsp;Implement the driver of given example version of `gemm` kernel:
```cpp
void gemm(hls::stream<ap_axiu<32,4,5,5>> C,
          hls::stream<ap_axiu<32,4,5,5>> A,
          hls::stream<ap_axiu<32,4,5,5>> B,
          uint32_t M, uint32_t N, uint32_t K);
```

#### Part 2. Optimize GEMM

&emsp;Optimize the `gemm` kernel based on the unoptimized version. Modifying the top-level function signature is not permitted.

#### Part 3. Benchmark & Analysis the difference version of GEMM

1. Resource analysis of the designs:
    - **estimated** resource usage vs. **actual** resource usage
    - Check the Vitis HLS C-Synthesis report for estimated resource usage.
    - Check the Vivado implmentation report for actual resource usage.
    - What optimizations were applied to reduce resource usage? Is there any difference betwen the estimated and actual resource usage?

1. Performance analysis of the designs:
    - **estimated** total latency vs. **actual** total latency
    - What optimizations were applied to improve performance?

</br>

---

### Assignment

&emsp;Please submit your work on Blackboard including:  

1. A compressed zip file containing:  
	+ HLS source files (*.cpp*, *.h*, etc.) of optimized GEMM
	+ C-simulation, C-Synthesis, Co-Simulation report files (*.rpt*, *.log*, etc.) of optimized GEMM
	+ an exported optimized GEMM IP zip file

1. Another compressed zip file containing:  
	+ a bitstream *(.bit)* file  
	+ a hardware handoff *(.hwh)* file  
	+ a Jupyter Notebook *(.ipynb)* file  
	
1. The report file in *.pdf* format

</br>

---

#### References

- [Arbitrary Precision Data Types Library](https://docs.amd.com/r/2024.1-English/ug1399-vitis-hls/Arbitrary-Precision-Data-Types-Library)