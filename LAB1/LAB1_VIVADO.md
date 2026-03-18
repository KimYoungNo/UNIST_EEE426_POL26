## LAB 1: Pynq-Z2 board w. FFT example

### Vivado Tutorial

1. Open Vivado and click ***Create Project*** in the ***Quick Start***.

    ![CREATE_PROJECT](./images/1-1.png)

    ---

1. Press ***Next >*** button.

    ![NEXT](./images/1-2.png)

    ---

1. Set ***Project name*** and ***Project location***.

    > **CAUTION**  
    > &emsp;Do not include **Any Non-English** chracter in the ***Project name*** and ***Project location*** !

    ![NEW_PROJECT](./images/1-3.png)

    ---

1. Let option as ***RTL Project*** and click ***Next >***.

    ![PROJECT_TYPE](./images/1-4.png)

    ---

1. Let additional source empty and click ***Next >***.

    ![ADD_SOURCES](./images/1-5.png)

    ---

1. Let constraints empty and click ***Next >***.

    ![ADD_CONSTRAINT](./images/1-6.png)

    ---

1. Select **Boards** &ndash; **pynq-z2** and click ***Next >***.

    > **ATTENTION**  
    > &emsp;If **pynq-z2** is not on the list, try:  
    > &emsp;&ensp; 1. press ***Refresh*** on the left-bottom.  
    > &emsp;&ensp; 2. if still not updated, check your internet connection and re-open Vivado.  
    > &emsp;&ensp; 3. follow the instruction from the start.

    ![DEFAULT_PART](./images/1-7.png)

    ---

1. Click ***Next >***, then you can see Vivado project manager.

    ![PROJECT_SUMMARY](./images/1-8.png)

    ![FIRST_SCREEN](./images/1-9.png)

    ---

1. Click ***Create Block Design*** under **IP INTEGRATOR** on the Flow Navigator, then enter ***Design name***.

    ![CREATE_BLOCK_DESIGN](./images/1-10.png)

    ---

1. On the toolbar in the ***Diagram*** section, press **<font size=5px>+</font>** to add IP.

    ![ADD_IP](./images/1-11.png)

    ![IP_BROWSER_1](./images/1-12.png)

    ---

1. In the pop-up window, search and add **ZYNQ7 Processing System**.

    ![IP_BROWSER_2](./images/1-13.png)

    ![IP_BROWSER_3](./images/1-14.png)

    ---

1. Likewise, add one **Fast Fourier Transform**, three **AXI Direct Memory Access**, and two **AXI Interconnect**.

    ![IP_BROWSER_4](./images/1-15-1.png)

    ![IP_BROWSER_5](./images/1-15-2.png)

    ![IP_BROWSER_6](./images/1-15-3.png)

    ![IP_BROWSER_7](./images/1-16.png)

    ---

1. Configure DMA named ***axi_dma_0*** as next:
    - Disable ***Scatter Gather Engine***    
    - Buffer Length Register Width = 26  
    - Disable ***Write Channel***  

    ![AXI_DMA_0](./images/1-17-1.png)

    ---

1. Configure DMA named ***axi_dma_1*** as next:
    - Disable ***Scatter Gather Engine***   
    - Disable ***Write Channel***  

    ![AXI_DMA_1](./images/1-17-2.png)

    ---

1. Configure DMA named ***axi_dma_2*** as next:
    - Disable ***Scatter Gather Engine***   
    - Buffer Length Register Width = 26  
    - Disable ***Read Channel***  

    ![AXI_DMA_2](./images/1-17-3.png)

    ---

1. Configure AXI Interconnect named ***axi_interconnect_0*** as next:
    - \# of Slave Interfaces = 1  
    - \# of Master Interfaces = 3

    ![AXI_INTERCCONNECT_0](./images/1-18-1.png)

    ---

1. Configure AXI Interconnect named ***axi_interconnect_1*** as next:
    - \# of Slave Interfaces = 3  
    - \# of Master Interfaces = 1

    ![AXI_INTERCCONNECT_1](./images/1-18-2.png)

    ---

1. Configure FFT as next:
    - Transform Length = 65536  
    - Architecture Choice = Pipelined, Streaming I/O
    - Enable ***Run Time Configurable Transform Length***

    ![FFT_CONF](./images/1-19.png)

    ---

1. After configure all IPs, click ***Run Block Automation*** in the green suggestion box and click ***Next >*** button.

    ![BLOCK_AUTOMATION](./images/1-21.png)

    ![AFTER_BLOCK_AUTOMATION](./images/1-22.png)

    ---

1. Double click ZYNQ7 Processing System named ***processing_system7_0***, and go to ***PS-PL Configuration*** on the left page navigator. Enable ***S AXI HP0 interface*** under ***HP Slave AXI Interface***.

    ![S_AXI_HP0](./images/1-23.png)

    ---

