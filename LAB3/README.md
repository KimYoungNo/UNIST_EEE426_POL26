## LAB 3: Vitis HLS - Vector Add

### Objectives

&emsp;Vitis HLS provides powerful optimizations through HLS pragmas, allowing you to enhance performance by controlling loop execution and data movement. This lab will introduce you to three key optimization techniques:

+ `UNROLL` : expands loops to increase parallel execution
+ `PIPELINE` : reduces latency by overlapping computation stages
+ `DATAFLOW` : enables task-level parallelism by breaking dependencies between loops

&emsp;The Pynq-Z2 board allows you to integrate high-level synthesis (HLS) with Python, enabling efficient FPGA prototyping. Instead of manually optimizing RTL code, you will use HLS pragmas to improve the execution speed of a vector addition operation.

&emsp;By completing this lab, you will learn how to:

+ Implement a **vector addition kernel** in Vitis HLS.
+ Experiment with **HLS pragmas** to optimize execution.
+ Compare execution times before and after applying loop transformations.
+ Export the generated IP to Vivado and integrate it with the Processing System (PS).
+ Generate the `.bit` and `.hwh` files and transfer them to Jupyter Notebook.
+ Test the design on the Pynq-Z2 board using Python.

&emsp;For future labs, it is recommended that you continue exploring loop optimizations and memory access strategies to further enhance FPGA performance.


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

1. Create the following files in Vitis HLS.  
&nbsp;┖ &nbsp;[*vadd_ip.cpp*](./hls_sources/vadd_ip.cpp)  
&nbsp;┖ &nbsp;[*vadd_ip.h*](./hls_sources/vadd_ip.h)  
&nbsp;┖ &nbsp;[*vadd_tb.cpp*](./hls_sources/vadd_tb.cpp)  

1. Run Simulations and Synthesis.
    - Run **C Simulation** to verify functional correctness.
    - Try different **HLS pragma** (`PIPELINE`, `UNROLL`, `DARAFLOW`) and observe their impact.
    - Perform **C Synthesis** and analyze the **latency**, **resource utilization** and **performace** comparing removing and applying the optimizations.

    > Check [LAB3_HLS.md](./LAB3_HLS.md) for further information.

1. Integrate the IP into Vivado.
    - Open **Vivado** and create a new block design.
    - Add the IP repository and place the vector addition IP into the design.
    - Complete the design.
    - Generate the bitstream and backup `.bit` and `.hwh` files.

    > Check [LAB3_VIVADO.md](./LAB3_VIVADO.md) for further information.

1. Test the Design on the Pynq-Z2 Board.
    - Upload `.bit` and `.hwh` file on the Jupyter Notebook.
    - Write a Python script to interface with the Pynq-Z2 and test vector addition.
    - Compare execution times removing vs. applying **HLS pragma**.

    > Check [LAB3_JUPYTER.md](./LAB3_JUPYTER.md) for further information.

</br>

---

### Report

&emsp;Each group will implement **two IPs** for the SAXPY function:  
```cpp
void saxpy(float *z, float *x, float *y, float a)
{
    // z[i] = a * x[i] + y[i];
    ...
}
```

- One IP should use `#pragma HLS PIPELINE` without `#pragma HLS UNROLL`.

- The other should use `#pragma HLS UNROLL` without `#pragma HLS PIPELINE`.

&emsp;The report should include the following:

- A **top-level block diagram** of your design.

- An analysis of the **Schedule Viewer** results for each IP. 

- A **graph** comparing the runtime against vector length for each type of IP.

#### Part 1:

1. In the Vitis HLS synthesis report, you can find the **latency** of your IP in cycles. Does this value match the actual runtime in Python? If not, why?

#### Part 2:

1. **Benchmark** and **compare the runtime** of the two IPs for **at least three** different vector lengths. Which one performs better?

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

- [Vitis HLS Documentation](https://docs.amd.com/r/2024.1-English/ug1399-vitis-hls) &ensp; (2024.1)

    - [pragma HLS PIPELINE](https://docs.amd.com/r/2024.1-English/ug1399-vitis-hls/pragma-HLS-pipeline)

    - [pragma HLS UNROLL](https://docs.amd.com/r/2024.1-English/ug1399-vitis-hls/pragma-HLS-unroll)

    - [pragma HLS DATAFLOW](https://docs.amd.com/r/2024.1-English/ug1399-vitis-hls/pragma-HLS-dataflow)