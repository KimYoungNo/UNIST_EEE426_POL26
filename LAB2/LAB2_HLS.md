## LAB 2: Vitis HLS - Scalar Add

### Vitis HLS Tutorial

> **DISCLAIMER**  
> &emsp;Before proceeding, please go over the last step of the [installation process](../README.md#how-to-install).

1. Open Vitis HLS and click ***Create Project*** under ***Project***.  

    ![CREATE_PROJECT](./images/2-1-1.png)

    ---

1. Set ***Project name***, ***Location*** and click ***Next >*** button.

    ![PROJECT_CONF](./images/2-1-2.png)

    ---

1. Leave design files empty and click ***Next >*** button.

    ![DESIGN_FILES](./images/2-1-3.png)

    ---

1. Leave testbench files empty and click ***Next >*** button.

    ![TB_FILES](./images/2-1-4.png)

    ---

1. Press ***…*** button under **Part Selection**, search and select **xc7z020clg400-1**, press ***OK*** and ***Finish***.

    ![SOL_CONF_1](./images/2-1-5.png)

    ![SOL_CONF_2](./images/2-1-6.png)

    ---

1. After configuration is finished, you will see the screen below.

    - Download all HLS sources from [here](./hls_sources) and remember the path of the sources' directory.

    ![VITIS_HLS_FIRST](./images/2-2-1.png)

    ---

1. In the left **exploerer**, right click ***Sources*** and click ***Add Source Files***. Select `adder_ip.h` and `adder_ip.cpp` from the sources.

    - You can choose ***New Source File*** later in case of creating your own sources.

    ![ADD_SOURCES_1](./images/2-2-2.png)

    ![ADD_SOURCES_2](./images/2-2-3.png)

    ---

1. Likewise, right-click ***Test Bench*** and click ***Add Test Bench File***. Select `adder_tb.cpp`.

    ![ADD_TESTBENCH_1](./images/2-2-4.png)

    ![ADD_TESTBENCH_2](./images/2-2-5.png)

    ---

1.  After adding all sources, the screen should look like below:

    ![AFTER_ADD_ALL_SRC](./images/2-3.png)

    ---

1. Temporarily, change the `adder_ip.cpp` source as follows:

    ![TEMP_CHANGE](./images/2-4.png)

    before change:
    ```cpp
    #pragma HLS INTERFACE ap_ctrl_none port=return
    ```

    after change:
    ```cpp
    #pragma HLS INTERFACE s_axilite port=return
    ```

    ---

1. Press the green triangle on the toolbar, and select ***C Simulation***. Leave all options at their defaults and run the simulation.

    ![C_SIMULATION](./images/2-5-1.png)

    ![C_SIM_DIALOG](./images/2-5-2.png)

    Expected result:

    ![C_SIM_RESULT](./images/2-5-3.png)

    > The printed number may differ depending on your test cases.

    ---

1. To proceed with synthesis, you need to specify the **top function**. Select **Project** &ndash; **Project Settings**

    ![TOP_FUNCTION_1](./images/2-6-1.png)

    ---

1. Open the **Synthesis** tab and enter `adder` in the **Top Function** field.

    ![TOP_FUNCTION_2](./images/2-6-2.png)

    ---

1. Press the green triangle again, and select ***C Synthesis***. Verify that the selected part is `xc7z020clg400-1`.

    ![C_SYNTHESIS_1](./images/2-6-3.png)

    ![C_SYNTHESIS_2](./images/2-6-4.png)

    Expected result:

    ![C_SYNTHESIS_3](./images/2-6-5.png)

    ---

1. Press the green triangle and select ***Cosimulation***.

    ![CO_SIM_1](./images/2-7-1.png)

    ---

1. Configure the cosimulation settings as follows:
    - Dump Trace = all  
    - Enable ***Wave Debug***

    ![CO_SIM_2](./images/2-7-2.png)

    ---

1. After taking some time, Vivado will launch and RTL waveform will be displayed as below:

    ![CO_SIM_3](./images/2-7-3.png)

    ---

1. Close Vivado to complete the simulation.

    ![CO_SIM_4](./images/2-7-4.png)

    Expected output:

    ![CO_SIM_5](./images/2-7-5.png)

    ---

1. After finishing ***Cosimulation***, revert the code to `#pragma HLS INTERFACE ap_ctrl_none port=return`, and re-synthesize `adder` IP.

    ![AP_CTRL_NONE](./images/2-8.png)

    ---

1. When ***C Synthesis*** is done, press the green triangle and select ***Export RTL***.

    ![EXPORT_RTL_1](./images/2-9-1.png)

    ---

1. Specify the output location for the exported IP.

    > &emsp;You will need to remember this output location. It is recommended to set it to the same directory as the HLS project folder.

    ![EXPORT_RTL_2](./images/2-9-2.png)

    Expected output:

    ![EXPORT_RTL_3](./images/2-9-3.png)

    ---

1. After exporting, do not close Vitis HLS. You will likely need to reopen it when debugging your IP.
