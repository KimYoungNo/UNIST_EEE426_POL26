## LAB 2: Vitis HLS - Scalar Add

### Jupyter Notebook Tutorial

1. Upload the `.bit` and `.hwh` files to the Jupyter Notebook.  

1. Press ***New*** → ***Python 3 (ipykernel)*** to create a new Notebook file.

1. Enter the following script in the notebook and execute it:  

    ***`In [1]:`***  
    ```python
    from pynq import Overlay

    # We can implement our custom IP class inherited from the Overlay class

    class Adder(Overlay):
        def __init__(self, *args, **kwargs):
            super().__init__(*args, **kwargs)

            # Our HLS IP
            self.ip = self.adder_0

            # register_map has mapping information for all ports of the IP
            self.reg = self.ip.register_map
        
        def __call__(self, a, b):
            self.ip.write(self.reg.a.address, a)
            self.ip.write(self.reg.b.address, b)
            return self.ip.read(self.reg.c.address)

        # ...or the following implementation is also possible:
        """
        def __call__(self, a, b):
            self.reg.a = a
            self.reg.b = b
            return int(self.reg.c)
        """
    ```

    ***`In [2]:`***  
    ```python
    adder = Adder( "<YOUR_BITSTREAM_FILENAME_IN_STR>" )
    ```

    ***`In [3]:`***  
    ```python
    for a, b in zip(range(0, 5), range(10, 15)):
        print(f"{a} + {b} = {adder(a, b)}")
    ```

    Expected output:

    ***`Out [3]:`***  
    ```python
    0 + 10 = 10
    1 + 11 = 12
    2 + 12 = 14
    3 + 13 = 16
    4 + 14 = 18
    ```

    ---

1. Based on this tutorial, write your own driver code for the questions requested in the report.