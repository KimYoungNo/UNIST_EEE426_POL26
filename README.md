# EEE426 Labs and Project

> Spring 2026
>
> Instructor: Jongeun Lee
>
> TAs: EunSeok Jo, SeonJae Kim, YoungNo Kim

---

### Prerequisite

An **AMD website account** is required to download following software:

- Vivado 2024.1

- Vitis HLS 2024.1

Please refer to the [How to Install](#how-to-install) section for the detailed installation procedure.

</br>

---

### [LAB 1: Pynq-Z2 board w. FFT example](./LAB1)

+ date: 2026-03-11

+ description:  
&emsp;Learning and practicing Vivado design flows, which are successively accomplished in the order of: *Block Deisgn - Synthesis - Implementation - Driver*.   
&emsp;It is important to read [FFT LogiCORE IP](./LAB1/README.md) documentation to debug.

</br>

---

### [LAB 2: Vitis HLS - Scalar Add](./LAB2)

+ date: 2026-03-18

+ description:
&emsp;
	
</br>

---

### LAB 3: Vitis HLS - Vector Add

+ date: 2026-03-25

+ description:

</br>

---

### LAB 4: Vitis HLS - Vector Add w. DMA

+ date: 2026-04-01

+ description:

</br>

---

### LAB 5: Vitis HLS - Matrix Multiplication

+ date: 2026-04-08

+ description:

</br>

---

### LAB 6: Neural Network Training + Inferencing on Pynq-Z2

+ date: 2026-04-29

+ description:

</br>

---

### LAB 7: Presentation + Optimization Methods

+ date: 2026-05-06

+ description:

</br>

---

### FINAL PROJECT

+ date: TBD

</br>

---

#### How to Install

1. Check your OS is supported:
	- `Windows 10.0 22H2 64-bit` or newer
	- `Ubuntu 20.04.4` or newer
	- another OS found in this [list](https://docs.amd.com/r/2024.1-English/ug973-vivado-release-notes-install-license/Requirements-and-Setup)
	
1. Click this [link](https://www.xilinx.com/support/download/index.html/content/xilinx/en/downloadNav/vivado-design-tools/2024-1.html) and scroll down to locate **AMD Unified Installer for FPGAs & Adaptive SoCs 2024.1 [ Windows | Linux ] Self Extracting Web Installer**.
Make sure choose appropriate version for your OS.

1. Login using your AMD account.

1. Complete the required form and click the download button.

1. Execute the installer and grant the program permission to modify your system. Note that disabling your anti-virus software templorarily may save your time.
	
1. Fill out your AMD account credential and click next, ensuring that the radio button is set to **Download and Install Now**

1. Select the **Vitis** option and click next.

1. Accept all license agreements and click next.

1. Wait for the download and installation process.

1. Verify whether **Vivado 2024.1** and **Vitis HLS 2024.1** are locatable.

</br>

---

#### References

- Pynq:  

	+ [Github](https://github.com/xilinx/pynq)
	
	+ [Webpage](https://www.pynq.io/)
	
	+ [Documentation](https://pynq.readthedocs.io/en/latest/index.html)


- AMD Technical Information:  
	
	+ [Documentation Portal](https://docs.amd.com/search/all?query=Vivado)

	+ [Vivado Design Suite Documentation](https://docs.amd.com/r/2024.1-English/ug896-vivado-ip/Vivado-Design-Suite-Documentation)
	&ensp; (UG896, 2024.1)
	
	+ [Vitis High-Level Syntehsis User Guide](https://docs.amd.com/r/2024.1-English/ug1399-vitis-hls)
	&ensp; (UG1399, 2024.1)


- AMD Adaptive SoC & FPGA Support:

	- AXI Bascis:
	
		1. [Introduction to AXI](https://adaptivesupport.amd.com/s/article/1053914)
		
		1. [Simulating AXI interfaces with the AXI Verification IP (AXI VIP)](https://adaptivesupport.amd.com/s/article/1053935)
		
		1. [Master AXI4-Lite simulation with the AXI VIP](https://adaptivesupport.amd.com/s/article/1058302)
		
		1. [Using the AXI VIP as protocol checker for an AXI4 Master interface](https://adaptivesupport.amd.com/s/article/1062002)
		
		1. [Create an AXI4-Lite Sniffer IP to use in Xilinx Vivado IP Integrator](https://adaptivesupport.amd.com/s/article/1064306)
		
		1. [Introduction to AXI4-Lite in Vitis HLS](https://adaptivesupport.amd.com/s/article/1137153)
		
		1. [Connecting to the PS using AXI4-Lite and Vitis HLS](https://adaptivesupport.amd.com/s/article/1137753)
		
