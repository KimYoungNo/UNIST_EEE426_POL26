## LAB 1: Pynq-Z2 board w. FFT example

### Objectives

&emsp;Vivado is a powerful design suite developed by Xilinx for FPGA development, offering a comprehensive environment for block-level IP design, simulation, and synthesis. This lab will teach you how to use Vivado alongside Jupyter Notebook to program the Pynq-Z2 FPGA board, using a Fast Fourier Transform (FFT) example. The Pynq-Z2 board allows users to leverage programmable logic with Python, making hardware design more accessible and flexible. Instead of manually writing HDL for every task, you can interact with the FPGA through high-level Python commands in Jupyter Notebook. This combination simplifies testing and visualization, helping you better understand FPGA concepts and DSP algorithms like FFT. For future labs, it is highly recommended that you practice integrating RTL (or HLS) design with Python interfaces to streamline your workflow and enhance your FPGA programming skills.

</br>

---

### Materials

&emsp;For this lab, you will need a computer with Xilinx Vivado 2024.1 installed. You can download it from the Xilinx website: [Vivado Design Suite](https://www.xilinx.com/support/download/index.html/content/xilinx/en/downloadNav/vivado-design-tools/2024-1.html). Installation guide and setup instruction is located in this repository's main [README](../README.md). The Pynq-Z2 FPGA boards will be distributed in class, with one board assigned to each group. You will also use Jupyter Notebook to interface with the FPGA, allowing you to program and test your designs using Python. You can access Jupyter Notebook documentation here: [Jupyter Documentation](https://docs.jupyter.org/en/latest/). Be sure to follow the lab instructions closely.

</br>

---

### Procedure

1. Generate a **bitstream** for the **FFT** design.

1. Write a **Python script** to upload and execute the bitstream within the Jupyter Notebook.

1. Run the FFT on the Pynq-Z2 and compare the runtime between **NumPy FFT vs. Pynq FFT**.
	
</br>

---

### Report

&emsp;The report should includes following:

- A top-level block diagram of your design.
	
- A graph comparing the runtime against array size for both NumPy vs. Pynq.
	
- Justification of the FFT output using a function with a comparable answer (e.g., comparing with NumPy's FFT result), in case of accomplish **Part 3**.

#### Part 1:

&emsp;a. Make a **plot of the runtime comparison** between HW(pynq) vs. SW(numpy).  
&emsp;b. Make at least **6 datapoints**.  
&emsp;c. You can use matplotlib by default.  
	
#### Part 2:

&emsp;a. The time complexity of FFT is $O(n\ \log\ n)$. Does the HW or SW runtime seems to be $O(n\ \log\ n)$?  
&emsp;b. Is the HW runtime always faster? Explain **when** and **why** HW is faster.
	
#### Part 3 (optional):

&emsp;a. It is your homework to read the output data correctly. Step d~e is an example to test the correctness of the FFT output. You may think of other methods/test cases to verify the FFT HW.  
&emsp;b. The 32 bit output is concatenation of imaginary and real part, which are both fixed point signed 16-bit.  
&emsp;c. The scale factor is the same as the maximum transformation length.  
&emsp; ***NOTE**: if you change the max. length, you should change the configuration by your own. STRONGLY NOT RECOMMENDED.*  
&emsp;d. Make a dummy signal of two or three sinusoidal waves interferenced.  
&emsp;e. After reading the values as complex numbers properly, make a plot of the absolute values.

</br>

---

### Assignment

&emsp;Please submit your work on Blackboard including:  

1. A compressed zip file containing:  
	+ a bitstream *(.bit)* file  
	+ a hardware handoff *(.hwh)* file  
	+ a Jupyter Notebook *(.ipynb)* file  
	
1. The report file in *.pdf* format

</br>

---

#### References

- [FFT LogiCORE IP](https://docs.amd.com/r/en-US/pg109-xfft) &ensp; (PG109, v9.1)
