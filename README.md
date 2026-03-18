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

### [LAB 1: Pynq-Z2 board w. FFT example](./LAB1) <div align="right">2026-03-11</div>

<table>
<tr>
	<td>Jupyter Notebook URL</td>
	<td><code>pynq:9090</code></td>
</tr>
<tr>
	<td>User Name</td>
	<td><code>xilinx</code></td>
</tr>
<tr>
	<td>Password</td>
	<td><code>xilinx</code></td>
</tr>
</table>

</br>

---

### [LAB 2: Vitis HLS - Scalar Add](./LAB2) <div align="right">2026-03-18</div>

<table>
<tr>
	<td>Target Device</td>
	<td><code>xc7z020-clg400-1</code></td>
</tr>
<tr>
	<td rowspan="2">HLS Interfaces</td>
	<td><code>ap_ctrl_none</code></td>
</tr>
<tr>
	<td><code>s_axilite</code></td>
</tr>
</table>

> **Warning**  
> `#pragma HLS INTERFACE ap_ctrl_none port=return` directive makes Cosimulation **unavailable**.
	
</br>

---

### [LAB 3: Vitis HLS - Vector Add](./LAB3) <div align="right">2026-03-25</div>

<table>
<tr>
	<td rowspan="2">HLS Interfaces</td>
	<td><code>m_axi</code></td>
</tr>
<tr>
	<td><code>s_axilite</code></td>
</tr>
<tr>
	<td rowspan="3">HLS Directives</td>
	<td><code>PIPELINE</code></td>
</tr>
<tr>
	<td><code>UNROLL</code></td>
</tr>
<tr>
	<td><code>DATAFLOW</code></td>
</tr>
</table>

</br>

---

### [LAB 4: Vitis HLS - Vector Add w. DMA](./LAB4) <div align="right">2026-04-01</div>

</br>

---

### [LAB 5: Vitis HLS - Matrix Multiplication](./LAB5) <div align="right">2026-04-08</div>

</br>

---

### [LAB 6: Neural Network Training + Inferencing on Pynq-Z2](./LAB6)  <div align="right">2026-04-29</div>

</br>

---

### LAB 7: Presentation + Optimization Methods  <div align="right">2026-05-06</div>

</br>

---

### FINAL PROJECT  <div align="right">TBD</div>

</br>

---

#### How to Install

1. Check your OS is supported:  
	- `Windows 10.0 22H2 64-bit` or newer
	- `Ubuntu 20.04.4` or newer
	- another OS found in this [list](https://docs.amd.com/r/2024.1-English/ug973-vivado-release-notes-install-license/Requirements-and-Setup)
	
1. Click this [link](https://www.xilinx.com/support/download/index.html/content/xilinx/en/downloadNav/vivado-design-tools/2024-1.html) and scroll down to locate  
**AMD Unified Installer for FPGAs & Adaptive SoCs 2024.1 [ Windows | Linux ] Self Extracting Web Installer**  
Make sure choose appropriate version for your OS.

1. Login using your AMD account.

1. Complete the required form and click the download button.

1. Execute the installer and grant the program permission to modify your system.  
Note that disabling anti-virus software templorarily may save your time.
	
1. Fill out your AMD account credential and click next, ensuring that the radio button is set to **Download and Install Now**

1. Select the **Vivado** option and click next.

1. Select the **Vivado ML Standard** option and click next.

1. Uncheck every option under **Devices**, except **Devices** &ndash; **Production Devices** &ndash; **SoCs** &ndash; **Zynq-7000** (to reduce download size) and click next.

1. Accept all license agreements and click next.

1. Wait for the download and installation process.

1. After download is finished:  

	- **Windows**: execute [hls_lnk_patch.bat](./hls_lnk_patch.bat) to make Vitis HLS 2024.1 shortcut compatible with the legacy environment.  

	- **Linux**: always execute `vitis_hls` with `-classic` option.

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

	+ AXI Bascis:
	
		+ [Introduction to AXI](https://adaptivesupport.amd.com/s/article/1053914)
		
		+ [Simulating AXI interfaces with the AXI Verification IP (AXI VIP)](https://adaptivesupport.amd.com/s/article/1053935)
		
		+ [Master AXI4-Lite simulation with the AXI VIP](https://adaptivesupport.amd.com/s/article/1058302)
		
		+ [Using the AXI VIP as protocol checker for an AXI4 Master interface](https://adaptivesupport.amd.com/s/article/1062002)
		
		+ [Create an AXI4-Lite Sniffer IP to use in Xilinx Vivado IP Integrator](https://adaptivesupport.amd.com/s/article/1064306)
		
		+ [Introduction to AXI4-Lite in Vitis HLS](https://adaptivesupport.amd.com/s/article/1137153)
		
		+ [Connecting to the PS using AXI4-Lite and Vitis HLS](https://adaptivesupport.amd.com/s/article/1137753)
		
