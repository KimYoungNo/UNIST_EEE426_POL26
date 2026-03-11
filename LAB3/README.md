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

</br>

---

### Report

</br>

---

### Assignment

</br>

---

#### References