## LAB 2: Vitis HLS - Scalar Add

### Vivado Tutorial

1. Open Vivado and create a project as done in [LAB 1](../LAB1/LAB1_VIVADO.md). Press ***Settings*** on the toolbar.

    ![OPEN_VIVADO](./images/2-10-1.png)

    ---

1. Go to **IP** &ndash; **Repository**, press the '**+**' button to add new path as an IP repository.

    ![IP_ADD_1](./images/2-10-2.png)

    ---

1. Select the directory where you exported your `adder` IP and press the ***Select*** button.

    > In this tutorial, the HLS project folder is selected, as recommended in [LAB2_HLS.md](./LAB2_HLS.md).

    ![IP_ADD_2](./images/2-10-3.png)

    Expected screen and result:

    ![IP_ADD_3](./images/2-10-4.png)

    ![IP_ADD_4](./images/2-10-5.png)

    ---

1. Create a block design and add the following IPs:  
    - one **ZYNQ7 Processing System**
    - one **AXI Interconnect**
    - one **Adder** (type 'adder' in the search browser)

    ![BLOCK_DESIGN](./images/2-11-1.png)

    ---

1. Configure **AXI Interconnect** as follows:
    - \# of Slave Interfaces = 1  
    - \# of Master Interfaces = 1

    ![CONF_AXI_INTER](./images/2-11-2.png)

    ---

1. Click ***Run Block Automation*** and click the ***Next >*** button.

    ![RUN_BLOCK_AUTOMATION](./images/2-11-3.png)

    ---

1. Connect all IPs as suggested:  
    | *axi_interconnect_0* | OTHER IPs |
    | --: | :-- |
    | `S##_AXI` | `M_AXI_GP0` : processing_system7_0 |
    | `M##_AXI` | `s_axi_control` : adder_0 |

    ![CONN_IPS](./images/2-11-4.png)

    ---

1. Click ***Run Connection Automation***, check all possible candidates, and click ***OK***.

    ![CONN_AUTOMATION](./images/2-11-5.png)

    Expected result:

    ![BLOCK_DESIGN](./images/2-11-6.png)

    ---

1. As done in [LAB 1](../LAB1/LAB1_VIVADO.md), generate the bitstream file and backup the `.bit` and `.hwh` files.
