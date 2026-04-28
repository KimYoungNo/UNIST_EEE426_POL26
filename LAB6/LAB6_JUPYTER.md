## LAB 6: Embedding & Optimizing Quantized Neural Network on Pynq-Z2

### Jupyter Notebook Contraints & Tips

#### Contraints

1. Do not modify the main kernel loop:
    ```python
    mnist_chunk = mnist_images[::mnist_slp.batch_size]
    benchmark = Benchmark()
    preds = list()

    for n, data_chunk in enumerate(mnist_chunk, 1):
        print(f"#{n} kernel calls...", end='\r')
        with benchmark:
            pred = mnist_slp.run(data_chunk)
        preds.extend(pred)
    ```

1. Additional data processing should be done under `MNIST_SLP.benchmark() `MNIST_SLP.run(...)` function:
    ```python
    class MNIST_SLP(Overlay):
        ...

        def run(self, data):
            # ...
            # Additional data preprocessing
            # may needed for in case of quantization
            # ...
            self.buffer.copy(data)
            self.dma(self.buffer)
            return self.buffer.pred
    ```

#### Tips

1. Runtime is automatically accumulated in the `benchmark` variable. If you want to reset the time record, call the `reset()` method from the `benchmark` variable.

1. The total runtime is calculated by the following equation:

    $$
    \text{total runtime} = \text{num of kernel calls} \times \text{elapsed time per calls}
    $$

    Therefore, to reduce the total runtime, either **(1) reducing the number of kernel calls** or **(2) increasing the kernel throughput** are valid approaches. Both methods require well-optimized HLS design.

1. The `MNIST_DATASET_*.npy` files are uploaded on the blackboard discussion.