## LAB 2: Vitis HLS - Scalar Add

### Objectives
&emsp;Vivado is a powerful design suite developed by Xilinx for FPGA development, providing an integrated environment for designing, simulating, and synthesizing IP blocks. This lab will teach you how to create a scalar addition kernel using Vivado HLS and integrate it into a complete FPGA design.
The Pynq-Z2 board allows users to interface with programmable logic through Python, simplifying hardware development and testing. Instead of manually writing HDL, you will use high-level C++ descriptions to generate custom IP and interact with the FPGA via Jupyter Notebook. This workflow enables efficient prototyping and enhances your understanding of FPGA design principles.

&emsp;By completing this lab, you will learn how to:

+ Develop a Vivado HLS project for a **scalar addition kernel**.  
+ Implement a testbench and verify functionality using **C Simulation**.  
+ Perform **C Synthesis** to generate RTL and run **CoSimulation**.  
+ Package and export the generated IP to Vivado.  
+ Integrate the custom IP into a hardware design.  
+ Generate the `.bit` and `.hwh` files and transfer them to Jupyter Notebook.  
+ Test the design on the Pynq-Z2 board using Python.  

&emsp;For future labs, it is recommended that you practice integrating RTL (or HLS) designs with Python interfaces to streamline your FPGA development process.

</br>

---

### Materials

&emsp;For this lab, you will need following materials:

+ A computer with Vitis HLS 2024.1 and Vivado 2024.1 installed   
+ Pynq-Z2 FPGA board  
+ Jupyter Notebook for testing and interfacing with the FPGA  

</br>

---

### Procedure

1. Create the following files in Vitis HLS.  
&nbsp;┖ &nbsp;[*adder_ip.cpp*](./hls_sources/adder_ip.cpp)  
&nbsp;┖ &nbsp;[*adder_ip.h*](./hls_sources/adder_ip.h)  
&nbsp;┖ &nbsp;[*adder_tb.cpp*](./hls_sources/adder_tb.cpp)  
	
1. Run simulations.  
	- Perform **C Simulation** to verify functionality.  
	- Perform **C Synthesis** to generate RTL.  
	- Perform **Cosimulation** to validate the design.  

	> Check [LAB2_HLS.md](./LAB2_HLS.md) for more details

1. Export the IP to Vivado.   
	- Package the synthesized IP in Vitis HLS.  
	- Import the IP into Vivado.  

1. Integrate with processing system.  
	- Add the custom IP to the block design.  
	- Connect it to the **Processing System** (PS) using **AXI Interconnect**.  

1. Generate a bitstream and export files.  
	- Generate *.bit* and *.hwh* files.   
	- Transfer these files to the Jupyter Notebook environment.  

	> Check [LAB2_VIVADO.md](./LAB2_VIVADO.md) for more details

1. Test the files on the Pynq board.  
	- Load the bitstream on Overlay.  
	- Write Python code to communicate with the FPGA and test the adder IP.

	> Check [LAB2_JUPYTER.md](./LAB2_JUPYTER.md) for more details
	
</br>

---

### Report

&emsp;Each group will implement a **Greatest Common Divisor IP** in Vitis HLS and verify its functional correctness on Jupyter Notebook. Students should also implement a custom IP driver (Overlay class).

&emsp;The report should include the following:

- A top-level block diagram of your design.

#### Part 1:

1. Describe a significant difference between the IP drivers (`.ipynb` script) of **ADDER** and **GCD**.  

1. What makes the difference? Explain it with a citation from [Vitis HLS Documentation](https://docs.amd.com/r/2024.1-English/ug1399-vitis-hls). The specific sections listed below may be useful.

</br>

---

### Assignment

&emsp;Please submit your work on Blackboard including:  

1. A compressed zip file containing:  
	+ HLS source files (*.cpp*, *.h*, etc.)
	+ C-simulation, C-Synthesis, Co-Simulation report files (*.rpt*, *.log*, etc.)
	+ an exported GCD IP zip file

1. Another compressed zip file containing:  
	+ a bitstream *(.bit)* file  
	+ a hardware handoff *(.hwh)* file  
	+ a Jupyter Notebook *(.ipynb)* file  
	
1. The report file in *.pdf* format

</br>

---

#### References

- [Vitis HLS Documentation](https://docs.amd.com/r/2024.1-English/ug1399-vitis-hls) &ensp; (2024.1)

	- [pragma HLS INTERFACE](https://docs.amd.com/r/2024.1-English/ug1399-vitis-hls/pragma-HLS-interface)

	- [Block-Level Control Protocols](https://docs.amd.com/r/2024.1-English/ug1399-vitis-hls/Block-Level-Control-Protocols)

	- [Port-Level Protocols for Vivado IP Flow](https://docs.amd.com/r/2024.1-English/ug1399-vitis-hls/Port-Level-Protocols-for-Vivado-IP-Flow)

	- [S_AXILITE and Port-Level Protocols](https://docs.amd.com/r/2024.1-English/ug1399-vitis-hls/S_AXILITE-and-Port-Level-Protocols)

- [Pynq Documentation](https://pynq.readthedocs.io/en/latest/)  

- [Greatest Common Divisor (GCD) Reference](https://en.wikipedia.org/wiki/Greatest_common_divisor)