1. After click ***OK***, critical messages may pop up. Ignore it and click ***OK*** button.

    ![CRITICAL_MESSAGES](./images/1-24.png)

    ---

1. Connect all IPs as suggested:  
    | *axi_dma_0* | OTHER IPs |
    | --: | :-- |
    | `S_AXI_LITE` | `M##_AXI` : axi_interconnect_0 |
    | `M_AXI_MM2S` | `S##_AXI` : axi_interconnect_1 |
    | `M_AXIS_MM2S` | `S_AXIS_DATA` : xfft_0 |

    | *axi_dma_1* | OTHER IPs |
    | --: | :-- |
    | `S_AXI_LITE` | `M##_AXI` : axi_interconnect_0 |
    | `M_AXI_MM2S` | `S##_AXI` : axi_interconnect_1 |
    | `M_AXIS_MM2S` | `S_AXIS_CONFIG` : xfft_0 |

    | *axi_dma_2* | OTHER IPs |
    | --: | :-- |
    | `S_AXI_LITE` | `M##_AXI` : axi_interconnect_0 |
    | `M_AXI_MM2S` | `S##_AXI` : axi_interconnect_1 |
    | `S_AXIS_S2MM` | `M_AXIS_DATA` : xfft_0 |

    | *processing_system7_0* | OTHER IPs |
    | --: | :-- |
    | `M_AXI_GP0` | `S##_AXI` : axi_interconnect_0 |
    | `S_AXI_HP0` | `M##_AXI` : axi_interconnect_1 |

    ![BEFORE_CONNECT](./images/1-25.png)

    ![AFTER_CONNECT](./images/1-26.png)

    ---

1. Click ***Run Connection Automation*** in the green suggestion box, check all possible candidates, and click ***OK*** button.

    ![CONNECTION_AUTOMATION](./images/1-27.png)

    ---

1. In the **BLOCK DESIGN**, change the tab into **Address Editor**

    ![BLOCK_DESIGN](./images/1-28.png)

    ![ADDR_EDITOR](./images/1-29.png)

    ---

1. Click ***Assign All*** and press ***OK*** button.

    ![ASSIGN_ALL](./images/1-30.png)

    ![AUTO_ASSIGN_COMPLETE](./images/1-31.png)

    ---

1. Back to the **Diagram** tab, push ***Validate Design (F6)*** and click ***OK*** button.

    ![VALIDATE_DESIGN](./images/1-32.png)

    ![VALIDATE_DESIGN_OK](./images/1-33.png)

    ---

1. At the top-left browser, select the ***Sources*** tab, right click the borad design file (*.bd), and choose **Create HDL Wrapper**.

    ![HDL_WRAPPER_1](./images/1-34.png)

    ![HDL_WRAPPER_2](./images/1-35.png)

    ---

1. Let the option as ***Let Vivado manage wrapper and auto-update***, and click ***OK*** button.

    ![HDL_WRAPPER_3](./images/1-36.png)

    ![HDL_WRAPPER_4](./images/1-37.png)

    ---

1. On the left flow navigator, click ***Run Synthesis***, maximize the \# of jobs, and click ***OK***. You can check whether the synthesis is ongoing on the top-right status bar.

    ![RUN_SYNTHESIS_1](./images/1-38.png)

    ![RUN_SYNTHESIS_2](./images/1-39.png)

    ![RUN_SYNTHESIS_3](./images/1-40-1.png)

    ![RUN_SYNTHESIS_4](./images/1-40-2.png)

    ---

1. After **Synthesis** is done, choose **Run Implementation** and click ***OK*** with same **Launch Runs** setup.

    ![RUN_IMPLEMENTATION](./images/1-41.png)

    ![LAUNCH_RUNS_1](./images/1-42.png)

    ---

1. After **Implementation** is done, choose **Generate Bitstream** and click ***OK*** with same **Launch Runs** setup.

    ![GEN_BITSTREAM](./images/1-43.png)

    ![LAUNCH_RUNS_2](./images/1-44.png)

    ---

1. Download **[copy_bit+hwh.bat](../copy_bit+hwh.bat)** and place the script in the top level Vivado project folder (same level with `.xpr` file).

    ![COPY_BIT_HWH](./images/1-45.png)

    ---

1. Double click the script to execute, and backup the `.bit` and `.hwh` files for Jupyter Notebook use.

    ![BATCH_SCRIPT](./images/1-46.png)

    ![BIT_HWH_COPIED](./images/1-47.png)

    ---

1. After backup `.bit` and `.hwh` files, follow [LAB1_JUPYTER.md](./LAB1_JUPYTER.md) to implement IP driver.