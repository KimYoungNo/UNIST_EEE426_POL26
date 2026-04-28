## LAB 6: Embedding & Optimizing Quantized Neural Network on Pynq-Z2

### Vitis HLS Tips

1. The trained weights will be embedded on the Pynq Z2. [LAB6_WeightEmbed.ipynb](./train_sources/LAB6_WeightEmbed.ipynb) provides the weight embedding function. [weights.h](./hls_sources/weights.h) shows the example of weights data in `float`.  
    > After quantization, the notebook file may need modification.

1. For the testbench, only a few images will be hardcoded as a header file. However, they ***WILL NOT BE EMBEDDED*** in the final sythesized RTL&mdash;they are used for test purposes only. [LAB6_ImageEmbed.ipynb](./train_sources/LAB6_ImageEmbed.ipynb) provides the function. [images.h](./hls_sources/images.h) shows the example of hardcoded image data.  

    > After quantization, you may increase the number of image files to be hardcoded for the testbench for simulating large-scale image processing.